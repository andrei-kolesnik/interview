using System;
//Find a pair with the given sum in an unsorted array
//IN:
//- An unsorted array
//- A number
//OUT:
//- All the element pairs which sum equals to the given number
//COMMENTS:
//Sorting solution: complexity O(n^2) (see the solution with sorting & iterators in STL)
namespace Arrays.NET
{
    class Arrays_Find_Pair
    {
        static void print_arr(int[] arr)
        {
            //Verbose form:
            int i = 0;
            foreach (int a in arr)
                Console.WriteLine("[{0}]: {1}", i++, a);
            //Compact form:
            //Array.ForEach(arr, Console.WriteLine);
            //Console.WriteLine();
        }
        static void array_find_pair(int[] arr, int sum)
        {
            for (int i = 0; i < arr.Length; i++)
                for (int j = i + 1; j < arr.Length; j++)
                    if (arr[i] + arr[j] == sum)
                        Console.WriteLine("Pair found at index [{0}] and [{1}]: ({2} + {3})", 
                            i, j, arr[i], arr[j]);
        }
        static void Main(string[] args)
        {
            int[] arr = new int[] { 3, 7, 6, 2, 11, 5, 1, 4, 8, 9, 10 };
            int sum = 12;
            print_arr(arr);
            array_find_pair(arr, sum);
            Console.ReadKey();
        }
    }
}
