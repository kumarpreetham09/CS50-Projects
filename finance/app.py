import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session["user_id"]
    all_symbols = []
    data = []
    cash = int(db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"])
    for i in (db.execute("SELECT DISTINCT symbol FROM history WHERE user_id = ?", user_id)):
        all_symbols.append(i["symbol"])

    for symbol in all_symbols:

        price = round(float(lookup(symbol)["price"]),4)
        shares = int(db.execute("SELECT SUM(shares) AS n FROM history  WHERE user_id = ? AND symbol = ?", user_id, symbol)[0]["n"])
        total = round(float(price * shares),2)
        data.append(
            {
                "symbol": symbol.upper(),
                "shares": shares,
                "price": price,
                "total": total
            }
        )

    return render_template("index.html",all_symbols=all_symbols, data=data, cash=cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        user_id = session["user_id"]
        if symbol:
            if shares and shares.isnumeric() and int(shares) > 0:
                symbol_dict = lookup(symbol)
                if symbol_dict:
                    time = "18-07-2023"
                    price = int(symbol_dict["price"])
                    total_price = price * int(shares)
                    cash = int(db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"])
                    if cash < total_price:
                        return apology("not enough balance",400)
                    else:
                        print(cash)
                        cash = cash - total_price
                        print(cash)
                        db.execute("INSERT INTO history (user_id, symbol, price, shares, time) VALUES(?, ?, ?, ?, ?)", user_id, symbol, price, shares, time)
                        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, user_id)
                        flash(f"Bought {shares} shares of {symbol} at {usd(total_price)}")
                        return redirect("/")
                else:
                    return apology("invalid symbol", 400)
            else:
                return apology("invalid number of shares", 400)
        else:
            return apology("you need to provide symbol", 400)
    else:
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    nature_list =[]
    user_id = session["user_id"]
    symbols = db.execute("SELECT symbol FROM history WHERE user_id = ?", user_id)[0]
    prices = db.execute("SELECT price FROM history WHERE user_id = ?", user_id)[0]
    shares = db.execute("SELECT shares FROM history WHERE user_id = ?", user_id)[0]
    for share in shares:
        if share > 0:
            nature_list.append("BOUGHT")
        else:
            nature_list.append("SOLD")

    return render_template("history.html", symbols=symbols, prices=prices, shares=shares, nature_list=nature_list)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""
    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        symbol_dict = lookup(symbol)
        if symbol_dict:
            return render_template("quoted.html", symbol_dict=symbol_dict)
        else:
            return apology("invalid symbol", 400)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if username and password and confirmation:
            username_validity = db.execute("SELECT * FROM users WHERE username = ?", username)
            if len(username_validity) == 0:
                if confirmation == password:
                    hash = generate_password_hash(password)
                    db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)
                    rows = db.execute("SELECT * FROM users WHERE username = ?", username)
                    session["user_id"] = rows[0]["id"]
                    return redirect("/")
                else:
                    return apology("password and Confirmation did not match", 400)
            else:
                return apology("this username has been taken", 400)
        else:
            return apology(f"you need to fill in all details", 400)
    else:
        return render_template("register.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    symbols = []
    user_id = session["user_id"]
    for i in (db.execute("SELECT DISTINCT symbol FROM history WHERE user_id = ?", user_id)):
        symbols.append((i["symbol"]))
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        if shares and shares.isdigit() and int(shares) > 0:
            print(symbol)
            avail_shares = int(db.execute("SELECT SUM(shares) AS n FROM history WHERE user_id = ? AND symbol = ?", user_id, symbol)[0]["n"])
            print(avail_shares)
            if int(shares) < avail_shares:
                symbol_dict = lookup(symbol)
                user_id = session["user_id"]
                time = "18-07-2023"
                price = int(symbol_dict["price"])
                total_price = price * int(shares)
                new_shares = -int(shares)
                db.execute("INSERT INTO history (user_id, symbol, price, shares, time) VALUES(?, ?, ?, ?, ?)", user_id, symbol, price, new_shares, time)
                flash(f"Sold {shares} shares of {symbol} at {usd(total_price)}")
                return redirect("/")
            else:
                return apology(f"enter a valid amount of shares", 400)
        else:
            return apology(f"fill in all details", 400)
    else:
        return render_template("sell.html",symbols=symbols)
