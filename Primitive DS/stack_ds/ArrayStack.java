/*
 * The following code contains the implementation of Stack data structure through arrays.
 * Here, the maximum capacity of the size of the stack is known and taken through client.
 */

import java.util.Scanner;
public class ArrayStack{
    private String stack[];
    private int pointer = -1;

    public ArrayStack(int n){
        stack = new String[n];
    }

    public boolean isEmpty(){
        return (pointer==-1);
    }

    public String pop(){
        if(isEmpty()) return "Invalid operation on empty stack";
        String item = stack[pointer];
        stack[pointer--] = null;
        return item;
    }

    public void push(String item){
        stack[++pointer] = item;
    }

    public static void main(String args[]){
        Scanner myScan = new Scanner(System.in);
        int n = myScan.nextInt();
        ArrayStack myStack = new ArrayStack(n);
        for(int i=0;i<args.length;i++){
             String item = args[i];
             //System.out.println(item);
            if( item.equals("-")){
                String popped = myStack.pop();
                System.out.println(popped);       
            }
            else{
                myStack.push(item);
            }
        }
    }

}