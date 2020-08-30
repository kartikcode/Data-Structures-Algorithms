/* *****************************************************************************
 *  Name: Kartikeya Gupta
 *  Date: 30/08/2020
 *  Description: Randomized Queue assignment
 **************************************************************************** */

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class RandomizedQueue<Item> implements Iterable<Item> {
    private Item[] Queue;
    private int listSize;
    private int last;

    // construct an empty randomized queue
    public RandomizedQueue() {
        Queue = (Item[]) new Object[2];
        last = 0;
        listSize = 0;
    }

    // is the queue empty?
    public boolean isEmpty() {
        return listSize == 0;
    }

    // return the number of items on the queue
    public int size() {
        return listSize;
    }

    // resize the underlying array
    private void resize(int max) {
        assert max >= listSize;

        Item[] temp = (Item[]) new Object[max];
        int templast = 0;

        for (int i = 0; i < last; i++) {
            if (Queue[i] != null) {
                temp[templast] = Queue[i];
                templast++;
            }
        }

        Queue = temp;
        last = templast;
    }

    // add the item
    public void enqueue(Item item) {
        if (item == null) {
            throw new NullPointerException();
        }

        // double size of array if necessary and recopy to front of array
        if (last == q.length - 1) {
            resize(2 * q.length);   // double size of array if necessary
        }

        Queue[last] = item;
        last++;

        listSize++;
    }

    // delete and return a random item
    public Item dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue underflow");
        }

        Item item = null;
        while (item == null) {
            int r = StdRandom.uniform(last);
            item = Queue[r];
            Queue[r] = null;  // avoid loitering
        }
        assert item != null;
        listSize--;

        // shrink size of array if necessary
        if (N > 0 && listSize == Queue.length / 4) {
            resize(Queue.length / 2);
        }

        return item;
    }

    // return (but do not delete) a random item
    public Item sample() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue underflow");
        }

        Item item = null;

        while (item == null) {
            int r = StdRandom.uniform(last);
            item = Queue[r];
        }
        assert item != null;

        return item;
    }

    // return an independent iterator over items in random order
    public Iterator<Item> iterator() {
        return new ArrayIterator();
    }

    private class ArrayIterator implements Iterator<Item> {
        private int i;  // number of items returned
        private int o;  // index to the random order array
        private int[] order;

        public ArrayIterator() {
            i = 0;
            order = new int[last];

            for (int j = 0; j < last; j++) {
                order[j] = j;
            }

            StdRandom.shuffle(order);
        }

        public boolean hasNext() {
            return i < listSize;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }

        public Item next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }

            Item item = null;
            while (item == null) {
                item = Queue[order[o]];
                o++;
            }
            i++;
            assert item != null;
            return item;
        }
    }

    // unit testing
    public static void main(String[] args) {
        RandomizedQueue<Integer> Queue = new RandomizedQueue<Integer>();
        int i;

        for (i = 0; i < 50; i++) {
            Queue.enqueue(i);
            assert Queue.size() == i + 1;
        }

        i = Queue.dequeue();
        StdOut.println("deque: " + i);
        assert Queue.size() == 49;

        for (i = 0; i < 5; i++) {
            StdOut.println("sample: " + Queue.sample());
        }

        for (i = 0; i < 40; i++) {
            Queue.dequeue();
        }

        Queue = new RandomizedQueue<Integer>();
        for (i = 0; i < 20; i++) {
            Queue.enqueue(i);
        }

        for (int j : q) {
            StdOut.println(j);
        }
    }
}
