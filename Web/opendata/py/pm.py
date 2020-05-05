
from urllib.request import urlopen
import pandas as pd
import datetime
import requests
import json
import os
import numpy as np
from configparser import ConfigParser


#input_file = open ('pm25.json')
# with open("pm25.json", encoding="utf-8") as f:
    # #print(f.read())
    # test = f.read()
    # print (test)
# json_array = json.load(test)['result']['records']
# for item in test:
    # print(item['records'])
#cfg = ConfigParser()
#cfg.read('config.ini')
#limit = int(cfg['param']['limit'])
#offset = int(cfg['param']['offset'])


try:
    #??
    #url = 'https://opendata.epa.gov.tw/webapi/api/rest/datastore/355000000I-000208/?format=json&limit='+limit+'&offset='+offset+'&sort=SiteId&token=6euxiKGh6UyQ3dxBfAIH9A'
    #rain
    url ='https://opendata.cwb.gov.tw/api/v1/rest/datastore/O-A0002-001?Authorization=CWB-8D336EBD-4CD8-4077-AD00-F5551E8DE2DA&format=JSON'
    #print(url)
    r = requests.get(url)#
    
    
    #print (r.text['result']['records'])
    #for item in r.text[]
    #jsonData = json.loads(r.text)
    #print (jsonData)
    #df = pd.read_json(jsonData)
    #for items in r:
    #    print (item['records'])
    #print (len(jsonData['results']['records']))
    #for info in jsonData['results']['records']:
    #    print (info)
    #print (json_normalize(jsonData['results']['records']))
    #print (df)
    #with urllib.request.urlopen("https://opendata.epa.gov.tw/webapi/api/rest/datastore/355000000I-000208/?format=json&limit=2&offset=0&sort=SiteId&token=6euxiKGh6UyQ3dxBfAIH9A") as url:
    #    print (url.read())
        #data = json.loads(url.read().decode())
        #print(data)
except:
    print ("Error")
    
        
        
        
