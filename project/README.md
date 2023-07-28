# Etsy Price Tracker

## Idea behind Web Scrapping
For this project, I had to learn web scrapping, which I implemented in the price_checker function. I had to research on libraries such as BeautifulSoup and Selenium.



## index
This function displays the watchlist.

## search
This function calls the price_checker function to identify the current price of the product.

It redirects to a html page called searched.html

## searched
This function gives the user the option of whether to add the product to the Watchlist, or not.

If the product already exists in the Watchlist, it will not add it regardless if the user presses the "Add" button. This is to avoid the Watchlist being cluttered with the same product.

It finally redirects the user to index.html which displays the Watchlist.

## price_checker