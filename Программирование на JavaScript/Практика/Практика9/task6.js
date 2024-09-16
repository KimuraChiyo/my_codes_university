// task 6
{
    function isValidURL(URL) {
        let regex = /http[s]?:\/\/www.[a-z]+.(ru|com)/g;
        return regex.test(URL)
    }
    alert(isValidURL('https:\/\/www.yandex.ru'));
    alert(isValidURL('http:\/\/www.yandex.ru'));
    alert(isValidURL('https:\/\/www.google.com'));
    alert(isValidURL('http:\/\/www.mangalib.me'));
}
