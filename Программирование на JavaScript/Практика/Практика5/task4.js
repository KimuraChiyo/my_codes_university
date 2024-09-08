// task 4
{
    function InitObject() {
        this.getProperties = function () {
            this.val1 = Number(prompt("Введите значение первого свойства: ", 10));
            this.val2 = Number(prompt("Введите значение второго свойства: ", 30));
        }
        this.sumProperties = function () {
            return this.val1 + this.val2;
        }
        this.multProperties = function () {
            return this.val1 * this.val2;
        }
    }

    let obj = new InitObject();
    alert(printableObj(obj));
    obj.getProperties();
    alert(printableObj(obj));
    alert(obj.sumProperties());
    alert(obj.multProperties());
}