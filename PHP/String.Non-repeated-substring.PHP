<?php
/*
Given a string, find the max size of the sub-string which has no duplicate characters.
*/
function getNonRepeatedSubstring($s) {
	$result = $left = $right = 0;
	$counter = array();
	while ($left < strlen($s))
	{
        $c = $s[$right];
		if (array_key_exists($c, $counter) == false)
		{
            $counter[$c] = true;
			if ($right + 1 >= strlen($s))
			{
				$result = max($result, $right + 1 - $left);
				break;
			}
			$right++;
		}
		else
		{
			$result = max($result, $right - $left);
            while ($left < strlen($s) && $s[$left] != $c)
                unset($counter[$s[$left++]]);
            if ($left < strlen($s))
                unset($counter[$s[$left++]]);
		}
	}
	return $result;
}

function check($str, $expected) {
	$actual = getNonRepeatedSubstring($str);
    echo 
        $str, ': ', 
        ($actual == $expected) ? "PASS" : "FAIL", 
        " ($actual/$expected)\n";
}

check("", 0);
check("a", 1); // "a"
check("aaaaaa", 1); // "a"
check("aaaaab", 2); // "ab"
check("abcdeacde", 5); // "abcde"
check("abacdefcde", 6); // "bacdef"
check("abcabaabccfdsaewer", 7); // "cfdsaew"
