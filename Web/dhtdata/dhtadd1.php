<?php
   	include("../connect.php");		//使用資料庫的呼叫程式
	
   	
   	$link=Connection();		//產生mySQL連線物件

	$temp1=$_GET["humidity"];		//取得get參數 : humidity
	$temp2=$_GET["temperature"];		//取得get參數 : temperature
	

	$query = "INSERT INTO `dhtdata` (`humidity`,`temperature`) VALUES ('".$temp1."','".$temp2."')"; 
	//組成新增到dhtdata資料表的SQL語法
   	echo $query ;

?>
