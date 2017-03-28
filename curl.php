<?php
$value =  $_POST ['value'];   //take the value of "value" field
$from = $_POST['from'];       //take the value of "from" field
$ip = $_SERVER['REMOTE_ADDR']; //the client's IP address
echo "Your value = ".$value." from=".$from.".And your IP address is ".$ip."\n";
$today=date("Y-m-d H:i:s");  //current time
$file = "curltest.log";   //the log file name
if(file_exists($file)){
	$fp = fopen($file, "a");   //open the file in appending mode
}
else{
	$fp = fopen($file, "w");   //open the file in writing ,mode
}
//prepare a line of record to write to the file, in CSV format
$record = $today . "," . $from . "," . $ip . "," . $value . "\n";
fwrite($fp, $record);         //write to file
fclose($fp);   //close the open file

?>