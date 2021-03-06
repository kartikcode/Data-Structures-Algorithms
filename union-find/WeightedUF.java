import java.util.Scanner;

public class WeightedUF{
    private static int[] id;
    private static int[] size;
    public static void initialize(int N){
        id = new int[N+1];
        size = new int[N+1];
        for(int i=0;i<=N;i++){
            id[i] = i;
            size[i] = 1;
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
        if(proot==qroot) return;
        if(size[proot]>size[qroot]){
            id[qroot] = proot;
            size[proot]+=size[qroot];
        }
        else{
            id[proot] = qroot;
            size[qroot]+=size[proot];
        }
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