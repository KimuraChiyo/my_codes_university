using System.Collections.Generic;

class Program {
    static void Main() {
        task_title(1);
        List<int> ints1 = new List<int>() {1, 2, 3, 4, 5};
        ints1.ForEach(p => Console.Write($"{p} "));
        ints1.Add(6);
        Console.WriteLine();
        ints1.ForEach(p => Console.Write($"{p} "));
        Console.WriteLine();

        task_title(2);
        List<int> ints2 = new List<int> {7, 8, 9};
        ints2.ForEach(p => Console.Write($"{p} "));
        Console.WriteLine();
        
        task_title(3);
        ints1.InsertRange(2, ints2);
        ints1.ForEach(p => Console.Write($"{p} "));
        Console.WriteLine();

        task_title(4);
        Console.WriteLine(ints1.Count);

        task_title(5);
        Console.WriteLine(ints1.Max());

        task_title(6);
        Console.WriteLine(ints1.Min());

        task_title(7);
        int[] array = new int [3];
        ints2.CopyTo(array);
        Array.ForEach(array, p => Console.Write($"{p} "));
        Console.WriteLine();

        task_title(8);
        ints2.RemoveAt(1);
        ints2.ForEach(p => Console.Write($"{p} "));
    }

    static void task_title(int number) {
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.WriteLine($"\nTask{number}-----------------------------------\n");
        Console.ForegroundColor = ConsoleColor.White;
    }

    // static int RetInt(string com = "") {
    //     Console.Write(com);
    //     while (true) {
    //         try {
    //             return Convert.ToInt32(Console.ReadLine());
    //         } catch {
    //             Console.Write($"Error:'{com}'\n");
    //         }
    //     }
    // }

}