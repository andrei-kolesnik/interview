<?php
/*
Implement a binary search for the integer in a sorted array
IN:
A sorted array, the element to search for
OUT: 
The position of the element in the array, or -1 if not found
*/

define('NOT_FOUND', -1);

function array_binary_search($needle, $haystack, $left = 0, $right = NULL) {
    if (!isset($right)) $right = count($haystack) - 1;
    if ($right < $left) return NOT_FOUND;
    if ($right == $left) return $haystack[$left] == $needle ? $left : NOT_FOUND;
    $middle = (int)(($right + $left) / 2);
    if ($haystack[$middle] ==  $needle) return $middle;
    if ($haystack[$middle] > $needle)
        return array_binary_search($needle, $haystack, $left, $middle - 1);
    else
        return array_binary_search($needle, $haystack, $middle + 1, $right);
}

$arr = array(1, 2, 3, 4, 6, 7, 8, 9, 11);
foreach ($arr as $value) {
    $pos = array_binary_search($value, $arr);
    echo "$value: $pos\n";
}
