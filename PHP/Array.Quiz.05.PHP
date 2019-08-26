<?php
$color = array(4 => 'white', 6 => 'green', 11 => 'red');

// method 1:
print($color[array_key_first($color)]);

// method 2:
print(reset($color));
