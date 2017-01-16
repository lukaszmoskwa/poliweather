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
![](http://i.imgur.com/kJozWxv.png)

##  Server

The server is written in python and uses the framework Flask (http://flask.pocoo.org/). Using flask it is possibile to use the decorator app.route, which takes as parameter the path on the web service.

```python
@app.route("/")
def hello():
    return "Homepage!"
```

Example:

```python
@app.route("/city/<cityname>")
def cityFun():
    return functionForJSON(cityname)
```
In this example, if you make a request to the server passing instead of \<cityname\> the name of a city, it will run the function to retrieve the forecast information about the city as JSON.

It is also possible to request those information from the server using the lat and long parameters.

TODO: Add specific function to request forecast for solar panel weaterboard. 

TODO: Add documentation and comments for the code 

The server will be hosted on a raspberry pi, and it will also have a cache to store for a certain time information already requested. In this way, if several solar panel's weatherboard request information from the same location, there won't be an over-request using the api of openweather. 

##  Client

The client is completely written in C++, using the QT cross platform application framework.

Client screenshot:

![](http://i.imgur.com/Bui5uBc.png)

##  Web Service

Added a default template to start working with (Xeon Template). I'm using flask to run the webservice as well
TODO: Add comments to the code

Web Service screenshots:

![](http://i.imgur.com/EgxQHKg.png)

---

![](https://s17.postimg.org/7cbxdcyal/pw_screen.png)
