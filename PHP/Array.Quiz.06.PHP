<?php

function printKeyValue($value, $key)
{
    echo "$key : $value"."\n";
}

$jsonStr = '{"Title": "The Cuckoos Calling",
"Author": "Robert Galbraith",
"Detail": {
"Publisher": "Little Brown"
}}';
$jsonArray = json_decode($jsonStr, true);
array_walk_recursive($jsonArray, "printKeyValue");
