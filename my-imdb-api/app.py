import csv
import glob
import json

from flask import Flask, Response, request

app = Flask(__name__)


def load_movies():
    files = glob.glob("*.csv")
    if not files:
        return []
    movies = []
    with open(files[0], newline="", encoding="utf-8") as f:
        for row in csv.DictReader(f):
            for key in row:
                if row[key] == "":
                    row[key] = None
            movies.append(row)
    return movies


def movies_by_genre(genre):
    movies = load_movies()
    if not genre:
        return movies
    genre = genre.strip().lower()
    result = []
    for movie in movies:
        genres = (movie.get("Genre") or "").lower().split(",")
        if genre in [g.strip() for g in genres]:
            result.append(movie)
    return result


def json_response(data, status=200):
    return Response(json.dumps(data), status=status, mimetype="text/html")


@app.route("/")
def index():
    return json_response(movies_by_genre(request.args.get("genre")))


@app.route("/action")
def action():
    return json_response(movies_by_genre("action"))


@app.route("/adventure")
def adventure():
    return json_response(movies_by_genre("adventure"))


@app.route("/comedy")
def comedy():
    return json_response(movies_by_genre("comedy"))


@app.route("/drama")
def drama():
    return json_response(movies_by_genre("drama"))


@app.route("/romance")
def romance():
    return json_response(movies_by_genre("romance"))
