using System;
using System.ComponentModel;

class Person {
    private string name;
    // закрытое поле string для имени
    private string lastname;
    // закрытое поле string для фамилии
    private DateTime birthdate;
    // закрытое поле DateTime для даты рождения

    public Person() {
        this.name = "Name";
        this.lastname = "Lastname";
        this.birthdate = DateTime.Now;
    }

    public Person(string Name, string lastname, DateTime birthdate) {
        this.name = Name;
        this.lastname = lastname;
        this.birthdate = birthdate;
    }

    public string Name {
        get { 
            return this.name;
        }
        set {
            this.name = value;
        }
    }

    public string Lastname {
        get {
            return this.lastname; 
        }
        set {
            this.lastname = value; 
        }
    }

    public DateTime Birthdate {
        get { 
            return this.birthdate; 
        }
        set {
            this.birthdate = value; 
        }
    }

    public int Birthyear {
        get { 
            return this.birthdate.Year; 
        }
        set {
            this.birthdate = new DateTime(value, birthdate.Month, birthdate.Day); 
        }
    }

    override public string ToString() {
        return $"{this.name} {this.lastname} {this.birthdate}";
    }

    public string ToShortString() {
        return $"{this.name} {this.lastname}";
    }
}