import java.util.Scanner;

public class QuickFindUF{
    private static int[] id;

    public static void initialize(int N){
        id = new int[N+1];
        for(int i=0;i <= N;i++){
            id[i] = i;
        }
    }

    public static boolean find(int p, int q){
        return (id[p]==id[q]);
    }

    public static void union(int p, int q, int N){
        int pid = id[p];
        int qid = id[q];
        for(int i=0;i<=N;i++){
            if(id[i]==pid) id[i] = qid;
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
            union(p,q,N);
        }
    }
 }