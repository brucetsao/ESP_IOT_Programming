<?php require_once('../Connections/connect.php');

 
   	
   	$link=Connection();		//產生mySQL連線物件

	$temp0=$_GET["field0"];		//取得POST參數 : field1
	$temp1=$_GET["field1"];		//取得POST參數 : field1
	$temp2=$_GET["field2"];		//取得POST參數 : field2
	$temp3=$_GET["field3"];		//取得POST參數 : field3
	

	$query = "INSERT INTO dhtdata (yyyymmdd,mac,celsius,fahrenheit,humidity) 
	VALUES ('".getYMD()."','".$temp0."',".$temp1.",".$temp2.",".$temp3.")"; 
	//組成新增到dhtdata資料表的SQL語法


  	echo $query ;

	mysql_query($query,$link);			//執行SQL語法
	mysql_close($link);		//關閉Query
	 
 
function getYMD(){
	$today = getdate();
	date("Y/m/d H:i");  //日期格式化
	$year=$today["year"]; //年 
	$month=$today["mon"]; //月
	$day=$today["mday"];  //日
 
	if(strlen($month)=='1')$month='0'.$month;
	if(strlen($day)=='1')$day='0'.$day;
	$today=$year.$month.$day;
	//echo "今天日期 : ".$today;
 
	return $today;
}
?>
