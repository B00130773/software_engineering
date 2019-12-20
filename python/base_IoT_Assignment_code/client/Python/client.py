import numpy as npy
import urllib.request
import xml.etree.ElementTree as elementtree
import matplotlib.pyplot as plot
import matplotlib as mpl

response = urllib.request.urlopen("http://localhost:8080/")
data = response.read().decode()
TEMPERATURE = []
TIME = []
root = elementtree.fromstring(data.strip("\n"))


for reading in root.findall('reading'):
    time = reading.find('time').text
    TIME.append(time[time.find(' '):])
    TEMPERATURE.append(int(reading.find('temperature').text))
    
plot.style.use('ggplot')
title_obj = plot.title("Temperature Vs Time")
plot.setp(title_obj,fontsize='14',fontname='Arial')
plot.xlabel("Time")
plot.ylabel("Temperature")
plot.plot(TIME, TEMPERATURE, 'brown')
plot.show()