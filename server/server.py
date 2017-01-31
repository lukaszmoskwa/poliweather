#!/usr/bin/env python

# Server for "Piattaforme Software per la Rete" project
# To add new commands, functions or redirect to html pages, just create a new
# @app.route("/something") and define it

# API KEY 47203e62524b2e776149dffb291c15ad
import urllib2, json, pprint, datetime, time
from flask import Flask, render_template, send_from_directory
app = Flask(__name__)

# Openweather Appkey for poliweather
appkey = "47203e62524b2e776149dffb291c15ad"

global cache
cache = []

# Function to change the color of a string in output (bash)
def hilite(string, status, bold):
    attr = []
    if status:
        # Green
        attr.append('32')
    else:
        # Red
        attr.append('31')
    if bold:
        attr.append('1')
    return '\x1b[%sm%s\x1b[0m' % (';'.join(attr), string)

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

# Definizione di Home page
@app.route("/")
def homepage():
	return render_template("index.html")

# Function to retrieve data in full format knowing lat and lon coordinates
@app.route("/city/<lat>&<lon>")
def getcitybycoord(lat, lon):
	try:
		response = urllib2.urlopen('http://api.openweathermap.org/data/2.5/weather?lang=it&APPID=' + appkey + '&lat=' + lat + '&lon=' + lon)
		return response.read()
	except urllib2.URLError as e:
		return "{\"cod\": 500}"

# Default function to obtain data from openweather and parse them in a easy-to-read format
@app.route("/app/city/<cityname>")
def getcitybynameapp(cityname):
	cityname = cityname.replace(" ", "")
	cache_result = check_cache(cityname)
	if cache_result is not None:
		print hilite("Result taken from the cache!",1,1)
		return json.dumps(cache_result)
	else:
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
			#Aggiungere commento su 34
			for x in range (0, 34):
				json_fixed['temp'].append(json_data['list'][(x)]['main']['temp'])
				json_fixed['weather'].append(json_data['list'][(x)]['weather'][0]['main'])
				json_fixed['description'].append(json_data['list'][(x)]['weather'][0]['description'])
				json_fixed['time'].append(json_data['list'][(x)]['dt_txt'])
			json_fixed['cache_time'] = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
			cache.append(json_fixed)
			print hilite("Result taken from Openweather server!",0,1)
			return json.dumps(json_fixed)
		except urllib2.URLError as e:
			return "{\"cod\": 500}"

# Function to display the cache when requested
@app.route("/cache")
def show_cache():
	return json.dumps(cache)

# Function to clear the cache on request while the server is still running. Used for demonstration purposes only.
@app.route("/clear_cache")
def clear_cache():
	del cache[:]
	return "<h1>The Cache was correctly cleared</h1>"

# Function to check if the data are already stored in the cache. Informations older that 30 minutes will be deleted and requested again from Openweather
def check_cache(request_string):
	current = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
	current_time = time.strptime(current, "%Y-%m-%d %H:%M:%S")
	for elim in cache:
		check_time = time.strptime(elim['cache_time'], "%Y-%m-%d %H:%M:%S")
		pprint.pprint(elim['cache_time'] +" "+ request_string)
		if check_time < current_time and (current_time.tm_min - check_time.tm_min > 30 or current_time.tm_hour > check_time.tm_hour or current_time.tm_wday > check_time.tm_wday):
			cache.remove(elim)
	for i in cache:
		if i['cityName'] == request_string:
			return i

if __name__ == "__main__":
    app.run(host='0.0.0.0')

