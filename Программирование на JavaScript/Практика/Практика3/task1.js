// task 1
{
    function checkAgeCond(age) {
        return (age > 18) ? true : confirm('Родители разрешили?');
    }

    function checkAgeOper(age) {
        return (age > 18) || confirm('Родители разрешили?');
    }

    let age = prompt('?: Сколько вам лет?', 10);
    alert(checkAgeCond(age));
    age = prompt('?: Сколько вам лет?', 19);
    alert(checkAgeCond(age));
    age = prompt('||: Сколько вам лет?', 10);
    alert(checkAgeOper(age));
    age = prompt('||: Сколько вам лет?', 19);
    alert(checkAgeOper(age));
}
