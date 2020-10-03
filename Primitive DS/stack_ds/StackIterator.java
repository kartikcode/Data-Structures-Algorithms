/* 
 * This file contains the implementation of the generic stacks through linked lists.
 * Generic classes allow the programmers to have a single method class declaration for various object types.
 */

import java.util.Scanner;
import java.util.Iterator;

 public class GenericStackLL<Item> implements Iterable<Item>{
    private Node first = null;

    private class Node{
        Item item;
        Node next;
    }

    public boolean isEmpty(){
        return (first==null);
    }

    public void push( Item next_item){
        Node oldfirst = new Node();
        oldfirst = first;
        first = new Node();
        first.item = next_item;
        first.next = oldfirst;
    }

    public Item pop(){
        Item item = first.item;
        first = first.next;
        return item;
    }

    public Iterator<Item> iterator(){ return new ListIterator();}

    private class ListIterator implements Iterator<Item>{
        private Node current = first;

        public boolean hasNext(){
            return current!=null;
        }
        public Item next(){
            Item item = current.item;
            current = current.next();
            return item;
        }
    }

    public static < Item > void main(String args[]){
        GenericStackLL<Item> myStack = new GenericStackLL<Item>();
        for(int i=0;i<args.length;i++){
            Item item = (Item)args[i];
            //System.out.println(myStack.isEmpty());
            Item popsignal = (Item)"-";
            if( item.equals(popsignal)){
                Item popped = myStack.pop();
                System.out.println(popped);
            }
            else{
                myStack.push(item);
            }
        }
    }

 }