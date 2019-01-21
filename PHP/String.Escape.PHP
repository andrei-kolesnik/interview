<?php
/*
Escape all % characters in a string with % as the escape character
IN:
A string with % characters
OUT:
The same string with all the % characters escaped with another % character
*/

function string_escape($str) {
    $result = "";
    foreach (str_split($str) as $ch) {
        if ($ch == '%') $result .= $ch;
        $result .= $ch;
    }
    return $result;
}

$strs = array(
		"", //empty case
		"Nothing to escape here",
		"~75% of all students have loan debt",
		"5% + 5% = 10%",
		"set PATH=c:\\;%PATH%",
		"WHERE comment LIKE '%10%%%'",
		"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" //extreme case
);

foreach($strs as $str)
    echo $str, " -> ", string_escape($str), "\n";
