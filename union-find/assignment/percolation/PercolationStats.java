/* *****************************************************************************
 *  Name:              Kartikeya Gupta
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {
    private final double[] records;
    private final double t;

    public PercolationStats(int n, int trials) {
        records = new double[trials];
        t = trials;
        for (int i = 0; i < trials; i++) {
            Percolation obj = new Percolation(n);
            while (!obj.percolates()) {
                int row = StdRandom.uniform(1, n + 1);
                int col = StdRandom.uniform(1, n + 1);
                obj.open(row, col);
            }
            double openCells = obj.numberOfOpenSites();
            records[i] = openCells / (n * n);
        }
    }

    // sample mean of percolation threshold
    public double mean() {
        return StdStats.mean(records);
    }

    // sample standard deviation of percolation threshold
    public double stddev() {
        return StdStats.stddev(records);
    }

    // low endpoint of 95% confidence interval
    public double confidenceLo() {
        double stdDeviation = stddev();
        double denom = Math.sqrt(t);
        double toSub = (2.576d) * stdDeviation;
        toSub /= denom;
        return (mean() - toSub);
    }

    // high endpoint of 95% confidence interval
    public double confidenceHi() {
        double stdDeviation = stddev();
        double denom = Math.sqrt(t);
        double toSub = (2.576d) * stdDeviation;
        toSub /= denom;
        return (mean() + toSub);
    }

    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int trials = Integer.parseInt(args[1]);
        PercolationStats myObj = new PercolationStats(n, trials);
        StdOut.println(
                "mean                    = " + myObj.mean());
        StdOut.println(
                "stddev                  = " + myObj.stddev());
        StdOut.println(
                "95% confidence interval = [" + myObj.confidenceLo() + ", " + myObj.confidenceHi()
                        + "]");
    }
}
