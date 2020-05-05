
<?php
 
   	include("../comlib.php");		//使用資料庫的呼叫程式
   	include("../Connections/iotcnn.php");		//使用資料庫的呼叫程式
		//	Connection() ;
  	$link=Connection();		//產生mySQL連線物件



	$qrystr="SELECT * FROM ncnuiot.dht order by mac,systime desc limit 0,120 " ;		//將dhtdata的資料找出來

	$d00 = array();		// declare blank array of d00
	$d01 = array();	// declare blank array of d01
	$d02 = array();	// declare blank array of d02
	$d03 = array();	// declare blank array of d03
	
	$result=mysql_query($qrystr,$link);		//將dhtdata的資料找出來(只找最後5

  if($result!==FALSE){
	 while($row = mysql_fetch_array($result)) 
	 {
			array_push($d00, $row["systime"]);		// $row[欄位名稱] 就可以取出該欄位資料
			array_push($d01, $row["temperature"]);	// array_push(某個陣列名稱,加入的陣列的內容
			array_push($d02, $row["humidity"]);
			array_push($d03, $row["mac"]);
		}// 會跳下一列資料

  }
			
	
	 mysql_free_result($result);	// 關閉資料集
 
	 mysql_close($link);		// 關閉連線





?>


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Frameset//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>DHT  Data List</title>
<link href="webcss.css" rel="stylesheet" type="text/css" />

</head>
<body>
<?php
//include 'title.php';
?>
  <div align="center">
   <table border="1" align = center cellspacing="1" cellpadding="1">		
		<tr>
			<td>MAC Address</td>
			<td>Date Time</td>
			<td>temperature</td>
			<td>humidity</td>
		</tr>

      <?php 
		  if(count($d00) >0)
		  {
				for($i=count($d00)-1;$i >=0  ;$i=$i-1)
					{
						echo sprintf("<tr><td>%s</td><td>%s</td><td>%f</td><td>%f</td></tr>", $d03[$i],
						  trandatetime4($d00[$i]), $d01[$i], $d02[$i]);
					 }
		 }
      ?>

   </table>

</div>

</form>
<?php
//include 'footer.php';
?>

</body>
</html>
