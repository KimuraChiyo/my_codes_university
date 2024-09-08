// task 7
{
    function func(num) {
        if (num >= 1 && num <= 100) {
            switch (num % 10) {
                case 1: {
                    num += (num == 11) ? 'th' : 'st';
                    break;
                }
                case 2: {
                    num += (num == 12) ? 'th' : 'nd';
                    break;
                }
                case 3: {
                    num += (num == 13) ? 'th' : 'rd';
                    break;
                }
                default: {
                    num += 'th';
                }
            }
        }
        return num;
    }

    alert(func(1));
    alert(func(2));
    alert(func(3));
    alert(func(11));
    alert(func(12));
    alert(func(13));
    alert(func(20));
    alert(func(36));
}