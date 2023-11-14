using System.ComponentModel;
using System.Data;
using System.Reflection.Metadata.Ecma335;
using System.Xml.Schema;

class Program {
    static void Main() {
        int[] temp = {1, 2, 3, 4};
        int[] temp1 = {5, 6, 7};
        Set arr = new Set(temp);
        Set arr1 = new Set(temp1);
        Set arrai = arr1 * arr;
        arrai.ShowSet();
    }
}