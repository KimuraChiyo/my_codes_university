// task 4
{
    let regex = /(0\d|1[01]).[0-5]\d (am|pm)/;

    let time1 = '11.59 am';
    let time2 = '00.00 pm';
    let time3 = '00.01 pm';
    alert(regex.test(time1));
    alert(regex.test(time2));
    alert(regex.test(time3));
}
