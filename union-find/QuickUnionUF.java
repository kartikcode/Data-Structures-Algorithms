import java.util.Scanner;

public class QuickUnionUF{
    private static int[] id;
    public static void initialize(int N){
        id = new int[N+1];
        for(int i=0;i<=N;i++){
            id[i] = i;
        }
    }

    public static int root(int i){ 
        while(id[i]!=i){
            i = id[i];
        }
        return i;
    }

    public static boolean find(int p, int q){
        return root(p)==root(q);
    }

    public static void union(int p, int q){
        int proot = root(p);
        int qroot = root(q);
        id[proot] = qroot;
    }

    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        int N = myObj.nextInt();
        int queries = myObj.nextInt();
        initialize(N);
        for(int i=0;i<queries;i++){
            int p = myObj.nextInt();
            int q = myObj.nextInt();
            union(p,q);
        }
    }

}