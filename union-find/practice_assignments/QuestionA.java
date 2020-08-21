/*
    Question:
    Social network connectivity. Given a social network containing N members and a log file containing M timestamps
    at which times pairs of members formed friendships, design an algorithm to determine the earliest time at which 
    all members are connected (i.e., every member is a friend of a friend of a friend ... of a friend). 
    Assume that the log file is sorted by timestamp and that friendship is an equivalence relation. The running time 
    of your algorithm should be Mlog⁡N or better and use extra space proportional to N.
 */

import java.util.Scanner;

public class QuestionA{
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
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }

    public static boolean find(int p, int q){
        return root(p)==root(q);
    }

    public static boolean union(int p, int q, int N){
        int proot = root(p);
        int qroot = root(q);
        if(proot==qroot) return false;
        if(size[proot]>size[qroot]){
            id[qroot] = proot;
            size[proot]+=size[qroot];
            if(size[proot]==N) return true;
        }
        else{
            id[proot] = qroot;
            size[qroot]+=size[proot];
            if(size[qroot]==N) return true;
        }
        return false;
    }

    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        int N = myObj.nextInt();
        int M = myObj.nextInt();
        initialize(N);
        for(int i=0;i<M;i++){
            int time = myObj.nextInt();
            int p = myObj.nextInt();
            int q = myObj.nextInt();
            boolean check = union(p,q,N);
            if(check){
                System.out.println(time);
                break;
            }           
        }
    }

}