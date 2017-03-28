<?php
$log_file = 'sound_log.txt';  //log file name
$data = $_POST['data'];
$today=date("Y-m-d H:i:s");  //current time
$str = gmdate("M d Y H:i:s",time()).', '.$data."\n";  //two fields in one record,the timestamp and postdata
//echo "This is from the server";
//now we open the file
if(file_exists($log_file)){
	$fp=fopen($log_file,"a");   //the file is opened as append mode
	fwrite($fp, $str);   //write current value(postdata with time stamp)
	fclose($fp);   
}else{   //the file doesn't exist,so open a new one.
	$fp = fopen($log_file,"w");
	fwrite($fp, $str);
	fclose($fp);
}
echo "Data is stored\n";   //echo something back to the raspberry pi
?>