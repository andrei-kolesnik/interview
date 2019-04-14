<?php
/*
Given an array, sort it using the merge sort algorithm
IN:
Unsorted array with n elements
Out:
Sorted array
*/

function print_array($arr, $start, $end) {
    for($i = $start; $i <= $end; $i++)
        echo "{$arr[$i]} ";
}

function merge(&$arr, $first, $middle, $last) { // in-place version
//##debug    echo "$first/$middle/$last: "; print_array($arr, $first, $last); echo " - ";
    $left = $first;
    $right = $middle + 1;
	//extra optional step: maybe everything happens to be already sorted and we can skip the merge
	if ($arr[$middle] <= $arr[$right]) 
        return;
    while($left <= $middle && $right <= $last)
    {
        if ($arr[$left] <= $arr[$right]) //selecting from $left: no swap, just advance $left
            $left++;
        else //selecting from $right: rotate one step to the $right
        {
            $swap = $arr[$right];
            for ($i = $right; $i > $left; $i--)
                $arr[$i] = $arr[$i - 1];
            $arr[$left] = $swap;
            $left++; $middle++; $right++;
        }
    }
    // Whatever remains in [$right..$last] is in place
//##debug    print_array($arr, $first, $last); echo "\n";
}

function mergeSort(&$arr, $left, $right) {
    if ($left < $right)
    {
        $middle = (int)(($left + $right) / 2);
        mergeSort($arr, $left, $middle);
        mergeSort($arr, $middle + 1, $right);
        merge($arr, $left, $middle, $right);
    }
}

$arr = array(5, 2, 4, 7, 1, 3, 2, 6);

mergeSort($arr, 0, count($arr) - 1);

echo(implode(" ", $arr) . "\n");
