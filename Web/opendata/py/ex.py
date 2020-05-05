import sys
import requests
import json
from requests.exceptions import HTTPError

url='https://opendata.epa.gov.tw/webapi/api/rest/datastore/355000000I-000208?offset=0&limit=10&sort=SiteId&format=json&token={6euxiKGh6UyQ3dxBfAIH9A}'
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

for data in table['result']['records']:
    print('item name =%s' % data['ItemName'])
    print('ItemEngName =%s' % data['ItemEngName'])	
    print('MonitorValue00 =%s' % data['MonitorValue00']);	
    print('')