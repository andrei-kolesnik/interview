# Data Structures and Algorithms interview questions and their solutions
Data Structures and Algorithms interview questions and their solutions.

(Problems from [LeetCode](https://github.com/andrei-kolesnik/leetcode) and [HackerRank](https://github.com/andrei-kolesnik/hackerrank) can be found in their respective repositories.)

* **[C++]** - C-style array
* **[STL]** - Standard Library std::array
* **[C#]** - C# Array class

## Arrays

### [Array.Binary-search](Array.Binary-search.CPP) [C++]
Implement a binary search for the integer in a sorted array.

### Array.Find-pair [[brute force version, C#]](Array.Find-pair.NET) [[sorting & iterators, STL]](Array.Find-pair.STL)
Find a pair with the given sum in an unsorted array.

### [Array.Merge-Sort](Array.Merge-sort.CPP) [CPP]
Sort an array using the merge sort alrorithm.
* Version 1: straightforward merge
* Version 2: merge using extra sentinel elements
* Version 3: merge in place
* Version 4: library `inplace_merge`

### [Array.Missing-element](Array.Missing-element.CPP) [C++]
Find a missing element in a randomized sequence.

### [Array.Sorted-merge](Array.Sorted-merge.STL) [STL]
Merge two sorted arrays.

---

## Strings

### [String.Anagram](String.Anagram.STL) [STL]
Determine if two strings are anagrams (version 1: sorting; version 2: character map).

### [String.Escape](String.Escape.CPP) [C++]
Escape all % characters in a string with % as the escape character.

### [String.Non-repeated-character](String.Non-repeated-character.STL) [STL]
Find the first non-repeated character in a string (version 1: two stacks; version 2: character map).

### [String.Reverse-words](String.Reverse-words.NET) [C#]
Reverse the words in a string. Include the punctuation as the part of the words (Split and StringBuilder).

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

### [Algorithm.Postfix-notation](Algorithm.Postfix-notation.STL) [STL]
Parse and calculate an arithmetic expression in [Reverse Polish / postfix notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation).

### [Algorithm.Sieve-of-Eratosthenes](Algorithm.Sieve-of-Eratosthenes.STL) [STL]
Find all the prime numbers up to a given limit using [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) algorithm.
