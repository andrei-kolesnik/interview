//Reverse the words in a string. Include the punctuation as the part of the words.
//IN: 
//A string
//OUT:
//The string with the words in the reversed order
using System;
using System.Text;

namespace String.Reverse_words.NET
{
    class StringReverseWords
    {
        static string ReverseWords(string str)
        {
            StringBuilder sb = new StringBuilder();
            string[] words = str.Split(new Char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            for (int i = words.Length-1; i >= 0; i--)
                sb.Append(words[i] + (i > 0 ? " " : ""));
            return sb.ToString();
        }
        static void Main(string[] args)
        {
            Console.WriteLine(ReverseWords(""));
            Console.WriteLine(ReverseWords("Hello!"));
            Console.WriteLine(ReverseWords("Hello?  World!"));
            Console.WriteLine(ReverseWords("Hello - world, it’s a so-so day..."));
            Console.ReadKey();
        }
    }
}
