class Program {
    static void Main() {
        int n = RetInt("Enter n: ");
        for (int i = 1; i <= n; i++) {
            int len = 0;
            int num_check = i;
            while (num_check > 0) {
                len++;
                num_check /= 10;
            }

            if (i == ((i * i) % (Math.Pow(10, len)))) {
                int num_without_ending = i * i - (i * i) % (int)(Math.Pow(10, len));
                if (num_without_ending != 0) {
                    Console.Write($"{i} {num_without_ending / Math.Pow(10, len)}");
                } else {
                    Console.Write($"{i} ");
                }
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine($"{((i * i) % (Math.Pow(10, len)))}");
                Console.ForegroundColor = ConsoleColor.White;

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
