using System.Collections.Generic;

class Program {
    static void Main() {
        task_title(1);
        string input_string = RetStr($"Input string: ");
        List<string> lexems = new List<string>();
        string words = "";
        foreach (char elem in input_string) {
            if (elem != ' ') {
                words += elem;
            } else {
                lexems.Add(words);
                words = "";
            }
        }
        lexems.Add(words);
        lexems.Reverse();
        Console.WriteLine("Обратный порядок слов");
        foreach (string elem in lexems) {
            Console.Write($"{elem} ");
        }
        Console.WriteLine();
        Console.WriteLine("Обратная строка:");
        foreach (string elem in lexems) {
            Console.Write($"{string.Join("", elem.ToCharArray().Reverse())} ");
        }

    }

    static void task_title(int number) {
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.WriteLine($"Task{number}-----------------------------------");
        Console.ForegroundColor = ConsoleColor.White;
    }

    static string RetStr(string com = "") {
        Console.Write(com);
        while (true) {
            try {
                return Console.ReadLine()!;
            } catch {
                Console.Write($"Error:'{com}'\n");
            }
        }
    }
}