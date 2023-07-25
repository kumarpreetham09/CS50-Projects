import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, password_required

# Configure application
app = Flask(__name__)


# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///project.db")


@app.after_request
def after_request(response):

    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@password_required
def index():

    user_id = session["user_id"]
    all_urls = []
    data = []
    cash = int(db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"])
    for i in db.execute(
        "SELECT DISTINCT symbol FROM history WHERE user_id = ?", user_id
    ):
        all_symbols.append(i["symbol"])

    for symbol in all_symbols:
        price = round(float(lookup(symbol)["price"]), 4)
        shares = int(
            db.execute(
                "SELECT SUM(shares) AS n FROM history  WHERE user_id = ? AND symbol = ?",
                user_id,
                symbol,
            )[0]["n"]
        )
        total = round(float(price * shares), 2)
        data.append(
            {"symbol": symbol.upper(), "shares": shares, "price": price, "total": total}
        )

    return render_template("index.html", data=data)


@app.route("/search", methods=["GET", "POST"])
@password_required
def search():
    if request.method == "POST":
        return apology("hello")

    else:
        return render_template("search.html")



@app.route("/login", methods=["GET", "POST"])
def login():


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


@app.route("/register", methods=["GET", "POST"])
def register():

    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if username and password and confirmation:
            username_validity = db.execute(
                "SELECT * FROM users WHERE username = ?", username
            )
            if len(username_validity) == 0:
                if confirmation == password:
                    hash = generate_password_hash(password)
                    db.execute(
                        "INSERT INTO users (username, hash) VALUES(?, ?)",
                        username,
                        hash,
                    )
                    rows = db.execute(
                        "SELECT * FROM users WHERE username = ?", username
                    )
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


@app.route("/logout")
def logout():


    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


