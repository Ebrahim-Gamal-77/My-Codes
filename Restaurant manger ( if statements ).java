

import java.util.Scanner;
import java.util.Arrays;

public class Program
{
    public static void main(String[] args) {
    
    // Take the orders and put it into array
        
        Scanner input = new Scanner(System.in);
        
        String orders = input.nextLine().toLowerCase();
        
        String[] ordersArr = orders.split(" ");
        
    // Meals prices ...
    
     float pizzaCost = 6.00F;
     float nachosCost = 6.00F;
     float cheeseburgerCost = 10.00F;
     float waterCost = 4.00F;
     float cokeCost = 5.00F;
     float tax = 7.00F / 100.00F;
     float totalPrice = 0;
        
    // Check if there are any undefined orders       
  
      for (int i = 0; i < ordersArr.length; i++) {
        
if (!ordersArr[i].equals("pizza"))
            {
if (!ordersArr[i].equals("nachos"))
            {
if (!ordersArr[i].equals("cheeseburger"))
            {
if (!ordersArr[i].equals("water"))
            {
if (!ordersArr[i].equals("coke"))
            {
               ordersArr[i] = "coke";         
            }       
            }        
            }    
            }
            }
           
        }
        
     // test inputs
                 
     /* System.out.println(ordersArr[0]);
      System.out.println(ordersArr[1]);
      System.out.println(ordersArr[2]);
      System.out.println(ordersArr[3]);
     */           

         
  // count the prices of every meal ..
    
        for (int i = 0; i < ordersArr.length; i++) {
            
            if (ordersArr[i].equals("pizza")) {
            
       totalPrice += pizzaCost ;  
            
    } else  if (ordersArr[i].equals("nachos")) {
    
       totalPrice += nachosCost ; 
    } else  if (ordersArr[i].equals("cheeseburger")) {
    
       totalPrice += cheeseburgerCost ; 
    } else  if (ordersArr[i].equals("water")) {
    
       totalPrice += waterCost ; 
    } else   if (ordersArr[i].equals("coke")) {
    
       totalPrice += cokeCost ; 
    }
    
}
    // Add the tax for total price
        
        totalPrice += tax * totalPrice;
        System.out.println(totalPrice);     
        
    }
}
