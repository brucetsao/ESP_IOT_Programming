<?php
	function Connection() 
	{

		$server="localhost";
		$user="ncnuiot";
		$pass="iot12345";
		$db="ncnuiot";
   		//echo "cnn is ok 01"."<br>" ;	   	
		$connection = mysql_pconnect($server, $user, $pass);
   		//echo "cnn is ok 02"."<br>" ;	   	

		if (!$connection) {
	    	die('MySQL ERROR: ' . mysql_error());
		}
		
   		//echo "cnn is ok 03"."<br>" ;	   	
		mysql_select_db($db) or die( 'MySQL ERROR: '. mysql_error() );
   		//echo "cnn is ok 04"."<br>" ;	   	
		mysql_query("SET NAMES UTF8");
   		//echo "cnn is ok 05"."<br>" ;	   	
		session_start();
   		//echo "cnn is ok 06"."<br>" ;	   	
	
		return $connection  ;	
	}
	
?>