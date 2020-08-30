/*
* The following code contains the implementation of Stack data structure through linked lists.
 */
import java.util.Scanner;

 public class StackLL{
    private Node first = null;

    private class Node{
        String item;
        Node next;
    }

    public boolean isEmpty(){
        return (first==null);
    }

    public void push( String next_string){
        Node oldfirst = new Node();
        oldfirst = first;
        first = new Node();
        first.item = next_string;
        first.next = oldfirst;
    }

    public String pop(){
        String item = first.item;
        first = first.next;
        return item;
    }

    public static void main(String args[]){
        StackLL myStack = new StackLL();
        int i=0;
        while(i<args.length){
            String item = args[i];
            //System.out.println(myStack.isEmpty());
            if( item.equals("-")){
                String popped = myStack.pop();
                System.out.println(popped);
            }
            else{
                myStack.push(item);
            }
            i++;
        }
    }

 }