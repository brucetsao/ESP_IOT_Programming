<?php
//echo $datastr ; 
//echo "<br>" ;




$link=Connection();	

//			$mosstr =  "SELECT a.id as tid, b.id as tid,a.type as type , count(a.type) as cnt , a.mac as mac, b.deviceid as did, b.devicename as dname, b.deviceaddr as addr , b.latitude as latitude, b.longitude as longitude, b.areaid as aid  FROM mosdata as a , mosdevice as b WHERE a.mac = b.mac group by a.type,a.mac order by b.deviceid desc"  ;	
//SELECT a.id as tid, b.id as tid,count(a.mac) as cnt , a.mac as mac, b.deviceid as did, b.devicename as dname, b.deviceaddr as addr , b.latitude as latitude, b.longitude as longitude, b.areaid as aid  FROM mosdata as a , mosdevice as b WHERE a.mac = b.mac and a.type = 'AEDES' group by a.mac order by b.deviceid desc
				$resultzz=mysql_query($datastr,$link);		
				$num_rows = mysql_num_rows($resultzz);		
			echo "{\n\t\"type\": \"FeatureCollection\",\n\t\"features\": \n[";
			$count= 1 ;
	  if($num_rows >0)
		{
			while($row = mysql_fetch_array($resultzz)) 
			{
			// pm2.5
				$tt = sprintf("\"title\": \"Particle Type:PM25 <br> <br>Device ID:%s<br>NameD:%s<br>Mac:%s<br>Values: %d<br>GPS:[%f,%f]<br>Address:%s\"",$row['did'],$row['dname'],$row['mac'],$row['pm25'],$row['longitude'],$row['latitude'],$row['addr']) ;
				$tmp = sprintf("\n\t{\n\t\t\"type\": \"Feature\",\n\t\t\"properties\": {\n\t\t\t\"amount\": %d ,\n\t\t\t %s ,\n\t\t\t\"species\": \"%s\"\t\t},\n\t\t\"geometry\": {\n\t\t\t\"type\": \"Point\",\n\t\t\t\"coordinates\": [%f, %f]\n\t\t}\n\t}",$row['pm25'],$tt,'PM25',$row['longitude'],$row['latitude']);
				echo $tmp.",\n" ;
			// pm1.0
				$tt = sprintf("\"title\": \"Particle Type:PM1.0 <br> <br>Device ID:%s<br>NameD:%s<br>Mac:%s<br>Values: %d<br>GPS:[%f,%f]<br>Address:%s\"",$row['did'],$row['dname'],$row['mac'],$row['pm1'],$row['longitude'],$row['latitude'],$row['addr']) ;
				$tmp = sprintf("\n\t{\n\t\t\"type\": \"Feature\",\n\t\t\"properties\": {\n\t\t\t\"amount\": %d ,\n\t\t\t %s ,\n\t\t\t\"species\": \"%s\"\t\t},\n\t\t\"geometry\": {\n\t\t\t\"type\": \"Point\",\n\t\t\t\"coordinates\": [%f, %f]\n\t\t}\n\t}",$row['pm1'],$tt,'PM1',$row['longitude'],$row['latitude']);
				echo $tmp.",\n" ;
			// pm10
				$tt = sprintf("\"title\": \"Particle Type:PM10 <br> <br>Device ID:%s<br>NameD:%s<br>Mac:%s<br>Values: %d<br>GPS:[%f,%f]<br>Address:%s\"",$row['did'],$row['dname'],$row['mac'],$row['pm10'],$row['longitude'],$row['latitude'],$row['addr']) ;
				$tmp = sprintf("\n\t{\n\t\t\"type\": \"Feature\",\n\t\t\"properties\": {\n\t\t\t\"amount\": %d ,\n\t\t\t %s ,\n\t\t\t\"species\": \"%s\"\t\t},\n\t\t\"geometry\": {\n\t\t\t\"type\": \"Point\",\n\t\t\t\"coordinates\": [%f, %f]\n\t\t}\n\t}",$row['pm10'],$tt,'PM10',$row['longitude'],$row['latitude']);
				echo $tmp ;
				if ($count < $num_rows)
					{
							$tmp = ",\n";
							echo $tmp ;
					}
				$count= $count +1	; 
			//	echo "<br>" ;		
			}
			// write tailer
			echo "\n\t]\n}";
			
			 mysql_free_result($resultzz);
		}						

?>