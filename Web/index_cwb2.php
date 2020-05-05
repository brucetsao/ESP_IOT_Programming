<?php 
include("./Connections/map8key.php");
?>
	
<?php

   	include("./Connections/iotcnn.php");		//使用資料庫的呼叫程式
	
	$link=Connection();		//產生mySQL連線物件

$datastr1 =  "SELECT * FROM ncnuiot.cwbsite c order by lat,lon ;"  ;	
$datastr =  "SELECT a.id as sid, a.pm1 as pm1, a.pm25 as pm25, a.pm10 as pm10,a.updatetime as datatime, a.mac as mac, b.deviceid as did, b.devicename as dname, b.deviceaddr as addr , b.latitude as latitude, b.longitude as longitude  FROM ncnuiot.particle as a , ncnuiot.pmdevice as b WHERE a.mac = b.mac  order by b.deviceid desc"  ;	
//include('./genmos.php'); 
   
?>
<!DOCTYPE html>
<html>
  <head>
    <style>
       /* Set the size of the div element that contains the map */

      html, body {
        margin: 0;
        padding: 0;
        height: 100%;
        width: 100%;
      }
      #map {
        height: 800px;  /* The height is 400 pixels */
        width: 100%;  /* The width is the width of the web page */
       }
      #map a.gomp-ctrl-logo {
          background-size: cover;
          height: 12px;
          width: 48px;
      }
	  #legend {
        font-family: Arial, sans-serif;
        background: #fff;
        padding: 10px;
        margin: 10px;
        border: 3px solid #000;
      }
      #legend h3 {
        margin-top: 0;
      }
      #legend img {
        vertical-align: middle;
      }
    </style>

	 <title>溫度分佈圖 (Heatmap)</title>        

    <link rel="stylesheet" href="https://api.map8.zone/css/gomp.css?key=<?php echo $map8key; ?>" />
	
  </head>
  <body>
    <?php
include 'title.php';
?>
    <div id="map" class="gomp-map">
    <div align="center">
    <label><input type="radio" name="switch" value="PM25" checked>PM2.5 </label>
    <label><input type="radio" name="switch" value="PM1">PM1.0</label>
    <label><input type="radio" name="switch" value="PM10">PM10</label>
    </div>
    <div align="center">
    <label><input type="radio" name="cwb" value="rain" checked checked>雨量</label>
    <label><input type="radio" name="cwb" value="temp">溫度</label>
    <label><input type="radio" name="cwb" value="humid">濕度</label>
    <label><input type="radio" name="cwb" value="bar">氣壓</label>
    </div>
<?php include("./cwbmap2.php");?> 
    <?php include 'footer.php'; ?> 
</body>
</html>
<?php


mysql_free_result($Recordset1);

?>
