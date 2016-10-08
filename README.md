# Poli Weather

Project for Politecnico di Milano's course Piattaforme Software per la Rete - 2016/2017


##  Main schema
![](http://i.imgur.com/vXn8zwo.png)

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

The server will be hosted on a raspberry pi.

##  Client

TODO: The client will be written i C++ using QT.

##  Web Service

TODO
