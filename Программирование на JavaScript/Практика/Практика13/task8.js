// task 8
{
    let library = [
        {title: 'War and Peace', author: 'Leo Tolstoy', ID: 2},
        {title: 'Crime and Punishment', author: 'Fyodor Dostoevsky', ID: 1},
        {title: 'Fathers and Sons', author: 'Ivan Turgenev', ID: 3}
    ];
    console.log(library.sort((a, b) => a.ID - b.ID ))
}