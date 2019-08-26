<?php
$str = "082307";

// 1: substr
echo substr($str, 0, 2) . ":" . substr($str, 2, 2) . ":" . substr($str, 4, 2) . "\n";

// 2: str_split + implode
echo implode(":", str_split($str, 2)) . "\n";

//3: chunk_split + substr to cut the last character off
echo substr(chunk_split($str, 2, ":"), 0, -1) . "\n";