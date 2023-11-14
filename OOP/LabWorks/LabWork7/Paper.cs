class Paper {
    public string Publication_Name { get; set; }
    public Person Author { get; set; }
    public DateTime Publication_Date { get; set; }

    public Paper(string Publication_Name, Person Author, DateTime Publication_Date) {
        this.Publication_Name = Publication_Name;
        this.Author = Author;
        this.Publication_Date = Publication_Date;
    }

    public Paper() {
        this.Publication_Name = "Hello, world!";
        this.Author = new Person();
        this.Publication_Date = DateTime.Now;
    }

    override public string ToString() {
        return $"Publication '{Publication_Name}' was created {Publication_Date} by {Author.ToShortString()}";
    }
    
}