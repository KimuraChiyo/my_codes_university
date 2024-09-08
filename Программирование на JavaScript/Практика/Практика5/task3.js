// task 3
{   
    let stud1 = {
        first_Name: 'Леонид',
        last_Name: 'Соловьёв',
        group: 'ПИ-1-22',
        year: 2022
    };
    let stud2 = {
        first_Name: 'Лиза',
        last_Name: 'Габриелова',
        group: 'ПМ-2-22',
        year: 2022
    };
    let stud3 = {
        first_Name: 'Арсений',
        last_Name: 'Байрамшин',
        group: 'ПИ-1-22',
        year: 2022
    };
    function objToString() {
        return `${this.first_Name} ${this.last_Name} обучается в группе ${this.group}. Год поступления ${this.year}`;
    }

    stud1.toString = objToString;
    stud2.toString = objToString;
    stud3.toString = objToString;
    
    alert(stud1);
    alert(stud2);
    alert(stud3);
}