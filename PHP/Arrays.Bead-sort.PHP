<?php
/*
Given an array, sort it using the bead sort sort algorithm
IN:
Unsorted array with n positive integer elements
Out:
Sorted array
*/

function rowsToColumns($arr)
{
    if (count($arr) == 0)
        return array();
    else if (count($arr) == 1)
        return array_chunk($arr[0], 1);

    // https://www.php.net/manual/en/function.array-map.php
    // An interesting use of array_map is to construct an array of arrays,
    // which can be easily performed by using NULL as the name of the callback function
    array_unshift($arr, NULL);
    $transpose = call_user_func_array('array_map', $arr);
    // Remove empty elements:
    return array_map('array_filter', $transpose);
}

function beadSort(Array $arr)
{
    $poles = array();
    foreach ($arr as $value)
        // Create rows with '1's for every number
        $poles[] = array_fill(0, $value, 1);
    // Convert rows to columns twice
    // Count '1's in every column of the result
    return array_map('count', rowsToColumns(rowsToColumns($poles)));
}

$arr = Array(
    0 => 5,
    1 => 3,
    2 => 1,
    3 => 3,
    4 => 8,
    5 => 7,
    6 => 4,
    7 => 1,
    8 => 1,
    9 => 3);

print_r(beadSort($arr));
