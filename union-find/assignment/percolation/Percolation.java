/* *****************************************************************************
 *  Name:              Kartikeya Gupta
 *  Coursera User ID:  123456
 *  Last modified:     22/8/2020
 **************************************************************************** */

import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    // creates n-by-n grid, with all sites initially blocked
    private int[][] grid;
    private int openSites = 0;
    private final int num;
    private final WeightedQuickUnionUF uf;

    public Percolation(int n) {
        grid = new int[n][n];
        uf = new WeightedQuickUnionUF((n * n) + 2);
        num = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = 0;
            }
        }
    }

    // open the site (row,col)
    public void open(int row, int col) {
        row--;
        col--;
        if (grid[row][col] == 0) {
            grid[row][col] = 1;
            openSites++;
            int a = ((row) * num) + col;
            if (isOpen(row, col + 1)) {
                int b = a - num;
                uf.union(a, b);
            }
            if (isOpen(row + 2, col + 1)) {
                int b = a + num;
                uf.union(a, b);
            }
            if (isOpen(row + 1, col + 2)) {
                int b = a + 1;
                uf.union(a, b);
            }
            if (isOpen(row + 1, col)) {
                int b = a - 1;
                uf.union(a, b);
            }
            if (row == 0) {
                uf.union(((num * num) + 1), col);
            }
            if (row == (num - 1)) {
                uf.union((num * num), (num * (num - 1)) + col);
            }
        }
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col) {
        row--;
        col--;
        if ((row > (num - 1)) || (row < 0)) return false;
        if ((col > (num - 1)) || (col < 0)) return false;
        return (grid[row][col] == 1);
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col) {
        row--;
        col--;
        return (uf.find(((num * num) + 1)) == uf.find((row) * num + col));
    }

    // returns the number of open sites
    public int numberOfOpenSites() {
        return openSites;
    }

    // does the system percolate?
    public boolean percolates() {
        return (uf.find(((num * num) + 1)) == uf.find((num * num)));
    }

    // test client (optional)
    public static void main(String[] args) {
        /*
         * Commented added
         * for client test only
         * */
    }
}
