
<?php
 
   	include("../comlib.php");		//使用資料庫的呼叫程式
   	include("../Connections/iotcnn.php");		//使用資料庫的呼叫程式
		//	Connection() ;
  	$link=Connection();		//產生mySQL連線物件

	$mid=$_GET["mac"];		//取得POST參數 : mac address
	//SELECT * FROM ncnuiot.dht where mac = 'CC50E38CEE18' order by systime desc limit 1
	$qrystr=sprintf("SELECT * FROM ncnuiot.dht where mac = '%s' order by systime desc limit 1 ",$mid) ;		//將dhtdata的資料找出來

	$d00 = array();		// declare blank array of d00
	$d01 = array();	// declare blank array of d01
	$d02 = array();	// declare blank array of d02
	$d03 = array();	// declare blank array of d03
	
	$result=mysql_query($qrystr,$link);		//將dhtdata的資料找出來(只找最後5
//	echo "step 02 . <br>" ;
  if($result!==FALSE){
	 while($row = mysql_fetch_array($result)) 
	 {
			array_push($d00, $row["systime"]);		// $row[欄位名稱] 就可以取出該欄位資料
			array_push($d01, $row["temperature"]);	// array_push(某個陣列名稱,加入的陣列的內容
			array_push($d02, $row["humidity"]);
			array_push($d03, $row["mac"]);
		}// 會跳下一列資料

  }
			
//	echo "step 03 . <br>" ;		
	 mysql_free_result($result);	// 關閉資料集
//	echo "step 04 . <br>" ;	 
	 mysql_close($link);		// 關閉連線
//	echo "step 05 . <br>" ;	 	




?>


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Frameset//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>DHT Sensor Guage Chart</title>
<link href="webcss.css" rel="stylesheet" type="text/css" />



<script src="/code/highcharts.js"></script>
<script src="/code/highcharts-more.js"></script>
<script src="/code/modules/exporting.js"></script>
<script src="/code/modules/export-data.js"></script>
<script src="/code/modules/accessibility.js"></script>


</head>
<body>
<?php
//include 'title.php';
?>

<div id="container1" style="min-width: 95%; height: 600px; margin: 0 auto"></div>
<p>
<div id="container2" style="min-width: 95%; height: 600px; margin: 0 auto"></div>
<p>


</form>
<?php
//include 'footer.php';
?>

<script type="text/javascript">

 //---------Color Temperaturte----------------
Highcharts.chart('container1', {

    chart: {
        type: 'gauge',
        plotBackgroundColor: null,
        plotBackgroundImage: null,
        plotBorderWidth: 0,
        plotShadow: false
    },

    title: {
        text: 'Temperature by MAC:<? echo $mid?> at <? echo trandatetime4($d00[0])?>',
    },

    pane: {
        startAngle: -120,
        endAngle: 120,
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
        min: -10,
        max: 50,

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
            step: 1,
            rotation: 'auto'
        },
        title: {
            text: '°C(Celsius)'
        },
        plotBands: [{
            from: -10,
            to: 22,
            color: '#DDDF0D' // yellow
        }, {
            from: 22,
            to: 30,
            color: '#55BF3B' // green
        }, {
            from: 30,
            to: 50,
            color: '#DF5353' // red
        }]
    },

    series: [{
        name: 'Celsius',
        data: [
		<?php
	for($i=count($d00)-1;$i >=0  ;$i=$i-1)
		{
			echo $d01[$i];
			echo ",";
		}
		?>		
		],
        tooltip: {
            valueSuffix: ' °C'
        }
    }]

});

 //---------Color humidity----------------
Highcharts.chart('container2', {

    chart: {
        type: 'gauge',
        plotBackgroundColor: null,
        plotBackgroundImage: null,
        plotBorderWidth: 0,
        plotShadow: false
    },

    title: {
        text: 'Humidity by MAC:<? echo $mid?> at <? echo trandatetime4($d00[0])?>',
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
        max: 100,

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
            step: 1,
            rotation: 'auto'
        },
        title: {
            text: '%(Percent)'
        },
        plotBands: [{
            from: 0,
            to: 50,
            color: '#55BF3B' //  green
        }, {
            from: 50,
            to: 85,
            color: '#DDDF0D' //yellow
        }, {
            from: 85,
            to: 100,
            color: '#DF5353' // red
        }]
    },

    series: [{
        name: 'humidity',
        data: [
		<?php
	for($i=count($d00)-1;$i >=0  ;$i=$i-1)
		{
			echo $d02[$i];
			echo ",";
		}
		?>		
		],
        tooltip: {
            valueSuffix: ' %'
        }
    }]

});



		</script>

</body>
</html>
