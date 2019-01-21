<?php
/*
Find the first non-repeated character in a string
*/
//VERSION 1: using two arrays
function getFirstNonRepeatedCharArray($str) {
    if (strlen($str) == 0) //str_split of an empty string will have one element in the return array, unfortunately
        return ' ';
    $repeated = array();
    $non_repeated = array();
    foreach (str_split($str) as $ch) {
        if (in_array($ch, $repeated)) continue;
        $pos = array_search($ch, $non_repeated);
        if ($pos !== false)
        {
            unset($non_repeated[$pos]);
            $repeated[] = $ch;
        }
        else 
            $non_repeated[] = $ch;
    }
    if (count($non_repeated) > 0)
    {
        reset($non_repeated); //reseting, because the first element might not be at index 0
        return current($non_repeated); 
        //alternative: array_values($non_repeated)[0];
    }
    else
        return ' ';
}
//VERSION 2: using character map/count
function getFirstNonRepeatedCharMap($str) {
    if (strlen($str) == 0) 
        return ' ';
    $map = count_chars($str);
    foreach (str_split($str) as $ch) 
        if ($map[ord($ch)] == 1)
            return $ch;
    return ' ';
}

function check($str, $expected) {
    $actual1 = getFirstNonRepeatedCharArray($str);
    $actual2 = getFirstNonRepeatedCharMap($str);
    echo 
        $str, ': ', 
        ($actual1 == $expected && $actual2 == $expected) ? "PASS" : "FAIL", 
        " ($actual1/$actual2/$expected)\n";
}

check('abcdeacdef', 'b');
check('abcdeabcde', ' ');
check('', ' ');
