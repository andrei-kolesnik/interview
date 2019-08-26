<?php
// method 1:
$x = array(1, 2, 3, 4, 5);
print_r($x);
unset($x[3]);
#$x = array_values($x);
print_r($x);

// method 2:
$x = array(1, 2, 3, 4, 5);
print_r($x);
array_splice($x, 3, 1);
print_r($x);
