
class Program {

    static void Main() {
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.WriteLine("Task1----------------------------------------------------");
        Console.ForegroundColor = ConsoleColor.White;
        task1();
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.WriteLine("\nTask2----------------------------------------------------");
        Console.ForegroundColor = ConsoleColor.White;
        task2();
    }
    
    static void task1() {
        for (int i = -10; i <= 8; i++) {
            if (i == -10) {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine("This is semiround");
                Console.ForegroundColor = ConsoleColor.White;
            }
            if (i >= -10 && i <= -6) {
                // y =  sqrt((R - (x - x0))(R + (x - x0))) + y0
                int x0 = -8, y0 = -2;
                Console.WriteLine($"x = {i}, y = {Math.Sqrt((2 - (i - x0)) * (2 + (i - x0))) + y0}");
                //  y =  sqrt((R - (x - x0))(R + (x - x0))) + y0
            }
            if (i == -6) {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine("\nThis is line");
                Console.ForegroundColor = ConsoleColor.White;
            }
            if (i >= -6 && i <= 2) {
                double y1 = -2, x1 = -6, y2 = 2, x2 = 2;
                Console.WriteLine($"x = {i}, y = {((y2 - y1) * (i - x1) / (x2 - x1)) +  y1}");
                // y = ((y2 - y1) * (x - x1) / (x2 - x1)) + y1;
            }
            if (i == 2) {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine("\nThis is zeroline");
                Console.ForegroundColor = ConsoleColor.White;
            }
            if (i >= 2 && i <= 6) {
                Console.WriteLine($"x = {i}, y = 0");
            }
            if (i == 6) {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine("\nThis is parable");
                Console.ForegroundColor = ConsoleColor.White;
            }
            if (i >= 6 && i <= 8) {
                Console.WriteLine($"x = {i}, y = {Math.Pow(i - 6, 2)}");
            }
        }
    }

    static void task2() {
        Console.WriteLine("Количество двузначных чисел, сумма цифр которых кратна 5 при умножении на 3");
        int count = 0;
        for (int i = 10; i < 100; i++) {
            if (SumDigits(i * 3) % 5 == 0) {
                Console.WriteLine($"Num = {i}");
                Console.WriteLine($"Num * 3 = {i * 3}\n");
                count++;
            }
        }
        Console.ForegroundColor = ConsoleColor.Red;
        Console.WriteLine($"Answer: {count}");
        Console.ResetColor();
    }
    static int SumDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}

