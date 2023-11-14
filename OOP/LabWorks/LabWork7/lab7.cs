using System.ComponentModel;
using System.Data;
using System.Reflection.Metadata.Ecma335;
using System.Xml.Schema;

class Program {
    static void Main() {
        task_title(1, "Create ResearchTeam and output ToShortString");
        ResearchTeam team = new ResearchTeam();
        Console.WriteLine(team.ToShortString());
        
        task_title(2, "Indexators with indexes");
        Console.WriteLine(team[TimeFrame.Year]);
        Console.WriteLine(team[TimeFrame.TwoYears]);
        Console.WriteLine(team[TimeFrame.Long]);
        
        task_title(3, "Output with ToString");
        Console.WriteLine(team.ToString());
        
        task_title(4, "Work of AddPapers");
        Paper[] new_papers = new Paper[2] {new Paper(), new Paper()};
        team.AddPapers(new_papers);
        Console.WriteLine(team.ToString());
        
        task_title(5, "Last Publication");
        Console.WriteLine(team.GetLastPaper);

        task_title(6, "Operation Time Research");

        Console.WriteLine("Введите два числа через разделитель:");
        Console.WriteLine("Доступные разделители: ' ', ';', ':', ',', '.', '&', '|'");
        Console.Write("Введите строку с числами: ");
        string nums = Console.ReadLine();
        string[] array = {"0", "0"};
        foreach (char separator in " ;:,.&|") {
            int flag = 0;
            foreach (char symbol in nums) {
                if (symbol == separator) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                array = nums.Split(separator);
                break;
            }
        }
        int nrow = Convert.ToInt32(array[0]), ncolumn = Convert.ToInt32(array[1]);
        Console.WriteLine($"{nrow} {ncolumn}");

        Paper[] oned_arr = new Paper[nrow*ncolumn];
        for (int i = 0; i < nrow*ncolumn; i++) {
            oned_arr[i] = new Paper();
        }

        Paper[,] twod_arr = new Paper[nrow, ncolumn];
        for (int i = 0; i < nrow; i++) {
            for (int j = 0; j < ncolumn; j++) {
                twod_arr[i, j] = new Paper();
            }
        }


        int count = nrow*ncolumn;
        int Min = 1;
        int Max = count / 2;
        Random randNum = new Random();
        Paper[][] ragg_arr = new Paper[4][];
        int len = count / 4;
        for (int i = 0; i < 4; i++) {
            if (count > len && i < 3) {
                ragg_arr[i] = new Paper[len];
                for (int k = 0; k < len; k++) {
                    ragg_arr[i][k] = new Paper();
                }
            } else {
                ragg_arr[i] = new Paper[count];
                for (int k = 0; k < count; k++) {
                    ragg_arr[i][k] = new Paper();
                }
            }
            count -= len;
        }

        int time1 = System.Environment.TickCount;
        foreach (Paper elem in oned_arr) {
            elem.Publication_Name = "NOT YOUR TROUBLES";
            elem.Author.Name = "NOT YOUR TROUBLES";
        }
        int time2 = System.Environment.TickCount;
        int time_oned = time2 - time1;



        time1 = System.Environment.TickCount;
        for (int i = 0; i < nrow; i++) {
            for (int k = 0; k < ncolumn; k++) {
                twod_arr[i, k].Publication_Name = "NOT YOUR TROUBLES";
                twod_arr[i, k].Author.Name = "NOT YOUR TROUBLES";
            }
        }
        time2 = System.Environment.TickCount;
        int time_twod = time2 - time1;


        time1 = System.Environment.TickCount;
        for (int i = 0; i < ragg_arr.Length; i++) {
            for (int k = 0; k < ragg_arr[i].Length; k++) {
                ragg_arr[i][k].Publication_Name = "NOT YOUR TROUBLES";
                ragg_arr[i][k].Author.Name = "NOT YOUR TROUBLES";
            }
        }
        time2 = System.Environment.TickCount;
        int time_raggarr = time2 - time1;

        Console.WriteLine($"\tType\t|\tTime, ms");
        Console.WriteLine($"\t1dim\t|\t{time_oned}");
        Console.WriteLine($"\t2dim\t|\t{time_twod}");
        Console.WriteLine($"\tragged\t|\t{time_raggarr}");
        // вывод одномерного массива
        // Array.ForEach(oned_arr, Console.WriteLine);

        // вывод двумерного массива
        // for (int i = 0; i < 2; i++)
        // {
        //     for (int k = 0; k < 4; k++)
        //     {
        //         Console.WriteLine(two_dimensions_array[i, k]);
        //     }
        // }

        // вывод ступенчатого массива 
        // for (int i = 0; i < ragged_array.Length; i++)
        // {
        //     for (int k = 0; k < ragged_array[i].Length; k++)
        //     {
        //         Console.WriteLine(ragged_array[i][k]);
        //     }
        // }

    }   

    static void task_title(int number, string comment) {
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.WriteLine($"\nTask{number}-----------------------------------{comment}\n");
        Console.ForegroundColor = ConsoleColor.White;
    }
}