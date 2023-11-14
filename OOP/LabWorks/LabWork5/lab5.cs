using System.Collections.Generic;

class Program {
    static void Main() {
        task_title(1);
        string input_string1 = RetStr($"Input string: ");
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        List<string> lexems1 = new List<string>();
        string words1 = "";
        foreach (char elem in input_string1) {
            if (elem != ' ') {
                words1 += elem;
            } else {
                lexems1.Add(words1);
                words1 = "";
            }
        }
        lexems1.Add(words1);
        lexems1.Reverse();
        Console.WriteLine("\nОбратный порядок слов");
        lexems1.ForEach(p => Console.Write($"{p} "));
        Console.WriteLine("\nОбратная строка:");
        lexems1.ForEach(p => Console.Write($"{string.Join("", p.ToCharArray().Reverse())} "));
        task_title(2);
        string input_string2 = RetStr($"Input string: ");
        List<string> lexems2 = new List<string>();
        string words2 = "";
        int max_len = -1;
        foreach (char elem in input_string2) {
            if (elem != ' ' && elem != ',') {
                words2 += elem;
            } else {
                lexems2.Add(words2);
                if (words2.Length > max_len) {
                    max_len = words2.Length;
                }
                words2 = "";
            }
        }
        lexems2.Add(words2);
        
        Console.WriteLine("You want to code or decode(1 to code and -1 to decode)");
        int ans = RetInt("Answer: ");
        if (ans == 1 || ans == -1) {
            max_len *= ans;
        }
        int len_str = input_string2.Length;

        input_string2.ToCharArray();
        for (int i = 0; i < len_str; i++) { 
            int index = alphabet.IndexOf(Char.ToLower(input_string2[i])) + max_len;
            if (index < 0) {
                index += 26;
            }
            if (Char.IsLower(input_string2[i])) {
                Console.Write(alphabet[index % 26]);
            } else if (Char.IsUpper(input_string2[i])) { 
                    Console.Write(Char.ToUpper(alphabet[index % 26]));
            } else {
                Console.Write(input_string2[i]);
            }
        }

    }

    static void task_title(int number) {
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.WriteLine($"\nTask{number}-----------------------------------\n");
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

    static int RetInt(string com = "") {
        Console.Write(com);
        while (true) {
            try {
                return Convert.ToInt32(Console.ReadLine());
            } catch {
                Console.Write($"Error:'{com}'\n");
            }
        }
    }

}