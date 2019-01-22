<?php
/*
Find a pair with the given sum in an unsorted array
IN:
- An unsorted array
- A number
OUT:
- All the element pairs which sum equals to the given number
COMMENTS:
Sorting solution: complexity O(n*log(n)) / space O(1) (see the brute force solution in C#)
*/
function twoSum($nums, $target) {
    $result = array();
    sort($nums);
    $left = 0; 
    $right = count($nums) - 1;
    while ($left < $right)
    {
        $sum = $nums[$left] + $nums[$right];
        if ($sum == $target)
        {
            $result[0] = $left+1;
            $result[1] = $right+1;
            return $result;
        }
        if ($sum < $target) $left++;
        else $right--;
    }
    return $result;
}

print_r(twoSum([2, 7, 11, 15], 9));
print_r(twoSum([3, 7, 6, 2, 11, 5, 1, 4, 8, 9, 10], 12));
