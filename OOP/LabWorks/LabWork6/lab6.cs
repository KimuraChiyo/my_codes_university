using System.Collections.Generic;

class Program {
    static void Main() {
        task_title(1);
        string path = "./file_sentences.txt";
        string [] array_strings = File.ReadAllLines(path);
        List<string> questions = new List<string>();
        List<string> declarative = new List<string>();
        foreach (string line in array_strings) {
            string sentence = "";
            int flag = 0;
            for (int i = 0; i < line.Length; i++) {
                if (line[i] == '?') {
                    sentence += line[i];
                    questions.Add(sentence);
                    sentence = "";
                    flag = 1;
                } else if (line[i] == '.') {
                    sentence += line[i];
                    declarative.Add(sentence);
                    sentence = "";
                    flag = 1;
                } else if (line[i] == ' ' && flag == 1) {
                    sentence = "";
                    flag = 0;
                } else {
                    sentence += line[i];
                }
            }
        }
        questions.ForEach(p => Console.WriteLine($"'{p}'\n"));
        declarative.ForEach(p => Console.WriteLine($"'{p}'\n"));

        task_title(2);
        string path1 = "./file_films.txt";
        string [] array_films = File.ReadAllLines(path1);
    
        var films = new Dictionary<int, List<string>>();
        foreach (string line in array_films) {
            int year = Convert.ToInt32(line.Substring(line.Length - 5, 4));
            if (films.ContainsKey(year)) {
                films[year].Add(line.Substring(0, line.Length - 7));
            } else {
                films[year] = new List<string>() {line.Substring(0, line.Length - 7)};
            }
        }

        Console.WriteLine();

        var sortedFilms = new SortedDictionary<int, List<string>>(films);
        string txt_sortedFilms = "";
        foreach (var key in sortedFilms.Keys) {
            Console.Write($"{key})");
            txt_sortedFilms += $"{key})";
            for (int i = 0; i < sortedFilms[key].Count; i++) {
                Console.WriteLine($"\t{i + 1}) {sortedFilms[key][i]}\n");
                txt_sortedFilms += $"\t{i + 1}) {sortedFilms[key][i]}\n";
            }
        }
        string returnPath = "./exit_file.txt";
        File.WriteAllText(returnPath, txt_sortedFilms);

    }

    static void task_title(int number) {
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.WriteLine($"\nTask{number}-----------------------------------\n");
        Console.ForegroundColor = ConsoleColor.White;
    }

}