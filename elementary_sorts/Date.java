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

    /*
     * Helper Functions
     */
    
    private static boolean less (Comparable v, Comparable w){
        return v.compareTo(w) < 0;
    }

    private static void exch(Comparable[] a, int i, int j){
        Comparable temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    private static boolean isSorted(Comparable a[]){
        for(int i=1;i<a.length;i++){
            if(less(a[i],a[i-1])){
                return false;
            }
        }
        return true;
    }
}