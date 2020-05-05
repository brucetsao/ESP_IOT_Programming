import sys
import requests
import json
import time
import datetime
import math
import os
import http.client
import unicodedata
from pathlib import Path

from requests.exceptions import HTTPError
str2="?f01=%27C0A560%27&f02=%27%E7%A6%8F%E5%B1%B1%27&f03=%272020-03-03%2010:00:00%27&f04=24.778333&f05=121.494583&f06=405.0&f07=148&f08=1.4&f09=20.1&f10=71&f11=975.1&f12=0.0&f13=%2706%27&f14=%27%E6%96%B0%E5%8C%97%E5%B8%82%27&f15=%27061%27&f16=%27%E7%83%8F%E4%BE%86%E5%8D%80%27"

try:
	print('1Access Server  is ok')
	conn = http.client.HTTPConnection("mosquitotrap.nhri.org.tw",80, timeout=60)
	print(str2)
	
	print('2Access Server  is ok')
	#conn.request("GET","/index.php")
	conn.request("GET", str2)
	r2 = conn.getresponse()
	print(r2.status, r2.reason)
	#r = conn.getresponse()
	print('3Access Server  is ok')
	#time.sleep(10)
except: # request.exceptions.RequestException as e: #requests.exceptions.RequestException as e:
	print('Exception in data_output')
