public class Date implements Comparable<Date>{
    public int month, year, date;
    public Date(int d, int m, int y){
        month = m;
        date = d;
        year  = y;
    }

    public int compareTo(Date that){
        if(this.year<that.year) return -1;
        if(that.year<this.year) return 1;
        if(this.month<that.month) return -1;
        if(that.month<this.month) return 1;
        if(this.date<that.date) return -1;
        if(that.date<this.date) return 1;
        return 0;
    }
}