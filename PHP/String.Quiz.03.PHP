<?php
$haystack = 'The quick brown fox jumps over the lazy dog.';
$needle = 'The';

echo strpos($haystack, $needle) !== false ? "YES" : "NO";