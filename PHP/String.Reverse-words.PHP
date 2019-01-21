<?php
/*
Reverse the words in a string. Include the punctuation as the part of the words.
IN: 
A string
OUT:
The string with the words in the reversed order
*/

function ReverseWords($str) {
    return implode(" ", array_reverse(explode(" ", $str)));
}

echo ReverseWords(""), "\n";
echo ReverseWords("Hello!"), "\n";
echo ReverseWords("Hello?  World!"), "\n";
echo ReverseWords("Hello - world, it’s a so-so day..."), "\n";
