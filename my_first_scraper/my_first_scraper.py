import requests
from bs4 import BeautifulSoup
import csv

def request_github_trending(url):
    return requests.get(url)


def extract(page):
    soup=BeautifulSoup(page.content,'html.parser')
    rows=soup.find_all(class_='Box-row')
    return rows


def transform(html_repos):
    repos = []
    for repo in html_repos:
        link = repo.find("h1").find("a")["href"]
        parts = link.strip("/").split("/")
        stars = repo.find("a", href=lambda h: h and h.endswith("/stargazers"))
        stars = stars.get_text().strip().replace(",", "")
        repos.append({
            "developer": parts[0],
            "repository_name": parts[1],
            "nbr_stars": stars,
        })
    return repos[:25]

def format(repositories_data:[str]):
    csv_file =','.join(repositories_data[0].keys())+ '\n'
    for user in repositories_data:
        line = ','.join(user.values())+'\n'
        csv_file += line
    return csv_file
