<?php
$temperatures = array(78, 60, 62, 68, 71, 68, 73, 85, 66, 64, 76, 63, 81, 76, 73, 68, 72, 73, 75, 65, 74, 63, 67, 65, 64, 68, 73, 75, 79, 73);

print("Average Temperature is : " . array_sum($temperatures) / count($temperatures) . "\n");

sort($temperatures);

print("List of five lowest temperatures : \n");
print_r(array_slice($temperatures, 0, 5));

print("List of five highest temperatures : \n");
print_r(array_slice($temperatures, -5, 5));