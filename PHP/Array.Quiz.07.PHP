<?php
function insertIntoArray($arr, $item, $position)
{
    return array_merge(array_slice($arr, 0, $position), array($item), array_slice($arr, $position));
}

$arr = array(1, 2, 3, 4, 5);
print_r(insertIntoArray($arr, '$', 3));
