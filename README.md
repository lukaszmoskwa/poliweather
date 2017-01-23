Table of Contents
=================

   * [Poli Weather](#poli-weather)
      * [Main schema](#main-schema)
      * [Server](#server)
      * [Client](#client)
      * [Web Service](#web-service)


# Poli Weather

Project for Politecnico di Milano's course Piattaforme Software per la Rete - 2016/2017


##  Main schema
![- Image of the main schema -](http://i.imgur.com/kJozWxv.png)

##  Server

The server is written in python and uses the framework Flask (http://flask.pocoo.org/). Using flask it is possibile to use the decorator app.route, which takes as parameter the path on the web service.

```python
@app.route("/")
def hello():
    return "Homepage!"
```

Example:

```python
@app.route("/app/city/<cityname>")
def cityFun():
    return functionForJSON(cityname)
```
In this example, if you make a request to the server passing instead of \<cityname\> the name of a city, it will run the function to retrieve the forecast information about the city as JSON.

It is also possible to request those information from the server using the lat and long parameters.

The server will be hosted on a raspberry pi, and it will also have a cache to store for a certain time information already requested. In this way, if several solar panel's weatherboard request information from the same location, there won't be an over-request using the api of openweather. 

#### Data format

As the data received from Openweather contains much more information that I actually needed for the project, I decided to parse those data in a easy-to-read format.

```python
json_data = json.load(response)
json_fixed = {}
json_fixed['cityName'] = json_data['city']['name']
json_fixed['country'] = json_data['city']['country']
json_fixed['humidity'] = json_data['list'][0]['main']['humidity']
json_fixed['wind'] = json_data['list'][0]['wind']['speed']
```

In order to add new data to retrieve, you just need to create a new field in the json_fixed dict

```python
# Add new data
json_fixed['newdata'] = ...
```

#### Cache

As the number of request grows, you don't want to always ask the Openweather server for datas, at least not when you already had them recently! So I decided to add a cache to the server in order to save and use the datas if many users make the same request in a short time.

You can see the cache anytime browsing poliweather.tk/cache

##  Client

The client is completely written in C++, using the QT cross platform application framework.

Client screenshot:

![- Client Screenshot -](http://i.imgur.com/Bui5uBc.png)

The client was written natively for Linux, but it is also compiled for Windows (.exe format) thanks to MXE cross-compiler and Android (.apk format).

As you can see in the screenshot above I decided to display the current forecast in a main panel showing as well the temperature, wind speed and humidity status. Then you can see the forecast of the following 3 days in the scroll panel.

##  Web Service

Added a default template to start working with (Xeon Template). I'm using flask to run the webservice as well

Web Service screenshots:

![](http://i.imgur.com/EgxQHKg.png)

---

![](https://s17.postimg.org/7cbxdcyal/pw_screen.png)
