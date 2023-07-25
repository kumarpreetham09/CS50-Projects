import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
from helpers import apology, login_required

app = Flask(__name__)


app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


db = SQL("sqlite:///project.db")


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
    information = []
    user_id = session["user_id"]
    data = db.execute("SELECT * FROM history WHERE user_id = ?",user_id)
    for dataset in data:
        price = float(dataset["price"])
        url = dataset["url"]
        result = price_checker(url)
        name = result["name"]
        current_price = float(result["price"])
        change = float(current_price - price)
        information.append({"product":name, "price":price, "c_price":current_price, "change":change})

    return render_template("index.html", information=information)


@app.route("/searched", methods=["GET", "POST"])
@login_required
def searched():

    data = session["data"]
    if request.method == "POST":
        user_id = session["user_id"]
        price = float(data["price"])
        url = data['url']
        name = data['name']
        check = db.execute("SELECT COUNT(*) FROM history WHERE url = ?",url)
        print(check)
        if check == 0:
            db.execute("INSERT INTO history (user_id, name, price, url) VALUES(?,?,?,?)",user_id, name, price, url)
        return redirect("/")

    else:
        return render_template("searched.html",data=data)



@app.route("/search", methods=["GET", "POST"])
@login_required
def search():
    session["data"].clear()
    if request.method == "POST":
        url = request.form.get("url")
        data = price_checker(url)
        session["data"] = data
        return redirect("/searched")

    else:
        return render_template("search.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    session.clear()

    if request.method == "POST":
        if not request.form.get("username"):
            return apology("must provide username", 403)

        elif not request.form.get("password"):
            return apology("must provide password", 403)

        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        session["user_id"] = rows[0]["id"]

        return redirect("/")

    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    session.clear()

    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
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


def price_checker(url):
    url_name = "Pot"
    chrome_options = Options()
    chrome_options.add_argument("--disable-notifications")
    browser = webdriver.Chrome(chrome_options=chrome_options)
    browser.get(url)
    url_price = browser.find_element(By.XPATH, '//div[contains(@class,"a-section a-spacing-micro")]//span[contains(@class, "a-offscreen")]').get_attribute("textContent").split("$")[1]
    return {"name":str(url_name), "price":url_price, "url":str(url)}





