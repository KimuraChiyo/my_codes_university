// task 1
{
    function Airplane(name) {
        this.name = name,
        this.flies = false
    }

    Airplane.prototype.take_off = function() {
        if (!(this.flies)) this.flies = true;
    }
    Airplane.prototype.land = function() {
        if (this.flies) this.flies = false;
    }

    console.log(Airplane.prototype['land'])
    console.log(Airplane.prototype['take_off'])
}