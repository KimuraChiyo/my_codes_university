class Program {
    static void Main() {
        for (int i = 1; i < 4; i++) {
            task_title(i);
            switch (i) {
                case 1: {
                    task1();
                    break;
                }
                case 2: {
                    task2();
                    break;
                }
                case 3: {
                    task3();
                    break;
                }
                default: {
                    Console.WriteLine("TODO");
                    break;
                }
            }
        }
    }

    static void task3() {
        Console.WriteLine();
        int[] arrs_n = {5, 3, 8, 4, 6};
        int[][] tooth_array = new int[5][];
        tooth_array[0] = new int[5];
        tooth_array[1] = new int[3];
        tooth_array[2] = new int[8];
        tooth_array[3] = new int[4];
        tooth_array[4] = new int[6];

        int Min = -500;
        int Max = 500;
        Random randNum = new Random();
        for (int i = 0; i < 5; i++) {
            int sum = 0;
            Console.ForegroundColor = ConsoleColor.Green;
            for (int k = 0; k < arrs_n[i]; k++) {
                int value = randNum.Next(Min, Max);
                tooth_array[i][k] = value;
                sum += value;
                Console.Write($"{tooth_array[i][k]}\t");
                
            }
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine($"\nsum(tooth_array[{i}]) = {sum}");
        }
        Console.ResetColor();

    }

    static void task2() {
        int n = RetInt("Input n: ");
        while (n < 1) {
            n = RetInt("Input n: ");
        }
        int m = RetInt("Input m: ");
        while (n < 1) {
            m = RetInt("Input m: ");
        }

        // initializing
        int Min = -1;
        int Max = 40;
        Random randNum = new Random();
        int[,] array = new int[n, m];
        
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.WriteLine();
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                int value = randNum.Next(Min, Max);
                array[i, k] = value;
                Console.Write($"{array[i, k]}\t");
            }
            Console.WriteLine();
        }
        Console.WriteLine();
        Console.ForegroundColor = ConsoleColor.White;

        int count = 0;
        for (int k = 0; k < m; k++) {
            int count_neg = 0;
            for (int i = 0; i < n; i++) {
                if (array[i, k] < 0) {
                    count_neg++;
                }
            }
            if (count_neg == 0) {
                count++;
            }
        }

        Console.ForegroundColor = ConsoleColor.Red;
        Console.WriteLine($"Count of cols without negatives: {count}");
        Console.ForegroundColor = ConsoleColor.White;

        Console.WriteLine();
        Console.WriteLine("Normal array:");
        Console.ForegroundColor = ConsoleColor.Red;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                Console.Write($"{array[i, k]}\t");
            }
            Console.WriteLine();
        }
        Console.ForegroundColor = ConsoleColor.White;
        Console.WriteLine();

        Console.WriteLine("1243 array:");
        Console.ForegroundColor = ConsoleColor.Red;
        int[] spec_array = new int[] {0, 1, 3, 2};
        foreach (int value in spec_array) {
            for (int k = 0; k < m; k++) {
                Console.Write($"{array[value, k]}\t");
            }
            Console.WriteLine();
        }
        Console.ForegroundColor = ConsoleColor.White;
        Console.WriteLine();

    }

    static void task1() {
        int n = RetInt("Input n: ");
        while (n < 1) {
            n = RetInt("Input n: ");
        }

        // initializing
        int Min = -40;
        int Max = 40;
        Random randNum = new Random();
        double[] array = new double[n];
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.WriteLine();
        for (int i = 0; i < n; i++) {
            double value = (double)randNum.Next(Min, Max) / randNum.Next(Min, Max);
            array[i] = value;
            Console.Write($"{array[i]}\t");
        }
        Console.ForegroundColor = ConsoleColor.White;
        Console.WriteLine();
        Console.WriteLine();

        // count + index of mininal num
        int count = 0;
        int min_i = 0;
        for (int i = 0; i < n; i++) {
            if (array[i] > 0) {
                count++;
            }
            if (array[i] < array[min_i]) {
                min_i = i;
            }
        }

        // sum of element < array[min_i]
        double sum = 0;
        for (int i = 0; i < min_i; i++) {
            sum += array[i];
        }

        // output
        Console.ForegroundColor = ConsoleColor.Red;
        Console.WriteLine($"Count of positive nums: {count}");
        Console.WriteLine($"Index of minimum number: {min_i}");
        Console.WriteLine($"Minimal number: {array[min_i]}");
        Console.WriteLine($"Sum of nums before min: {sum}");
        Console.ForegroundColor = ConsoleColor.White;
    }

    static void task_title(int number) {
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.WriteLine($"Task{number}-----------------------------------");
        Console.ForegroundColor = ConsoleColor.White;
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