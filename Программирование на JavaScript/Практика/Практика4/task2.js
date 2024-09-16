// task 2
{
    let salaries = {
        Adam: 250,
        Bob: 350,
        Cindy: 400
    };

    let sum = 0;
    for (let key in salaries) {
        sum += salaries[key];
    }

    alert(`Cумма зарплат(250 + 350 + 400) равна ${sum}`);
}
