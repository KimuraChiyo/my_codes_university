// task 1
{
    let user = new Object();
    alert(`user = ${user}`);
    user.name = 'John';
    alert(`user.name = ${user.name}`);
    user.surname = 'Smith';
    alert(`user.surname = ${user.surname}`);
    user.name = 'Pete';
    alert(`user.name = ${user.name}`);
    delete user.name;
    alert(`user.name = ${user.name}`);
}