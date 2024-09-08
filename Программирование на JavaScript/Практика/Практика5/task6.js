// task 6
{
    function Seller(name, itemsSold) {
        this.name = name;
        this.itemsSold = itemsSold;

        this.sell = function(something) {
            this.itemsSold++;
            return `Менеджер ${this.name} продал ${something}. Теперь у него ${this.itemsSold} продаж`;
        }
    }
    
    let manager = new Seller('Adam', 0);
    alert(manager.sell('товар1'));
    alert(manager.sell('товар2'));
}