<?php
   	include("../connect.php");		//使用資料庫的呼叫程式
	
   	
   	$link=Connection();		//產生mySQL連線物件

	$temp1=$_POST["humidity"];		//取得POST參數 : humidity
	$temp2=$_POST["temperature"];		//取得POST參數 : temperature


//	$query = "INSERT INTO `dhtdata` (`humidity`,`temperature`) VALUES ('".$temp1."','".$temp2."')"; 
	$query = "INSERT INTO `dhtdata` (`humidity`,`temperature`) VALUES (".$temp1.",".$temp2.")"; 
	//組成新增到dhtdata資料表的SQL語法




	mysql_query($query,$link);			//執行SQL語法
	mysql_close($link);		//關閉Query
	   	echo $query ;
 
?>
