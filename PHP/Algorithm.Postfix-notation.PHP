<?php
/*
Parse and calculate an arithmetic expression in Reverse Polish / postfix notation
IN: 
- an expression in postfix notation
OUT:
- the expression result
*/
function postfix($s) {
    if (strlen($s) == 0)
        return 0;
    $OpStack = new \Ds\Stack();
	$result = 0;
    foreach (explode(" ", $s) as $op)
	{
		if (strpos('+-*/', $op) !== false)
		{
			$op2 = $OpStack->pop();
			$op1 = $OpStack->pop();
            switch ($op) 
            {
                case '+': $result = $op1 + $op2; break;
                case '-': $result = $op1 - $op2; break;
                case '*': $result = $op1 * $op2; break;
                case '/': $result = $op1 / $op2; break;
			}
		}
		else
			$result = (int)$op;
		$OpStack->push($result);
	}
	return $OpStack->pop();
}

function check($str, $expected) {
	$actual = postfix($str);
    echo 
        $str, ': ', 
        ($actual == $expected) ? "PASS" : "FAIL", 
        " ($actual/$expected)\n";
}

check('3 4 +', 7);
check('5 2 -', 3);
check('3 5 *', 15);
check('15 5 /', 3);
check('15 7 1 1 + - / 3 * 2 1 1 + + -', 5);
