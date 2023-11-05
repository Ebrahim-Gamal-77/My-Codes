import java.util.HashMap;
import java.util.Scanner;

public class Program {
    public static void main(String[] args) {
        // Meals prices ...
        float pizzaCost = 6.00F;
        float nachosCost = 6.00F;
        float cheeseburgerCost = 10.00F;
        float waterCost = 4.00F;
        float cokeCost = 5.00F;
        float tax = 7.00F / 100.00F;
        float totalPrice = 0;

        HashMap<String, Float> prices = new HashMap<>();
        prices.put("pizza", pizzaCost);
        prices.put("nachos", nachosCost);
        prices.put("cheeseburger", cheeseburgerCost);
        prices.put("water", waterCost);
        prices.put("coke", cokeCost);

        // Take the orders and put it into array

        Scanner input = new Scanner(System.in);

        String[] orders = input.nextLine().split(" ");

        HashMap<String, Integer> order = new HashMap<>();

        for (String item : orders) {
            item = item.toLowerCase();
            if (!prices.containsKey(item)) {
                item = "coke";
            }

            if (!order.containsKey(item)) {
                order.put(item, 0);
            }

            order.put(item, order.get(item) + 1);
        }

        // Check if there are any undefined orders
        for (var item : order.entrySet()) {
            totalPrice += prices.get(item.getKey()) * item.getValue();
        }

        totalPrice += tax * totalPrice;
        System.out.println(totalPrice);

        input.close();
    }
}

