<?php
/*
Count the number of 1-bits in the binary representation of a positive number.
*/
// Version 1: simple count
function countOneBitsSimple($val)
{
	$result = 0;
	while ($val)
	{
		$result += $val & 1;
		$val >>= 1;
	} 
	return $result;
}
// Version 2: Brian Kernighan’s Algorithm (https://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan)
function countOneBitsKernighan($val)
{
	$result = 0;
	while ($val)
	{
		$val &= $val - 1;
	    $result++;
	}
	return $result;
}

echo countOneBitsSimple(0), " | ", countOneBitsKernighan(0), "\n";
echo countOneBitsSimple(1), " | ", countOneBitsKernighan(1), "\n";
echo countOneBitsSimple(0b0111111111111111), " | ", countOneBitsKernighan(0b0111111111111111), "\n";
echo countOneBitsSimple(0b10101010), " | ", countOneBitsKernighan(0b10101010), "\n";
