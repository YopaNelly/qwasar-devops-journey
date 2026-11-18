# Welcome to My First Scraper
***
- I [Gertrude Nelly Tatchou Yopa] worked on part 0 (request) and part 2 (transform). I wrote a function to request the page, and a function that turns each repository row into a dictionary with the developer, the repository name and the number of stars.
- I [Mbeumo Donfang Philippe Briand] worked on part 1 creating a function to extract from request result
- I did the last part into formating the final result of scrape data to conform to desired output with columns Developer,Repository Name,Number of Stars.

## Task
Scrape the page of the top 25 trending GitHub repositories and return the data as a CSV string. The challenge is to find the useful data inside the HTML, and to clean it so the CSV has the right columns.

## Description
The script has four functions. request_github_trending downloads the page with the requests library. extract finds every repository row with BeautifulSoup. transform reads the developer, the repository name and the number of stars of each row and returns a list of dictionaries. format turns that list into a CSV string with one line per repository.

## Installation
Download the dependency BeautifulSoup that will help you extract using command:
```md 
pip install BeautifulSoup
```
```python
get_page = request_github_trending(url)
extracted_rows = extract(get_page)
cleaned_rows = transform(extracted_rows)
csv_file = format(cleaned_rows)
```

## Usage
Import the functions, request the page, then extract, transform and format it:
```python
from my_first_scraper import *
page = request_github_trending(url)
csv_text = format(transform(extract(page)))
```

### The Core Team
Philippe Briand Mbeumo Donfang
Gertrude Nelly Tatchou Yopa 


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
