/* *****************************************************************************
 *  Name: Kartikeya Gupta
 *  Date: 30/08/2020
 *  Description: Deque assignment
 **************************************************************************** */

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {

    private class Node {
        Item item;
        Node next;
        Node prev;
    }

    private Node first;
    private Node last;
    private int listSize = 0;

    // construct an empty deque
    public Deque() {
        first = new Node();
        last = new Node();
    }

    // is the deque empty?
    public boolean isEmpty() {
        return (listSize == 0);
    }

    // return the number of items on the deque
    public int size() {
        return listSize;
    }

    // add the item to the front
    public void addFirst(Item item) {
        if (item == null) {
            throw new IllegalArgumentException();
        }
        if (listSize == 0) {
            Node newFirst = new Node();
            newFirst.item = item;
            first = newFirst;
            last = newFirst;
            listSize++;
            return;
        }
        listSize++;
        Node newFirst = new Node();
        newFirst.item = item;
        newFirst.next = first;
        first.prev = newFirst;
        first = newFirst;
    }

    // add the item to the back
    public void addLast(Item item) {
        if (item == null) {
            throw new IllegalArgumentException();
        }
        if (listSize == 0) {
            Node newFirst = new Node();
            newFirst.item = item;
            first = newFirst;
            last = newFirst;
            listSize++;
            return;
        }
        listSize++;
        Node newLast = new Node();
        newLast.item = item;
        last.next = newLast;
        newLast.prev = last;
        last = newLast;
    }

    // remove and return the item from the front
    public Item removeFirst() {
        if (listSize == 0) {
            throw new NoSuchElementException("Queue is empty.");
        }
        listSize--;
        Item item = first.item;
        first = first.next;
        return item;
    }

    // remove and return the item from the back
    public Item removeLast() {
        if (listSize == 0) {
            throw new NoSuchElementException("Queue is empty.");
        }
        listSize--;
        Item item = last.item;
        last = last.prev;
        return item;
    }

    // return an iterator over items in order from front to back
    public Iterator<Item> iterator() {
        return new ListIterator();
    }

    private class ListIterator implements Iterator<Item> {
        private Node current = first;

        public boolean hasNext() {
            if (listSize < 2) {
                return false;
            }
            return current.next != null;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }

        public Item next() {
            if (!hasNext()) {
                throw new NoSuchElementException("Iterator reached end");
            }
            Item item = current.item;
            current = current.next;
            return item;
        }
    }

    // unit testing (required)
    public static void main(String[] args) {
        /*
         * Client code
         *
         * */
    }

}
