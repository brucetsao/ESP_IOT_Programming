
<?php

   	include("./comlib.php");		//使用資料庫的呼叫程式
   	include("./Connections/iotcnn.php");		//使用資料庫的呼叫程式
		//	Connection() ;
  	$link=Connection();		//產生mySQL連線物件
	$qrystr="SELECT MAC, UPDATETIME, AVG(PM1) as pm10, AVG(PM25) as pm25, AVG(PM10) as pm100,AVG(temperature) as t,AVG(humidity) as h  FROM particle WHERE 1 GROUP BY MAC,UPDATETIME  order by updatetime desc limit 0,1" ;		//將dhtdata的資料找出來
//	int aa[] = {1,3,45,6,7} ;  == 	$aa = array(4,5,6,7,8,9);
//	int bb[] = {} ;  ==  $bb = array();
	$d00 = array();		// declare blank array of d00
	$d01 = array();	// declare blank array of d01
	$d02 = array();	// declare blank array of d02
	$d03 = array();	// declare blank array of d03
	$d04 = array();	// declare blank array of d03
	$d05 = array();	// declare blank array of d03
	$d06 = array();	// declare blank array of d03
	
	$result=mysql_query($qrystr,$link);		//將dhtdata的資料找出來(只找最後5

  if($result!==FALSE){
	 while($row = mysql_fetch_array($result)) 
	 {
			array_push($d00, $row["MAC"]);		// $row[欄位名稱] 就可以取出該欄位資料
			array_push($d01, $row["UPDATETIME"]);	// array_push(某個陣列名稱,加入的陣列的內容
			array_push($d02, $row["pm10"]);
			array_push($d03, $row["pm25"]);
			array_push($d04, $row["pm100"]);
			array_push($d05, $row["t"]);
			array_push($d06, $row["h"]);
		}// 會跳下一列資料
	 mysql_free_result($result);	// 關閉資料集
	 mysql_close($link);		// 關閉連線
  }
			
	




?>


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Frameset//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>IOT Course</title>
<link href="webcss.css" rel="stylesheet" type="text/css" />


    
	<script src="/code.highcharts.com/highcharts.js"></script>
    <script src="/code.highcharts.com/highcharts-more.js"></script>
    <script src="/code.highcharts.com/modules/solid-gauge.js"></script>
    <script src="/code.highcharts.com/modules/exporting.js"></script>
    <script src="/code.highcharts.com/modules/export-data.js"></script>
    <script src="/code.highcharts.com/modules/accessibility.js"></script>
    


    
</head>
<body>

<form id="form1" method="post" action="">
<div id="container1" style="min-width: 95%; height: 600px; margin: 0 auto"></div>
<p>
<div id="container2" style="min-width: 95%; height: 600px; margin: 0 auto"></div>
<p>
<div align="center">


   <table border="1" cellspacing="1" cellpadding="1">		
		<tr>
			<td>Date Time</td>
			<td>particle pm1.0</td>
			<td>particle pm2.5</td>
			<td>particle pm10</td>
			<td>temperature</td>
			<td>humidity</td>
      <?php 
		  if(count($d00) >0)
		  {
				for($i=count($d00)-1;$i >=0  ;$i=$i-1)
					{
						echo sprintf("<tr><td>%s</td><td>%f</td><td>%f</td><td>%f</td><td>%f</td><td>%f</td></tr>", 
						   $d01[$i], $d02[$i], $d03[$i], $d04[$i], $d05[$i], $d06[$i]);
					 }
		 }
      ?>

   </table>

</div>

</form>
<?php
//include 'footer.php';
?>

<script type="text/javascript">

 //-----------particle-----
 
Highcharts.chart('container1', {

    chart: {
        type: 'gauge',
        plotBackgroundColor: null,
        plotBackgroundImage: null,
        plotBorderWidth: 0,
        plotShadow: false
    },

    title: {
        text: 'Speedometer'
    },

    pane: {
        startAngle: -150,
        endAngle: 150,
        background: [{
            backgroundColor: {
                linearGradient: { x1: 0, y1: 0, x2: 0, y2: 1 },
                stops: [
                    [0, '#FFF'],
                    [1, '#333']
                ]
            },
            borderWidth: 0,
            outerRadius: '109%'
        }, {
            backgroundColor: {
                linearGradient: { x1: 0, y1: 0, x2: 0, y2: 1 },
                stops: [
                    [0, '#333'],
                    [1, '#FFF']
                ]
            },
            borderWidth: 1,
            outerRadius: '107%'
        }, {
            // default background
        }, {
            backgroundColor: '#DDD',
            borderWidth: 0,
            outerRadius: '105%',
            innerRadius: '103%'
        }]
    },

    // the value axis
    yAxis: {
        min: 0,
        max: 200,

        minorTickInterval: 'auto',
        minorTickWidth: 1,
        minorTickLength: 10,
        minorTickPosition: 'inside',
        minorTickColor: '#666',

        tickPixelInterval: 30,
        tickWidth: 2,
        tickPosition: 'inside',
        tickLength: 10,
        tickColor: '#666',
        labels: {
            step: 2,
            rotation: 'auto'
        },
        title: {
            text: 'km/h'
        },
        plotBands: [{
            from: 0,
            to: 120,
            color: '#55BF3B' // green
        }, {
            from: 120,
            to: 160,
            color: '#DDDF0D' // yellow
        }, {
            from: 160,
            to: 200,
            color: '#DF5353' // red
        }]
    },

    series: [{
        name: 'Speed',
        data: [80],
        tooltip: {
            valueSuffix: ' km/h'
        }
    }]

},
// Add some life
function (chart) {
    if (!chart.renderer.forExport) {
        setInterval(function () {
            var point = chart.series[0].points[0],
                newVal,
                inc = Math.round((Math.random() - 0.5) * 20);

            newVal = point.y + inc;
            if (newVal < 0 || newVal > 200) {
                newVal = point.y - inc;
            }

            point.update(newVal);

        }, 3000);
    }
});
 //---------


 //---------Color Temperaturte----------------

		</script>
</body>
</html>
