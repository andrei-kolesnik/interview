<?php
function array_to(array $arr, string $str): array
{
    return array_map(ctype_upper($str[0]) ? 'strtoupper' : 'strtolower', $arr);
}

$Color = array('A' => 'Blue', 'B' => 'Green', 'c' => 'Red');
print_r(array_to($Color, 'Upper'));
print_r(array_to($Color, 'l'));
