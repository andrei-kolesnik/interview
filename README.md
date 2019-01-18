# Data Structures and Algorithms interview questions and their solutions
Data Structures and Algorithms interview questions and their solutions.

(Problems from [LeetCode](https://github.com/andrei-kolesnik/leetcode) and [HackerRank](https://github.com/andrei-kolesnik/hackerrank) can be found in their respective repositories.)

* **[C++]** - C-style array
* **[STL]** - Standard Library std::array
* **[C#]** - C# Array class

## Arrays

### [Array.Binary-search](Array.Binary-search.CPP) [C++]
Implement a binary search for the integer in a sorted array.

### Array.Find-pair 
Find a pair with the given sum in an unsorted array.
* Version 1: brute force [[C#]](Array.Find-pair.NET) 
* Version 2: sorting & iterators [[STL]](Array.Find-pair.STL)

### [Array.Merge-Sort](Array.Merge-sort.CPP) [CPP]
Sort an array using the merge sort alrorithm.
* Version 1: straightforward merge
* Version 2: merge using extra sentinel elements
* Version 3: merge in place
* Version 4: library `inplace_merge`

### [Array.Quick-Sort](Array.Quick-sort.CPP) [CPP]
Sort an array using the merge sort alrorithm.

### [Array.Missing-element](Array.Missing-element.CPP) [C++]
Find a missing element in a randomized sequence.

### [Array.Duplicated-element](Array.Duplicated-element.CPP) [C++]
Given an array of n + 1 integers between 1 and n, find one of the duplicates.
* Version 1: brute force
* Version 2: using a map/counters
* Version 3: using the sum of the elemets
* Version 4: using +/- markers
* Version 5: looking for a loop

### [Array.Sorted-merge](Array.Sorted-merge.STL) [STL]
Merge two sorted arrays.

---

## Strings

### [String.Anagram](String.Anagram.STL) [STL]
Determine if two strings are anagrams 
* Version 1: sorting
* Version 2: character map

### [String.Escape](String.Escape.CPP) [C++]
Escape all % characters in a string with % as the escape character.

### [String.Non-repeated-character](String.Non-repeated-character.STL) [STL]
Find the first non-repeated character in a string 
* Version 1: two stacks
* Version 2: character map

### [String.Non-repeated-substring](String.Non-repeated-substring.STL) [STL]
Given a string, find the max size of the sub-string which has no duplicate characters.
* character map
* two pointers

### [String.Reverse-words](String.Reverse-words.NET) [C#]
Reverse the words in a string. Include the punctuation as the part of the words.
* split
* StringBuilder

---

## Algorithms

### [Algorithm.Counting-1-bits](Algorithm.Counting-1-bits.STL) [STL]
Count the number of 1-bits in the binary representation of a positive number.
* Version 1: straightforward bitwise shift
* Version 2: [Brian Kernighan’s Algorithm](https://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan)

### [Algorithm.Finite-state-machine](Algorithm.Finite-state-machine.STL) [STL]
Implement binary addition using [Finite state machine](https://en.wikipedia.org/wiki/Finite-state_machine).

### [Algorithm.Huffman-codes](Algorithm.Huffman-codes.STL) [STL]
Implement [Huffman coding](https://en.wikipedia.org/wiki/Huffman_coding).

### [Algorithm.Greatest-common-divisor](Algorithm.Greatest-common-divisor.CPP) [C++]
Find the greatest common divisor of the two given numbers using the [Euclidean algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm).
* Version 1: division-based
* Version 2: subtraction-based
* Version 3: recursion-based

### [Algorithm.Hanoi](Algorithm.Hanoi.STL) [STL]
Solve the [Tower of Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi) puzzle.

### [Algorithm.Inversion-number](Algorithm.Inversion-number.STL) [STL]
Count the [Inversion number](https://en.wikipedia.org/wiki/Inversion_%28discrete_mathematics%29) in an array.
* Version 1: Straightforward

### [Algorithm.Postfix-notation](Algorithm.Postfix-notation.STL) [STL]
Parse and calculate an arithmetic expression in [Reverse Polish / postfix notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation).

### [Algorithm.Sieve-of-Eratosthenes](Algorithm.Sieve-of-Eratosthenes.STL) [STL]
Find all the prime numbers up to a given limit using [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) algorithm.

### [Algorithm.Two-odd-numbered-elements](Algorithm.Two-odd-numbered-elements.CPP) [CPP]
You are given an integer array, where all numbers except for TWO numbers appear even number of times. 
Find out the two numbers which appear odd number of times.
* Version 1: bit manipulation
* Version 2: using a hash table - is trivial and is not implemented
