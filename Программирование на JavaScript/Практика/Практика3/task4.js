// task 4
{
    function getDayOfWeek(dayNumber) {
        if (dayNumber >= 1 && dayNumber <= 7) {
            let result = '';
            switch ((dayNumber - 1) % 7) {
                case 0: {
                    result = 'понедельник';
                    break;
                }
                case 1: {
                    result = 'вторник';
                    break;
                }
                case 2: {
                    result = 'среда';
                    break;
                }
                case 3: {
                    result = 'четверг';
                    break;
                }
                case 4: {
                    result = 'пятница';
                    break;
                }
                case 5: {
                    result = 'суббота';
                    break;
                }
                case 6: {
                    result = 'воскресенье';
                    break;
                }
            }
            return result;
        } else {
            return `Нормальное число введи!`;
        }
    }
    alert(`getDayOfWeek(0) = ${getDayOfWeek(0)}`);
    alert(`getDayOfWeek(1) = ${getDayOfWeek(1)}`);
    alert(`getDayOfWeek(2) = ${getDayOfWeek(2)}`);
    alert(`getDayOfWeek(3) = ${getDayOfWeek(3)}`);
    alert(`getDayOfWeek(4) = ${getDayOfWeek(4)}`);
    alert(`getDayOfWeek(5) = ${getDayOfWeek(5)}`);
    alert(`getDayOfWeek(6) = ${getDayOfWeek(6)}`);
    alert(`getDayOfWeek(7) = ${getDayOfWeek(7)}`);
    alert(`getDayOfWeek(8) = ${getDayOfWeek(8)}`);
}