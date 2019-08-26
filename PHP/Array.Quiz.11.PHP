<?php
function getList($val)
{
    return is_array($val) ? $val : array($val);
}

function mergeByIndex($val1, $val2): array 
{
    $result = array();
    if (isset($val1))
        $result[] = $val1;
    if (isset($val2)) {
        if (is_scalar($val2))
           $result[] = $val2;
        else
            foreach ($val2 as $val) {
                $result[] = $val;
        }
    }
    return $result;
}


$array1 = array(array(77, 87), array(23, 45), 33, 44);
$array2 = array("w3resource", "com", "one more"); 

print_r(array_map('mergeByIndex', $array2, $array1));
