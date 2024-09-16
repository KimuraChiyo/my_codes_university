// task 5
{
    let regex = /1([5-7]\d\d|800)/;

    let num1 = '1499';
    alert(regex.test(num1));
    let num2 = '1599';
    alert(regex.test(num2));
}