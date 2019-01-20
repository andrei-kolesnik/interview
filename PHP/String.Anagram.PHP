<?php
//Determine if two strings are anagrams
//IN:
//Two strings
//OUT:
//- true is if the two strings are anagrams
//- false otherwise

//==============================================================================
//VERSION 1: using sorting
function string_sort($str) {
    $str_arr = str_split(str_replace(' ', '', $str)); //we don't care about the spaces
    sort($str_arr);
    return implode('', $str_arr);
}

function string_anagram_sort($str1, $str2) {
    return string_sort($str1) == string_sort($str2);
}

//==============================================================================
//VERSION 2: using character map/count
function string_anagram_map1($str1, $str2) {
    $chars = count_chars(str_replace(' ', '', $str1)); //we don't care about the spaces
    foreach (str_split($str2) as $char)
    {
        if ($char !== ' ' && ord($char) !== 0) //we still don't care about the spaces
        {
            if ($chars[ord($char)] == 0) return false;
            $chars[ord($char)]--;
        }
    }
    return array_sum($chars) == 0;
}

$samples = array(
	array("", ""),
	array("forty five", "over fifty"),
	array("customers", "store scum"),
	array("determine if two strings", "are anagrams"),
);

foreach ($samples as $sample) {
    echo "{$sample[0]} | {$sample[1]} | " 
        . (string_anagram_sort($sample[0], $sample[1]) ? "Yes" : "No") . ' | '
        . (string_anagram_map1($sample[0], $sample[1]) ? "Yes" : "No") . ' | ' 
        . "\n";
}
