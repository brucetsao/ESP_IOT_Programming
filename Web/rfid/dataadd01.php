<?php 

   	include("../Connections/iotcnn.php");		//使用資料庫的呼叫程式
		//	Connection() ;
   	
   	$link=Connection();		//產生mySQL連線物件
	mysqli_select_db($link, "iot") ;

	$temp1=$_GET["mac"];		//取得POST參數 : field1
	$temp2=$_GET["card"];		//取得POST參數 : field1

	$dt = getdatetime() ;	//取得POST參數 : field3
	
//INSERT INTO `rfidreader` (`id`, `crtdatetime`, `mac`, `cardnumber`, `inputdatetime`) VALUES (NULL, current_timestamp(), 'aabbccddeeff', '0123456789', '2019-11-28 06:12:28');
//2019-11-22 20:03:55

	$query = "INSERT INTO rfidreader01 (mac,cardnumber,inputdatetime) 
	VALUES ('".$temp1."','".$temp2."','".$dt."')"; 
	//組成新增到dhtdata資料表的SQL語法
//http://192.168.99.200/iot/rfid/dataadd.php?mac=aabbccddeeff&card=0123456789
//http://192.168.99.200/iot/rfid/dataadd.php?mac=aabbccddeeff&card=0345678134
// host is  ==>192.168.99.200
//  app program is ==> /iot/dht/dataadd.php
//  App parameters ==> ?mac=aabbccddeeff&t=23&h=88


	echo $query ;
	echo "<br>" ;
    

	if (mysqli_query($link,$query))
		{
				echo "Successful <br>" ;
		}
		else
		{
				echo "Fail <br>" ;
		}
		
			;			//執行SQL語法
	echo "<br>" ;
	mysqli_close($link);		//關閉Query
 
	?> 
 
 
   <?php
         /* Defining a PHP Function */
         function getdataorder() {
           $dt = getdate() ;
				$yyyy =  str_pad($dt['year'],4,"0",STR_PAD_LEFT);
				$mm  =  str_pad($dt['mon'] ,2,"0",STR_PAD_LEFT);
				$dd  =  str_pad($dt['mday'] ,2,"0",STR_PAD_LEFT);
				$hh  =  str_pad($dt['hours'] ,2,"0",STR_PAD_LEFT);
				$min  =  str_pad($dt['minutes'] ,2,"0",STR_PAD_LEFT);
				$sec  =  str_pad($dt['seconds'] ,2,"0",STR_PAD_LEFT);

			return ($yyyy.$mm.$dd.$hh.$min.$sec)  ;
         }
         function getdataorder2() {
           $dt = getdate() ;
				$yyyy =  str_pad($dt['year'],4,"0",STR_PAD_LEFT);
				$mm  =  str_pad($dt['mon'] ,2,"0",STR_PAD_LEFT);
				$dd  =  str_pad($dt['mday'] ,2,"0",STR_PAD_LEFT);
				$hh  =  str_pad($dt['hours'] ,2,"0",STR_PAD_LEFT);
				$min  =  str_pad($dt['minutes'] ,2,"0",STR_PAD_LEFT);

			return ($yyyy.$mm.$dd.$hh.$min)  ;
         }
         function getdatetime() {
           $dt = getdate() ;
				$yyyy =  str_pad($dt['year'],4,"0",STR_PAD_LEFT);
				$mm  =  str_pad($dt['mon'] ,2,"0",STR_PAD_LEFT);
				$dd  =  str_pad($dt['mday'] ,2,"0",STR_PAD_LEFT);
				$hh  =  str_pad($dt['hours'] ,2,"0",STR_PAD_LEFT);
				$min  =  str_pad($dt['minutes'] ,2,"0",STR_PAD_LEFT);
				$sec  =  str_pad($dt['seconds'] ,2,"0",STR_PAD_LEFT);

			return ($yyyy."/".$mm."/".$dd." ".$hh.":".$min.":".$sec)  ;
         }
		
		

      ?>
