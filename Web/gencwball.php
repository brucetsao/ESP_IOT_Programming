<?php
//echo $datastr ; 
//echo "<br>" ;




$link1=Connection();	

//			$mosstr =  "SELECT a.id as tid, b.id as tid,a.type as type , count(a.type) as cnt , a.mac as mac, b.deviceid as did, b.devicename as dname, b.deviceaddr as addr , b.latitude as latitude, b.longitude as longitude, b.areaid as aid  FROM mosdata as a , mosdevice as b WHERE a.mac = b.mac group by a.type,a.mac order by b.deviceid desc"  ;	
//SELECT a.id as tid, b.id as tid,count(a.mac) as cnt , a.mac as mac, b.deviceid as did, b.devicename as dname, b.deviceaddr as addr , b.latitude as latitude, b.longitude as longitude, b.areaid as aid  FROM mosdata as a , mosdevice as b WHERE a.mac = b.mac and a.type = 'AEDES' group by a.mac order by b.deviceid desc
				$resultzz1=mysql_query($datastr1,$link1);		
				$num_rows1 = mysql_num_rows($resultzz1);		
			echo "{\n\t\"type\": \"FeatureCollection\",\n\t\"features\": \n[";
			$count= 1 ;
	  if($num_rows1 >0)
		{
			while($row1 = mysql_fetch_array($resultzz1)) 
			{
				$tt = sprintf("\n{\n\t\"type\": \"Feature\",\n\t\"geometry\": {\n\t\t\"type\": \"Point\",\n\t\t\"coordinates\": [%f,%f]\n\t},\n\t\"properties\":\n\t{\n\t\t\"height\": %d ,\n\t\t\"wdir\": %d ,\n\t\t\"wspeed\": %d ,\n\t\t\"temp\": %f ,\n\t\t\"humid\": %f ,\n\t\t\"bar\": %f ,\n\t\t\"rain\": %f \n\t}\n}",$row1['lon'],$row1['lat'],$row1['height'],$row1['wdir'],$row1['wspeed'],$row1['temp'],$row1['humid'],$row1['bar'],$row1['rain']);

/*

{
	"type": "Feature",
	"geometry": 
	{
		"type": "Point",
		"coordinates": [21.923578,120.727792]
	},
	"properties":
	{
		"height": 0 ,
		"wdir": 69 ,
		"wspeed": 4 ,
		"temp": 24.300000 ,
		"humid": 5.700000 ,
		"bar": 1017.400000 ,
		"rain": 0.000000 
	}
}
*/

			//	echo $tmp ;
			//	echo "/" ;
			//	echo $tt ;
			//	echo "<br>" ;
				echo $tt ;
				if ($count < $num_rows1)
					{
							$tmp = ",\n";
							echo $tmp ;
					}
				$count= $count +1	; 
			//	echo "<br>" ;		
			}
			// write tailer
			echo "\n\t]\n}";
			
			 mysql_free_result($resultzz1);
		}						

?>