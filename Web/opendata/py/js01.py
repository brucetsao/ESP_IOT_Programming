import sys
import requests
import json
import time
import datetime
import math
import os
import http.client
from pathlib import Path

from requests.exceptions import HTTPError

url='https://opendata.cwb.gov.tw/api/v1/rest/datastore/O-A0001-001?Authorization=CWB-8D336EBD-4CD8-4077-AD00-F5551E8DE2DA&format=JSON'
try:
    res = requests.get(url)
    res.raise_for_status()
except HTTPError as http_err:
    print(f'HTTP error occurred: {http_err}')
    sys.exit(0)
except Exception as err:
    print(f'Other error occurred: {err}')
    sys.exit(0)
else:
    print('Success!')

table=json.loads(res.content)
print('return value = %s' %table['success'])

for data in table['records']['location']:
    print('item name =%s' % data['lat'])
    print('item name =%s' % data['lon'])
    print('item name =%s' % data['stationId'])
    print('item name =%s' % data['locationName'])
    print('item name =%s' % data['time']['obsTime'])
    for data2 in data['weatherElement']:
        print('subitem name =%s' % data2['elementName'])
        print('subitem name =%s' % data2['elementValue'])
    for data3 in data['parameter']:
        print('subitem name =%s' % data3['parameterName'])
        print('subitem name =%s' % data3['parameterValue'])
#    print('item name =%s' % data['weatherElement'])