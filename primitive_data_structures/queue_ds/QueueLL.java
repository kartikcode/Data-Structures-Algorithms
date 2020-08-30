/*
 * The following code contains the implementation of Queue data structure through linked lists.
 * Queue follows the concept of FIFO : First In First Out
 */

import java.util.Scanner;
public class QueueLL{
    private Node first = null;
    private Node last = null;
    private class Node{
        String item;
        Node next;
    }

    public boolean isEmpty(){
        return (first==null);
    }

    public void enqueue(String item){
        Node next_node = new Node();
        next_node.item = item;
        if(isEmpty()){
            last = next_node;
            first = next_node;
            return;
        }
        last.next = next_node;
        last = next_node;
    }

    public String dequeue(){
        String item = first.item;
        first = first.next;
        return item;
    }

    public static void main(String[] args){
        QueueLL myQueue = new QueueLL();
        for(int i=0;i<args.length;i++){
            String item = args[i];
            if(item.equals("-")){
                String popped = myQueue.dequeue();
                System.out.println(popped);
            }
            else{
                myQueue.enqueue(item);
            }
        }
    }
}
