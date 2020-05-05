<?php
   	include('../Connections/iot.php');	//使用資料庫的呼叫程式
		//	Connection() ;
   	
  	 mysql_select_db($database_iot, $iot);

	$s01=$_GET["f01"];		//取得POST參數 : sid
//	$s02=$_GET["f02"];		//取得POST參數 : sname
	$s03=$_GET["f03"];		//取得POST參數 : sdatetime
	$s04=$_GET["f04"];		//取得POST參數 : lat
	$s05=$_GET["f05"];		//取得POST參數 : lon
	$s06=$_GET["f06"];		//取得POST參數 : hight
	$s07=$_GET["f07"];		//取得POST參數 : wdir
	$s08=$_GET["f08"];		//取得POST參數 : wspeed
	$s09=$_GET["f09"];		//取得POST參數 : temp
	$s10=$_GET["f10"];		//取得POST參數 : humid
	$s11=$_GET["f11"];		//取得POST參數 :bar
	$s12=$_GET["f12"];		//取得POST參數 : rain
	$s13=$_GET["f13"];		//取得POST參數 : cid
//	$s14=$_GET["f14"];		//取得POST參數 : cname
	$s15=$_GET["f15"];		//取得POST參數 : tid
//	$s16=$_GET["f16"];		//取得POST參數 : tname
	$sysdt = getdatetime() ;
	$ddt = getdataorder() ;
	$ddt2 = getdataorder2() ;

//http://mosquitotrap.nhri.org.tw/opendata/rainadd.php?f01=%27C0A560%27&f02=%27%E7%A6%8F%E5%B1%B1%27&f03=%272020-03-03%2010:00:00%27&f04=24.778333&f05=121.494583&f06=405.0&f07=148&f08=1.4&f09=20.1&f10=71&f11=975.1&f12=0.0&f13=%2706%27&f14=%27%E6%96%B0%E5%8C%97%E5%B8%82%27&f15=%27061%27&f16=%27%E7%83%8F%E4%BE%86%E5%8D%80%27

//	$query = sprintf("INSERT INTO iot.mosenvironment (dataorder, sid, sname, sdatetime, lat, lon, hight, wdir, wspeed, temp, humid, bar, rain, cid, cname, tid, tname) VALUES ('%s', %s, %s, %s, %f, %f, %d, %d, %f, %f, %f, %f, %d, %s, %s, %s, %s)",$ddt,$s01,$s02,$s03,$s04,$s05,$s06,$s07,$s08,$s09,$s10,$s11,$s12,$s13,$s14,$s15,$s16);
	$query = sprintf("INSERT INTO iot.mosenvironment (dataorder,sid,sdatetime,lat,lon,hight,wdir,wspeed,temp,humid, bar, rain, cid, tid) VALUES ('%s','%s','%s',%f,%f,%d,%d,%f,%f,%f,%f,%d,'%s', '%s')",$ddt,$s01,$s03,$s04,$s05,$s06,$s07,$s08,$s09,$s10,$s11,$s12,$s13,$s15);
//	$query = "INSERT INTO `dhtdata` (`dataorder`,`temperature`) VALUES ('".$temp1."','".$temp2."')";  
	//組成新增到dhtdata資料表的SQL語法

/// http://iot.nhri.org.tw/ict/ictadd.php?mac=123412345678&f0=1&f1=88&f2=35.3&f3=65.3&f4=23&f5=677&f6=876&f7=1&f8=0
// sample


	if (mysql_query($query,$iot))
		{
				echo "Successful <br>" ;
		}
		else
		{
				echo "Fail <br>" ;
		}
		
			;			//執行SQL語法
	echo "<br>" ;

	mysql_close($iot);		//關閉Query
	
	   	echo $query ;

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

			return ($yyyy.$mm.$dd.$hh.$min.$sec)  ;
         }
		

      ?>