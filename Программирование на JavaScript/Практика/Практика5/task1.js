// task 1
{
    let object = {
        name: "Леонид",

        toString() {
            return `Меня зовут ${this.name}`
        }
    }

    alert(object);
    // было интересно как выводятся объекты с методами
    // alert(printableObj(object));
}