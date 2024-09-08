using System;

class Program {
    static void Main() {
        Console.WriteLine("Task1----------------------------------------------------");
        task1();
        Console.WriteLine("\nTask2----------------------------------------------------");
        task2();
        Console.WriteLine("\nTask3----------------------------------------------------");
        task3();
    }
    

    static void task1() {
        double alpha = RetDoub("Enter alpha: ");

        Console.WriteLine($"\nalpha = {alpha}");
        Console.WriteLine($"alpha/4 = {alpha / 4}");
        
        Console.WriteLine($"(3*pi)/8 = {(3 * Math.PI) / 8}");
        double cos_par1 = (3 * Math.PI) / 8 - alpha / 4;
        Console.WriteLine($"(3*pi)/8 - alpha/4 = {cos_par1}");
        double cos1 = Math.Cos(cos_par1);
        Console.WriteLine($"cos((3*pi)/8 - alpha/4) = {cos1}");
        Console.WriteLine($"cos^2((3*pi)/8 - alpha/4) = {cos1 * cos1}");

        Console.WriteLine($"(11*pi)/8 = {(11 * Math.PI) / 8}");
        double cos_par2 = (11 * Math.PI) / 8 + alpha / 4;
        Console.WriteLine($"(11*pi)/8 + alpha/4 = {cos_par2}");
        double cos2 = Math.Cos(cos_par2);
        Console.WriteLine($"cos((11*pi)/8 + alpha/4) = {cos2}");
        Console.WriteLine($"cos^2((11*pi)/8 + alpha/4) = {cos2 * cos2}");

        Console.ForegroundColor = ConsoleColor.Red;
        Console.WriteLine($"\nz1 = cos^2((3*pi)/8 - alpha/4) - cos^2((11*pi)/8 + alpha/4) = {Math.Round(cos1 * cos1 - cos2 * cos2, 3)}");

        Console.ForegroundColor = ConsoleColor.White;
        Console.WriteLine($"\nalpha/2 = {alpha / 2}");
        Console.WriteLine($"sin(alpha/2) = {Math.Sin(alpha / 2)}");

        Console.ForegroundColor = ConsoleColor.Red;
        Console.WriteLine($"\nz2 = sqrt(2) * sin(alpha/2) / 2 = {Math.Round(Math.Sqrt(2) * Math.Sin(alpha / 2) / 2, 3)}");

        Console.ResetColor();
    }

    static void task2() {
        double x = RetDoub("Enter x: "), a = RetDoub("Enter a: "), b = RetDoub("Enter b: ");
        if (a * x < b) {
            lt(x, a, b);
        } else {
            ge(x, a, b);
        }
        Console.ResetColor();
    }

    static void task3() {
        int year = RetInt("Enter year: ");
        Console.ForegroundColor = ConsoleColor.Red;
        switch (year % 12) {
            case 4: {
                Console.WriteLine("Год крысы");
                break;
            }
            case 5: {
                Console.WriteLine("Год коровы");
                break;
            }
            case 6: {
                Console.WriteLine("Год тигра");
                break;
            }
            case 7: {
                Console.WriteLine("Год зайца");
                break;
            }
            case 8: {
                Console.WriteLine("Год дракона");
                break;
            }
            case 9: {
                Console.WriteLine("Год змеи");
                break;
            }
            case 10: {
                Console.WriteLine("Год лошади");
                break;
            }
            case 11: {
                Console.WriteLine("Год овцы");
                break;
            }
            case 0: {
                Console.WriteLine("Год обезьяны");
                break;
            }
            case 1: {
                Console.WriteLine("Год петуха");
                break;
            }
            case 2: {
                Console.WriteLine("Год собаки");
                break;
            }
            case 3: {
                Console.WriteLine("Год свиньи");
                break;
            }
        }
        Console.ResetColor();
    }

    static void lt(double x, double a, double b) {
        Console.WriteLine($"\nx, a, b = {x}, {a}, {b}");
        Console.WriteLine($"-2x = {-2 * x}");
        Console.WriteLine($"e^(-2x) = {Math.Exp(-2 * x)}");
        Console.WriteLine($"a^4 = {Math.Pow(a, 4)}");
        Console.WriteLine($"a^4 + x = {Math.Pow(a, 4) + x}");
        if ((Math.Pow(a, 4) + x) >= 0) {
            Console.WriteLine($"(a^4 + x)^1/4 = {Math.Pow(Math.Pow(a, 4) + x, 1.0/4)}");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine($"Answer: e^(-2x) + (a^4 + x)^1/4 = {Math.Exp(-2 * x) + Math.Pow(Math.Pow(a, 4) + x, 1.0/4)}");
        } else {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("Answer: (a^4 + x) < 0");
        }
    }

    static void ge(double x, double a, double b) {
        Console.WriteLine($"\nx, a, b = {x}, {a}, {b}");
        Console.WriteLine($"sin(x) = {Math.Sin(x)}");
        Console.WriteLine($"b^2 = {Math.Pow(b, 2)}");
        Console.ForegroundColor = ConsoleColor.Red;
        Console.WriteLine($"Answer: sin(x) - b^2 = {Math.Sin(x) - Math.Pow(b, 2)}");
    }

    static double RetDoub(string com = "") {
        Console.Write(com);
        while (true) {
            try {
                return Convert.ToDouble(Console.ReadLine());
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
