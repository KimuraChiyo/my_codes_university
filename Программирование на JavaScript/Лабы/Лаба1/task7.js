// task 7
{
    for (let i = 1; i < 10; i++) {
        let string = String(i);
        for (let k = 0; k < i - 1; k++) string += String(i);
        console.log(string);
    }
}
