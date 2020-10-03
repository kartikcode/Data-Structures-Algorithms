/* *****************************************************************************
 *  Name: Kartikeya Gupta
 *  Date: 30/08/2020
 *  Description: Permutations assignment
 **************************************************************************** */

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class Permutation {
    public static void main(String[] args) {
        RandomizedQueue<String> myQ = new RandomizedQueue<String>();
        int x = Integer.parseInt(args[0]);
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            myQ.enqueue(item);
        }
        for (int i = 0; i < x; i++) {
            String item = myQ.dequeue();
            StdOut.println(item);
        }
    }
}
