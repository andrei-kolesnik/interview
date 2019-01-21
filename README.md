# Data Structures and Algorithms interview questions and their solutions
Data Structures and Algorithms interview questions and their solutions.

(Problems from [LeetCode](https://github.com/andrei-kolesnik/leetcode) and [HackerRank](https://github.com/andrei-kolesnik/hackerrank) can be found in their respective repositories.)

## Arrays

### Binary Search [[C++]](Array.Binary-search.CPP) [[PHP]](PHP/Array.Binary-search.PHP)
Implement a binary search for the integer in a sorted array.

### Find a Pair 
Find a pair with the given sum in an unsorted array.
* Version 1: brute force [[C#]](Array.Find-pair.NET) 
* Version 2: sorting & iterators [[C++ STL]](Array.Find-pair.STL)

### Missing Element [[C++]](Array.Missing-element.CPP)
Find a missing element in a randomized sequence.

### Duplicated Element [[C++]](Array.Duplicated-element.CPP)
Given an array of n + 1 integers between 1 and n, find one of the duplicates.
* Version 1: brute force
* Version 2: using a map/counters
* Version 3: using the sum of the elemets
* Version 4: using +/- markers
* Version 5: looking for a loop

### Merge Sort [[C++]](Array.Merge-sort.CPP) [[PHP]](PHP/Array.Merge-sort.PHP)
Sort an array using the merge sort alrorithm.
* Version 1: straightforward merge
* Version 2: merge using extra sentinel elements
* Version 3: merge in place
* Version 4: library `inplace_merge`

### Merge Sorted [[C++ STL]](Array.Sorted-merge.STL)
Merge two sorted arrays.

### Quick Sort [[C++]](Array.Quick-sort.CPP) [[PHP]](PHP/Array.Quick-sort.PHP)
Sort an array using the quick sort alrorithm.


---

## Strings

### Anagram [[C++ STL]](String.Anagram.STL) [[PHP]](PHP/String.Anagram.PHP)
Determine if two strings are anagrams 
* Version 1: sorting
* Version 2: character map

### Escaping [[C++]](String.Escape.CPP) [[PHP]](PHP/String.Escape.PHP)
Escape all % characters in a string with % as the escape character.

### Non-repeated Character [[C++ STL]](String.Non-repeated-character.STL) [[PHP]](PHP/String.Non-repeated-character.PHP)
Find the first non-repeated character in a string 
* Version 1: two stacks
* Version 2: character map

### Non-repeated Substring [[C++ STL]](String.Non-repeated-substring.STL)
Given a string, find the max size of the sub-string which has no duplicate characters.
* character map
* two pointers

### Reverse Words [[C#]](String.Reverse-words.NET) [[PHP]](PHP/String.Reverse-words.PHP)
Reverse the words in a string. Include the punctuation as the part of the words.
* split
* StringBuilder

---

## Algorithms

### Counting 1-bits [[C++ STL]](Algorithm.Counting-1-bits.STL) [[PHP]](PHP/Algorithm.Counting-1-bits.PHP)
Count the number of 1-bits in the binary representation of a positive number.
* Version 1: straightforward bitwise shift
* Version 2: [Brian Kernighan’s Algorithm](https://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan)

### Finite State Machine [[C++ STL]](Algorithm.Finite-state-machine.STL)
Implement binary addition using [Finite state machine](https://en.wikipedia.org/wiki/Finite-state_machine).

### Huffman Codes [[C++ STL]](Algorithm.Huffman-codes.STL)
Implement [Huffman coding](https://en.wikipedia.org/wiki/Huffman_coding).

### Greatest Common Divisor [[C++]](Algorithm.Greatest-common-divisor.CPP)
Find the greatest common divisor of the two given numbers using the [Euclidean algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm).
* Version 1: division-based
* Version 2: subtraction-based
* Version 3: recursion-based

### Inversion Number [[C++ STL]](Algorithm.Inversion-number.STL)
Count the [Inversion number](https://en.wikipedia.org/wiki/Inversion_%28discrete_mathematics%29) in an array.
* Version 1: Straightforward

### Postfix Notation [[C++ STL]](Algorithm.Postfix-notation.STL)
Parse and calculate an arithmetic expression in [Reverse Polish / postfix notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation).

### Sieve of Eratosthenes [[C++ STL]](Algorithm.Sieve-of-Eratosthenes.STL)
Find all the prime numbers up to a given limit using [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) algorithm.

### Tower of Hanoi [[C++ STL]](Algorithm.Hanoi.STL) 
Solve the [Tower of Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi) puzzle.

### Two Odd Numbered Elements [[C++]](Algorithm.Two-odd-numbered-elements.CPP)
You are given an integer array, where all numbers except for TWO numbers appear even number of times. 
Find out the two numbers which appear odd number of times.
* Version 1: bit manipulation
* Version 2: using a hash table - is trivial and is not implemented
