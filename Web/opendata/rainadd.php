<?php
   	include('../Connections/iot.php');	//使用資料庫的呼叫程式
		//	Connection() ;
   	
  	 mysql_select_db($database_iot, $iot);

	$s01=$_GET["f01"];		//取得POST參數 : roomid
	$s02=$_GET["f02"];		//取得POST參數 : roomid
	$s03=$_GET["f03"];		//取得POST參數 : roomid
	$s04=$_GET["f04"];		//取得POST參數 : roomid
	$s05=$_GET["f05"];		//取得POST參數 : roomid
	$s06=$_GET["f06"];		//取得POST參數 : roomid
	$s07=$_GET["f07"];		//取得POST參數 : roomid
	$s08=$_GET["f08"];		//取得POST參數 : roomid
	$s09=$_GET["f09"];		//取得POST參數 : roomid
	$s10=$_GET["f10"];		//取得POST參數 : roomid
	$s11=$_GET["f11"];		//取得POST參數 : roomid
	$s12=$_GET["f12"];		//取得POST參數 : roomid
	$s13=$_GET["f13"];		//取得POST參數 : roomid
	$s14=$_GET["f14"];		//取得POST參數 : roomid
	$s15=$_GET["f15"];		//取得POST參數 : roomid
	$s16=$_GET["f16"];		//取得POST參數 : roomid
	$sysdt = getdatetime() ;
	$ddt = getdataorder() ;
	$ddt2 = getdataorder2() ;

//http://163.22.24.51:9999/opendata/rainadd.php?f01='C0C630'&f02='大溪'&f03='2020-03-03 22:00:00'&f04=24.884722&f05=121.256944&f06=209.0&f07=64&f08=1.2&f09=18.1&f10=8.4&f11=995.5&f12=0.0&f13='08'&f14='桃園市'&f15='060'&f16='大溪區'

//INSERT INTO iot.mosenvironment (dataorder, sid, sname, sdatetime, lat, lon, hight, wdir, wspeed, temp, humid, bar, rain, cid, cname, tid, tname) VALUES ('20200303222843', 'C0C630', '大溪', '2020-03-03 22:00:00', 24.884722, 121.256944, 209, 64, 1.200000, 18.100000, 8.400000, 995.500000, 0, '08', '桃園市', '060', '大溪區')

//INSERT INTO `mosenvironment` (`id`, `sysdatetime`, `dataorder`, `sid`, `sname`, `sdatetime`, `lat`, `lon`, `hight`, `wdir`, `wspeed`, `temp`, `humid`, `bar`, `rain`, `cid`, `cname`, `tid`, `tname`) VALUES (NULL, CURRENT_TIMESTAMP, '20200302114601', '01', '02', '2020-03-03 05:00:00', '03', '04', '05', '06', '07', '08', '09', '10', '11', '12', '13', '14', '15');
//	$query = "INSERT INTO `dhtdata` (`dataorder`,`temperature`) VALUES ('".$temp1."','".$temp2."')"; 
//	$query = sprintf("INSERT INTO iot.mosenvironment (dataorder, sid, sname, sdatetime, lat, lon, hight, wdir, wspeed, temp, humid, bar, rain, cid, cname, tid, tname) VALUES ('%s', %s, %s, %s, %f, %f, %d, %d, %f, %f, %f, %f, %d, %s, %s, %s, %s)",$ddt,$s01,$s02,$s03,$s04,$s05,$s06,$s07,$s08,$s09,$s10,$s11,$s12,$s13,$s14,$s15,$s16);
	$query = sprintf("INSERT INTO ncnuiot.environment (dataorder, sid, sname, sdatetime, lat, lon, hight, wdir, wspeed, temp, humid, bar, rain, cid, cname, tid, tname) VALUES ('%s', %s, %s, %s, %f, %f, %d, %d, %f, %f, %f, %f, %d, %s, %s, %s, %s)",$ddt,$s01,$s02,$s03,$s04,$s05,$s06,$s07,$s08,$s09,$s10,$s11,$s12,$s13,$s14,$s15,$s16);
	$query2 = sprintf("update ncnuiot.cwbsite set dataorder = '%s', lat= %f, lon = %f, sdatetime = %s, hight = %d , wdir = %d , wspeed = %f, temp = %f, humid = %f, bar = %f, rain = %f  where sid = %s",$ddt,$s04,$s05,$s03,$s06,$s07,$s08,$s09,$s10,$s11,$s12,$s01);


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

	if (mysql_query($query2,$iot))
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
	   	echo "<br>" ;
	   	echo $query2 ;
	   	echo "<br>" ;

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