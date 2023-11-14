using System.Dynamic;
using System.Reflection.Metadata;
using System.Runtime.Serialization.Formatters;
using System.Security.Cryptography.X509Certificates;
using System.Text;

class ResearchTeam {
    private string Research_Theme;
    private string Organization;
    private int Registration_Number;
    private TimeFrame timeFrame;
    private Paper[] Papers = new Paper[0];

    public ResearchTeam() {
        this.Research_Theme = "Programming";
        this.Organization = "KSPEU";
        this.Registration_Number = 1000;
        this.timeFrame = TimeFrame.Year;
        this.Papers = new Paper[4] {new Paper(), new Paper(), new Paper("The Flash", new Person("Tom", "Cavanagh", new DateTime(1963, 10, 27)), new DateTime(2024, 10, 27)), new Paper()};
    }

    public ResearchTeam(string Research_Theme, string Organization, int Registration_Number, TimeFrame timeFrame) {
        this.Research_Theme = Research_Theme;
        this.Organization = Organization;
        this.Registration_Number = Registration_Number;
        this.timeFrame = timeFrame;
    }

    public string Theme {
        get {
            return this.Research_Theme;
        }
        set {
            this.Research_Theme = value;
        }
    }

    public string Company {
        get {
            return this.Organization;
        }
        set {
            this.Organization = value;
        }
    }

    public int RegNum {
        get {
            return this.Registration_Number;
        }
        set {
            this.Registration_Number = value;
        }
    }
    public TimeFrame FrameTime {
        get {
            return this.timeFrame;
        }
        set {
            this.timeFrame = value;
        }
    }

    public Paper[] PapersList {
        get {
            return this.Papers;
        }
        set {
            this.Papers = value;
        }
    }

    public Paper GetLastPaper {
        get {
            if (Papers.Length > 0) {
                Paper last = Papers[0];
                for (int i = 1; i < Papers.Length; i++) {
                    if (Papers[i].Publication_Date > last.Publication_Date) {
                        last = Papers[i];
                    }
                }
                return last;
            } else {
                return null;
            }
        }
    }

    public bool this[TimeFrame index] {
        get {
            return index == (TimeFrame)this.timeFrame;
        }
    }

    public void AddPapers(Paper[] AdditPapers) {
        Paper[] newPapers = new Paper[Papers.Length + AdditPapers.Length];
        Array.Copy(Papers, 0, newPapers, 0, Papers.Length);
        Array.Copy(AdditPapers, 0, newPapers, Papers.Length, AdditPapers.Length);
        this.Papers = newPapers;
    }

    public override string ToString() {
        int i = 1;
        string str_list = "\n";
        foreach (Paper paper in Papers) {
            str_list += $"\t {i++}) {paper}\n";
        }
        return $"Theme:\t{this.Research_Theme}\nOrganization:\t{this.Organization}\nRegistration Number:\t{this.Registration_Number}\nTimeFrame:\t{this.timeFrame}\nPapers:\t" + str_list;
    }
    public string ToShortString() {
        return $"Theme:\t{this.Research_Theme}\nOrganization:\t{this.Organization}\nRegistration Number:\t{this.Registration_Number}\nTimeFrame:\t{this.timeFrame}";
    }
}