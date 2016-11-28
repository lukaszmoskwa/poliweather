#!/usr/bin/env python
# API KEY 47203e62524b2e776149dffb291c15ad
import urllib2, json
from flask import Flask, render_template, send_from_directory
app = Flask(__name__)

appkey = "47203e62524b2e776149dffb291c15ad"

#Added route to see js files from flask
@app.route("/js/<path:path>")
def send_js(path):
    return send_from_directory("templates/js", path)

#Added route to see css files from flask
@app.route("/css/<path:path>")
def send_css(path):
    return send_from_directory("templates/css", path)

#Added route to see images files from flask
@app.route("/images/<path:path>")
def send_image(path):
    return send_from_directory("templates/images", path)

#Added route to see fonts files from flask
@app.route("/fonts/<path:path>")
def send_fonts(path):
    return send_from_directory("templates/fonts", path)

# Definizione di Home page
@app.route("/")
def homepage():
    return render_template("index.html")

# Viene passato city come parametro all'interno della funzione
@app.route("/city/<cityname>")
def getcitybyname(cityname):
	cityname = cityname.replace(" ", "")
	try:
		response = urllib2.urlopen('http://api.openweathermap.org/data/2.5/weather?lang=it&APPID=' + appkey + '&q=' + cityname)
		return response.read()
	except urllib2.URLError as e:
		return "{\"cod\": 500}"
	#return "city" + cityname

@app.route("/city/<lat>&<lon>")
def getcitybycoord(lat, lon):
	try:
		response = urllib2.urlopen('http://api.openweathermap.org/data/2.5/weather?lang=it&APPID=' + appkey + '&lat=' + lat + '&lon=' + lon)
		return response.read()	
	except urllib2.URLError as e:
		return "{\"cod\": 500}"

# TODO: Aggiungere la documentazione e i commenti in inglese
# Prendere le informazioni di forecast (previsione nelle prossime ore fino a 5 giorni)

@app.route("/city/3/<cityname>")
def getcitybyname3(cityname):
	cityname = cityname.replace(" ", "")
	try:
		response = urllib2.urlopen('http://api.openweathermap.org/data/2.5/forecast?lang=it&APPID=' + appkey + '&q=' + cityname)
		return response.read()
	except urllib2.URLError as e:
		return "{\"cod\": 500}"


if __name__ == "__main__":
    app.run()

