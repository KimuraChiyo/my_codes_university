class Set {
    public int[] Elements = new int[0];
    public int Count;
    public Set() {
        // реализовать уникальность
        this.Count = RetInt("Введите количество элементов: ");
        while (this.Count <= 0) {
            this.Count = RetInt("Введите количество элементов: ");
        }
        Elements = new int[this.Count];
        Fill();
    }
    public Set(int[] array) {
        // реализовать уникальность
        this.Count = array.Length;
        this.Elements = new int[this.Count];
        for (int i = 0; i < this.Count; i++) {
            Elements[i] = array[i];
        }
    }

    public void Fill() {
        // реализовать уникальность введенных значений
        for (int i = 0; i < Count; i++) {
            int value;
            while (1) {
                value = RetInt($"Введите {i}-тый элемент: ");
                if (Arrayvalue)
            }
            this.Elements[i] = RetInt($"Введите {i}-тый элемент: ");
        }
    }
    public void ShowSet() {
        for (int i = 0; i < this.Count; i++) {
            Console.WriteLine($"[{i}]:\t{Elements[i]}");
        }
    }
    public int IndexOf(int value) {
        int temp = -1;
        for (int i = 0; i < this.Count; i++) {
            if (this.Elements[i] == value) {
                temp = i;
                break;
            }
        }
        return temp;
    }  
    // public void Add(int new_elem) {
    //     // проверить с уникальностью
    //     Array.Resize(ref Elements, this.Count + 1);
    //     this.Count++;
    //     this.Elements[this.Count - 1] = new_elem;
    // }
    public static int RetInt(string com = "") {
        Console.Write(com);
        while (true) {
            try {
                return Convert.ToInt32(Console.ReadLine());
            } catch {
                Console.Write($"Error:'{com}'\n");
            }
        }
    }

    public static Set operator ++ (Set set1) {
        for (int i = 0; i < set1.Count; i++) {
            set1.Elements[i] += 1;
        }
        return set1;
    }
    // public static Set operator + (Set set1, Set set2) {
    //     // уникальность
    //     int[] set3 = new int[set1.Count + set2.Count];
    //     Array.Copy(set1.Elements, 0, set3, 0, set1.Count);
    //     Array.Copy(set2.Elements, 0, set3, set1.Count, set2.Count);
    //     Set temp = new Set(set3);
    //     return temp;
    // }
}