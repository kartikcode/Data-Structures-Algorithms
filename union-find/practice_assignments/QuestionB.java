/*
    Question:
    Union-find with specific canonical element. Add a method find() to the union-find data type so that find(i)
    returns the largest element in the connected component containing i. The operations, union(), connected() and 
    find() should all take logarithmic time or better.
    For example, if one of the connected components is {1,2,6,9}, then the find() method should return 9 for each
    of the four elements in the connected components.
 */

import java.util.Scanner;

public class QuestionB{
    private static int[] id;
    private static int[] size;
    private static int[] canonical;

    public static void initialize(int N){
        id = new int[N+1];
        size = new int[N+1];
        canonical = new int[N+1];
        for(int i=0;i<=N;i++){
            id[i] = i;
            size[i] = 1;
            canonical[i] = i;
        }
    }

    public static int root(int i){ 
        while(id[i]!=i){
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }

    public static boolean connected(int p, int q){
        return root(p)==root(q);
    }

    public static void union(int p, int q){
        int proot = root(p);
        int qroot = root(q);
        if(proot==qroot) return ;
        if(size[proot]>size[qroot]){
            id[qroot] = proot;
            size[proot]+=size[qroot];
            canonical[proot] = Math.max(canonical[proot],canonical[qroot]);
        }
        else{
            id[proot] = qroot;
            size[qroot]+=size[proot];
            canonical[qroot] = Math.max(canonical[proot],canonical[qroot]);
        }
    }

    public static int find(int i){
        return canonical[root(i)];
    }

    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        int N = myObj.nextInt();
        int M = myObj.nextInt();
        initialize(N);
        for(int i=0;i<M;i++){
            int p = myObj.nextInt();
            int q = myObj.nextInt();   
            union(p,q);    
        }
        int i = myObj.nextInt();
        int ans = find(i);
        System.out.println(ans);
    }

}