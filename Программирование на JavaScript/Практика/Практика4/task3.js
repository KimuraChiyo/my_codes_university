// task 3
{
    let week = {
        1: 'понедельник',
        2: 'вторник',
        3: 'среда',
        4: 'четверг',
        5: 'пятница',
        6: 'суббота',
        7: 'воскресенье'
    };

    for (let day in week) {
        alert(`${day} день недели: ${week[day]}`);
    }
}