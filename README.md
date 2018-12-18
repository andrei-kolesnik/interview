# Data Structures and Algorithms interview questions and their solutions
Data Structures and Algorithms interview questions and their solutions.

* **[C++]** - C-style array
* **[STL]** - Standard Library std::array
* **[C#]** - C# Array class

## Arrays

### [Array.Binary-search](Array.Binary-search.CPP) [C++]
Implement a binary search for the integer in a sorted array.
### [Array.Find-pair](Array.Find-pair.NET) [C#]
Find a pair with the given sum in an unsorted array (brute force version).
### [Array.Find-pair](Array.Find-pair.STL) [STL]
Find a pair with the given sum in an unsorted array (sorting & iterators).
### [Array.Missing-element](Array.Missing-element.CPP) [C++]
Find a missing element in a randomized sequence.
### [Array.Sorted-merge](Array.Sorted-merge.STL) [STL]
Merge two sorted arrays.
### [Array.Merge-Sort](Array.Merge-sort.CPP) [CPP]
Sort an array using the merge sort alrorithm.
* Version 1: straightforward merge
* Version 2: merge using extra sentinel elements
* Version 3: merge in place
* Version 4: library `inplace_merge`

---

## Strings

### [String.Anagram](String.Anagram.STL) [STL]
Determine if two strings are anagrams (version 1: sorting; version 2: character map).
### [String.Escape](String.Escape.CPP) [C++]
Escape all % characters in a string with % as the escape character.
### [String.Reverse-words](String.Reverse-words.NET) [C#]
Reverse the words in a string. Include the punctuation as the part of the words (Split and StringBuilder).
### [String.Anagram](String.Non-repeated-character.STL) [STL]
Find the first non-repeated character in a string (version 1: two stacks; version 2: character map).

---

## Algorithms

### [Algorithm.Hanoi](Algorithm.Hanoi.STL) [STL]
Solve the [Tower of Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi) puzzle.

### [Algorithm.Counting-1-bits](Algorithm.Counting-1-bits.STL) [STL]
Count the number of 1-bits in the binary representation of a positive number.
* Version 1: straightforward bitwise shift
* Version 2: [Brian Kernighan’s Algorithm](https://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan)

### [Algorithm.Sieve-of-Eratosthenes](Algorithm.Sieve-of-Eratosthenes.STL) [STL]
Find all the prime numbers up to a given limit using [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) algorithm.

### [Algorithm.Postfix-notation](Algorithm.Postfix-notation.STL) [STL]
Parse and calculate an arithmetic expression in [Reverse Polish / postfix notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation).
