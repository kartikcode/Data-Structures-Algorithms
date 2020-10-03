import java.util.ArrayList;   
import java.util.Collections;

public class InterfaceSorts{  

   public static void main(String args[]){  
      // List of objects of Author class
      ArrayList<Date> birthdays=new ArrayList<Date>(); 
      birthdays.add(new Date(21,02,1967));  
      birthdays.add(new Date(01,10,1970));
      birthdays.add(new Date(04,01,1997));
      birthdays.add(new Date(20,02,2001));
      
      /*
       * Sorting the list using Collections.sort() method, we
       * can use this method because we have implemented the 
       * Comparable interface in our user defined class Date
       */
      Collections.sort(birthdays);  
      for(Date date:birthdays){  
    	  System.out.println(date.date+" / "+
          date.month+" / "+date.year);  
      } 
   }  
}  