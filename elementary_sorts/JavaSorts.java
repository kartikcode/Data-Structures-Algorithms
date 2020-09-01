import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class JavaSorts {
  public static void main(String[] args) {
    /*
     * Integer class implements Comparable
     * Using inbuilt methods in Java to sort basic data types
     */
    int[] arr = {11,55,22,0,89};
    Arrays.sort(arr);
    System.out.print("Sorted Int Array: ");
    System.out.println(Arrays.toString(arr));

    /*
     * Integer class implements Comparable
     */

    System.out.println("Sorted String arrays");
    String[] names = {"kartikcode","guptakar20","gkartik"};
    Arrays.sort(names);
    System.out.println(Arrays.toString(names));
  }
}

    