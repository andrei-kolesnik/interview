<?php

# a) ascending order sort by value
$arr = array("Sophia"=>"31","Jacob"=>"41","William"=>"39","Ramesh"=>"40");
asort($arr);
print_r($arr);

# b) ascending order sort by Key
$arr = array("Sophia"=>"31","Jacob"=>"41","William"=>"39","Ramesh"=>"40");
ksort($arr);
print_r($arr);

# c) descending order sorting by Value
$arr = array("Sophia"=>"31","Jacob"=>"41","William"=>"39","Ramesh"=>"40");
arsort($arr);
print_r($arr);

# d) descending order sorting by Key
$arr = array("Sophia"=>"31","Jacob"=>"41","William"=>"39","Ramesh"=>"40");
krsort($arr);
print_r($arr);
