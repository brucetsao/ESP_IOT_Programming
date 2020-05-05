<?php
# FileName="Connection_php_mysql.htm"
# Type="MYSQL"
# HTTP="true"

$hostname_iot = "localhost";
$database_iot = "ncnuiot";
$username_iot = "ncnuiot";
$password_iot = "iot12345";
$iot = mysql_pconnect($hostname_iot, $username_iot, $password_iot) or trigger_error(mysql_error(),E_USER_ERROR); 
		mysql_query("SET NAMES UTF8");
		session_start();
		mysql_select_db($database_iot, $iot);		
?>