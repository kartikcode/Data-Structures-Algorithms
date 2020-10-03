/*
 * The following code contains the implementation of Stack data structure through arrays.
 * Here, the maximum capacity of the size of the stack is known and taken through client.
 */

import java.util.Scanner;
public class ResizeArrayStack{
    private String stack[];
    private int pointer = -1;

    public ResizeArrayStack(){
        stack = new String[1];
    }

    public boolean isEmpty(){
        return (pointer==-1);
    }

    public void resize (int size){
        String[] newStack = new String[size];
        for(int i=0;i<stack.length;i++){
            if(stack[i]==null) break;
            newStack[i] = stack[i];
        }
        stack = newStack;
    }

    public String pop(){
        if(isEmpty()) return "Invalid operation on empty stack";
        String item = stack[pointer];
        stack[pointer] = null;
        if((stack.length)>=(pointer*4)){
            resize((stack.length)/2);
        }
        pointer--;
        return item;
    }

    public void push(String item){
        pointer++;
        if(pointer==stack.length){
            resize(pointer*2);
        }
        stack[pointer]= item;
    }

    public static void main(String args[]){
        Scanner myScan = new Scanner(System.in);
        int n = myScan.nextInt();
        ResizeArrayStack myStack = new ResizeArrayStack();
        for(int i=0;i<args.length;i++){
             String item = args[i];
            if( item.equals("-")){
                String popped = myStack.pop();
                System.out.println(popped);       
            }
            else{
                myStack.push(item);
            }
            //System.out.println(myStack.pointer);
        }
    }

}