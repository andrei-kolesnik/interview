<?php
/*
Given an array, sort it using the quick sort alrorithm
IN:
Unsorted array with n elements
Out:
Sorted array
*/
/*
//swap: Version 1: array by reference + indexes
function swap(&$arr, $a, $b) {
    if ($a !== $b)
    {
        $swap = $arr[$a];
        $arr[$a] = $arr[$b];
        $arr[$b] = $swap;
    }
}
//swap version 2: array elements by reference
function swap(&$a, &$b) {
    if ($a !== $b)
    {
        $swap = $a;
        $a = $b;
        $b = $swap;
    }
}
*/

function partition(&$arr, $left, $right) {
    $pos = $left;
    $pivot = $arr[$right];
    for ($i = $left; $i < $right; $i++)
    {
        if ($arr[$i] < $pivot) 
        {
            [$arr[$i], $arr[$pos]] = [$arr[$pos], $arr[$i]]; // swap: Version 3: PHP 7.1 syntax
//            list($arr[$i], $arr[$pos]) = [$arr[$pos], $arr[$i]]; // swap: Version 4: pre-PHP 7.1 syntax
//            swap($arr[$i], $arr[$pos]);
//            swap($arr, $i, $pos);
            $pos++;
        }
    }
    [$arr[$right], $arr[$pos]] = [$arr[$pos], $arr[$right]];
//    swap($arr[$right], $arr[$pos]);
//    swap($arr, $right, $pos);
    return $pos;
}

function quickSort(&$arr, $left, $right) {
    if ($left < $right)
    {
        $pos = partition($arr, $left, $right); // the element at $pos is already at its place
        quickSort($arr, $left, $pos - 1); // everything on the left of $pos is smaller, we can quick sort it
        quickSort($arr, $pos + 1, $right); // everything on the right of $pos is bigger, we can quick sort it as well
    } 
}

$arr = array(5, 2, 4, 7, 1, 3, 2, 6);

quickSort($arr, 0, count($arr) - 1);

echo(implode(" ", $arr) . "\n");
