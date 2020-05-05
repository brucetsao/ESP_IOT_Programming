
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
	
	$result=mysqli_query($link,$qrystr);		//將dhtdata的資料找出來(只找最後5

  if($result!==FALSE){
	 while($row = mysqli_fetch_array($result)) 
	 {
			array_push($d00, $row["MAC"]);		// $row[欄位名稱] 就可以取出該欄位資料
			array_push($d01, $row["UPDATETIME"]);	// array_push(某個陣列名稱,加入的陣列的內容
			array_push($d02, $row["pm10"]);
			array_push($d03, $row["pm25"]);
			array_push($d04, $row["pm100"]);
			array_push($d05, $row["t"]);
			array_push($d06, $row["h"]);
		}// 會跳下一列資料
	 mysqli_free_result($result);	// 關閉資料集
	 mysqli_close($link);		// 關閉連線
  }
			
	




?>


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Frameset//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>NUK IOT Course</title>
<link href="webcss.css" rel="stylesheet" type="text/css" />

	<script src="/iot/code/highcharts.js"></script>
    <script src="/iot/code/highcharts-more.js"></script>
    <script src="/iot/code/modules/exporting.js"></script>
    <script src="/iot/code/modules/export-data.js"></script>
    <script src="/iot/code/modules/accessibility.js"></script>	
</head>
<body>
<?php
//include 'title.php';
?>
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
		</tr>

      <?php 
		  if(count($d00) >0)
		  {
				for($i=count($d00)-1;$i >=0  ;$i=$i-1)
					{
						echo sprintf("<tr><td>%s</td><td>%f</td><td>%f</td><td>%f</td><td>%f</td></tr>", 
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

 //-----------particle--------------

Highcharts.chart('container1', {
    chart: {
        type: 'spline'
    },
    title: {
        text: 'Temperature',
		fontsize: 30
    },
    subtitle: {
        text: ''
    },
    xAxis: {
        categories: [
		<?php
	for($i=count($d01)-1;$i >=0  ;$i=$i-1)
		{
			echo "'";
			echo $d01[$i];
			echo "',";
		}
		?>
        ]
    },
    yAxis: {
        title: {
            text: '.C'
        }
    },
    plotOptions: {
        line: {
            dataLabels: {
                enabled: true
            },
            enableMouseTracking: false
        }
    },
    series: [{
        name: 'PM1.0',
        data: [
		<?php
	for($i=count($d01)-1;$i >=0  ;$i=$i-1)
		{
			echo $d02[$i];
			echo ",";
		}
		?>
        ]},{
        name: 'PM2.5',
        data: [
		<?php
	for($i=count($d01)-1;$i >=0  ;$i=$i-1)
		{
			echo $d03[$i];
			echo ",";
		}
		?>
        ]},{
        name: 'PM10',
        data: [
		<?php
	for($i=count($d01)-1;$i >=0  ;$i=$i-1)
		{
			echo $d04[$i];
			echo ",";
		}
		?>
        ]} ]
});
 //---------Color Temperaturte----------------
Highcharts.chart('container2', {
    chart: {
        type: 'spline'
    },
    title: {
        text: 'Temperature & Humidity ',
		fontsize: 30
    },
    subtitle: {
        text: ''
    },
    xAxis: {
        categories: [
		<?php
		for($i=0;$i < count($d01);$i=$i+1)
		{
			echo "'";
			echo $d01[$i];
			echo "',";
		}
		?>
        ]
    },
    yAxis: {
        title: {
            text: '%'
        }
    },
    plotOptions: {
        line: {
            dataLabels: {
                enabled: true
            },
            enableMouseTracking: false
        }
    },
    series: [{
        name: '.C',
        data: [
		<?php
		for($i=0;$i < count($d01);$i=$i+1)
		{
			echo $d05[$i];
			echo ",";
		}
		?>
        ]},{
        name: 'Percent',
        data: [
		<?php
		for($i=0;$i < count($d01);$i=$i+1)
		{
			echo $d06[$i];
			echo ",";
		}
		?>
        ]} ]
});
		</script>
</body>
</html>
