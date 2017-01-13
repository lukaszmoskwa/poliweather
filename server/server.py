#!/usr/bin/env python
# API KEY 47203e62524b2e776149dffb291c15ad
import urllib2, json, pprint
from flask import Flask, render_template, send_from_directory
app = Flask(__name__)

appkey = "47203e62524b2e776149dffb291c15ad"

global cache
cache = []

#Added route to see files included in the download folder
@app.route("/download/<path:path>")
def send_file(path):
    return send_from_directory("templates/download", path)

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

# Definizione di Docs page
@app.route("/<parame>")
def docspage(parame):
    if parame == "documentation.html":
        return render_template("documentation.html")

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

@app.route("/app/city/<cityname>")
def getcitybynameapp(cityname):
	cityname = cityname.replace(" ", "")
	try:
		response = urllib2.urlopen('http://api.openweathermap.org/data/2.5/forecast?lang=it&APPID=' + appkey + '&q=' + cityname)
		json_data = json.load(response)
		json_fixed = {}
		json_fixed['cityName'] = json_data['city']['name']
		json_fixed['country'] = json_data['city']['country']
		json_fixed['humidity'] = json_data['list'][0]['main']['humidity']
		json_fixed['wind'] = json_data['list'][0]['wind']['speed']
		json_fixed['temp'] = []
		json_fixed['weather'] = []
		json_fixed['description'] = []
		json_fixed['time'] = []
		for x in range (0, 34):
			json_fixed['temp'].append(json_data['list'][(x)]['main']['temp'])
			json_fixed['weather'].append(json_data['list'][(x)]['weather'][0]['main'])
			json_fixed['description'].append(json_data['list'][(x)]['weather'][0]['description'])
			json_fixed['time'].append(json_data['list'][(x)]['dt_txt'])
		cache.append(json_fixed)
		return json.dumps(json_fixed) 
	except urllib2.URLError as e:
		return "{\"cod\": 500}"

@app.route("/cache")
def showcache():
	return json.dumps(cache)


if __name__ == "__main__":
    app.run()

