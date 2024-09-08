// task 5
{
    function Magnifier(firstValue) {
        this.value = firstValue;

        this.read = function () {
            let numToAdd = Number(prompt("Введите число, которое надо добавить:", 10));
            this.value += numToAdd;
        }
    }

    let magn = new Magnifier(10);
    alert(printableObj(magn));
    magn.read();
    alert(printableObj(magn));
}