# Etsy Price Tracker

## Idea behind Web Scrapping
For this project, I had to learn web scrapping, which I implemented in the price_checker function. I had to research on libraries such as BeautifulSoup and Selenium. I decided that I could use this to my advantage, by improving my online shopping experience of a website I use frequently, Etsy. By experimenting on the html code in the Etsy product pages, I was able to identify the html tags the relevent information are located in and make use of them in my project.

## index
This function displays the Watchlist. In this function, data is extracted from the SQL database called project.db and from the history TABLE, all of the user's existing products are displayed as a table. The Original Price is stored in the database, while the price_checker function is called for the Current Prices. It starts off with an empty page but once the "Add Item" link is clicked, it directs you to a page where the user can start adding products to the table.

## search
This function calls the price_checker function to identify the current price of the product. To use it, the user is prompted to enter the url of the product page and click the "Search" button. This will redirect the user to a html page called searched.html

## searched
This function gives the user the option of whether to add the product to the Watchlist, or not. If the product already exists in the Watchlist, it will not add it regardless if the user presses the "Add" button. This is to avoid the Watchlist being repeated with the same product. It finally redirects the user back to index.html which displays the updated Watchlist.

## price_checker