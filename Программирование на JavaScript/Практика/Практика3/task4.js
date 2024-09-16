// task 4
{
    function getDayOfWeek(dayNumber) {
        if (dayNumber >= 1 && dayNumber <= 7) {
            let result = '';
            switch ((dayNumber - 1) % 7) {
                case 0: { result = 'понедельник'; break;}
                case 1: { result = 'вторник'; break;}
                case 2: { result = 'среда'; break;}
                case 3: { result = 'четверг'; break; }
                case 4: { result = 'пятница'; break; }
                case 5: { result = 'суббота'; break;}
                case 6: { result = 'воскресенье'; break; }
            }
            return result;
        } else { return `Нормальное число введи!`; }
    }
    for (let i = 0; i < 9; i++) {
        alert(`getDayOfWeek(${i}) = ${getDayOfWeek(i)}`);
    }
}
