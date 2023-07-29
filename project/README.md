# Etsy Price Tracker
#### Video Demo:  <https://youtu.be/Tct7MkItTKE>
#### Description:

#### Idea behind Web Scraping
For this project, I had to learn web scraping, which I implemented in the price_checker function. I had to research on libraries such as BeautifulSoup and Selenium. I decided that I could use this to my advantage, by improving my online shopping experience of a website I use frequently, Etsy. By experimenting on the html code in the Etsy product pages, I was able to identify the html tags the relevant information is located in and make use of them in my project.

#### index
This function displays the Watchlist. In this function, data is extracted from the SQL database called project.db and from the history TABLE, all of the user's existing products are displayed as a table. The Original Price is stored in the database, while the price_checker function is called for the Current Prices. For each product, there is the option of clicking a "Delete" button, which will delete the data from the database and therefore, only display the remaining products. It starts off with an empty page, but once the "Add Item" link is clicked, it directs you to a page where the user can start adding products to the table.

#### search
This function calls the price_checker function to identify the current price of the product. To use it, the user is prompted to enter the URL of the product page and click the "Search" button. This will redirect the user to a html page called searched.html

#### searched
This function gives the user the option of whether to add the product to the Watchlist, or not. If the product already exists in the Watchlist, it will not add it regardless if the user presses the "Add" button. This is to avoid the Watchlist being repeated with the same product. It finally redirects the user back to index.html which displays the updated Watchlist.

#### price_checker
This function takes in one argument which is the URL of the product page. Using the library BeautifulSoup, this function is able to parse the HTML page to identify what each HTML tag represents. Through identifying elements based on their IDs and Classes, it assigns variables for the current price, as well as the product name. These variables are then inserted into the database, using SQL commands. This function is called for each product evertime the user is redirected to the index page, which enables the Watchlist table to be automatically updated.

#### project.db
project.db is a SQL database which has 2 main TABLES, 1 called "users" to contain the login details of users while the other is called "history" to contain all products that are currently in the Watchlist tables of any user. The "user" TABLE stores in a unique id for each new registrant, the username of the registrant as well as a hash string of their password. The "history" TABLE stores data required for functions such as price_checker and index to be functional. Firstly, the user_id of the user is stored so as to easily identify the products to display on respective users. The name and price are also stored in the TABLE, which are later displayed on the Watchlist table. Lastly, the URL of the product is also stored, so that when the user is redirected to index.html, the same URL could be passed into price_checker in order to obtain the respective Current Prices for the Watchlist table.

