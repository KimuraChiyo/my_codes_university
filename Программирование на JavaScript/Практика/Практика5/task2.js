// task 2
{
    let obj_A = {
        valueOf() {
            return 22;
        }
    };
    let obj_B = {
        valueOf() {
            return 33;
        }
    };
    alert(obj_A + obj_B)
}