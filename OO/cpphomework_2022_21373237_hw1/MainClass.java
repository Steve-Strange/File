import java.util.Scanner;
import java.util.HashMap;
import java.math.BigInteger;

public class MainClass {

    public static void main(String[] argv) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        select(m, scanner);
    }

    public static void createAdventure(Scanner scanner, HashMap<Integer, Adventure> adventures) {
        int advId = scanner.nextInt();
        String name = scanner.next();
        adventures.put(advId, new Adventure(advId, name));
    }

    public static void createBottle(Scanner scanner, HashMap<Integer, Adventure> adventures) {
        int advId = scanner.nextInt();
        int botId = scanner.nextInt();
        String name = scanner.next();
        long price = scanner.nextLong();
        double capacity = scanner.nextDouble();
        adventures.get(advId).getBottles().
                put(botId, new Bottle(botId, name, price, capacity));
    }

    public static void printInfo(Scanner scanner, HashMap<Integer, Adventure> adventures) {
        int advId = scanner.nextInt();
        int botId = scanner.nextInt();
        Bottle a = adventures.get(advId).getBottles().get(botId);
        System.out.format("The bottle's id is %d, name is %s," +
                        " capacity is %f, filled is %b.\n",
                a.getId(), a.getName(), a.getCapacity(), a.isFilled());
    }

    public static void sumPrice(Scanner scanner, HashMap<Integer, Adventure> adventures) {
        int advId = scanner.nextInt();
        HashMap<Integer, Bottle> a = adventures.get(advId).getBottles();
        BigInteger sum = new BigInteger("0");
        for (Bottle value : a.values()) {
            BigInteger temp = BigInteger.valueOf(value.getPrice());
            sum = sum.add(temp);
        }
        System.out.println(sum);
    }

    public static void maxPrice(Scanner scanner, HashMap<Integer, Adventure> adventures) {
        int advId = scanner.nextInt();
        HashMap<Integer, Bottle> a = adventures.get(advId).getBottles();
        long maxPrice = 0;
        for (Bottle value : a.values()) {
            if (value.getPrice() > maxPrice) {
                maxPrice = value.getPrice();
            }
        }
        System.out.println(maxPrice);
    }

    public static void select(int m, Scanner scanner) {
        HashMap<Integer, Adventure> adventures = new HashMap<>();
        for (int i = 0; i < m; i++) {
            int op = scanner.nextInt();
            if (op == 1) {
                createAdventure(scanner, adventures);
            } else if (op == 2) {
                createBottle(scanner, adventures);
            } else if (op == 3) {
                int advId = scanner.nextInt();
                int botId = scanner.nextInt();
                adventures.get(advId).getBottles().remove(botId);
            } else if (op == 4) {
                int advId = scanner.nextInt();
                int botId = scanner.nextInt();
                long price = scanner.nextLong();
                adventures.get(advId).getBottles().get(botId).setPrice(price);
            } else if (op == 5) {
                int advId = scanner.nextInt();
                int botId = scanner.nextInt();
                boolean filled = scanner.nextBoolean();
                adventures.get(advId).getBottles().get(botId).setFilled(filled);
            } else if (op == 6) {
                int advId = scanner.nextInt();
                int botId = scanner.nextInt();
                System.out.println(adventures.get(advId).getBottles().get(botId).getName());
            } else if (op == 7) {
                int advId = scanner.nextInt();
                int botId = scanner.nextInt();
                System.out.println(adventures.get(advId).getBottles().get(botId).getPrice());
            } else if (op == 8) {
                int advId = scanner.nextInt();
                int botId = scanner.nextInt();
                System.out.println(adventures.get(advId).getBottles().get(botId).getCapacity());
            } else if (op == 9) {
                int advId = scanner.nextInt();
                int botId = scanner.nextInt();
                System.out.println(adventures.get(advId).getBottles().get(botId).isFilled());
            } else if (op == 10) {
                printInfo(scanner, adventures);
            } else if (op == 11) {
                sumPrice(scanner, adventures);
            } else {
                maxPrice(scanner, adventures);
            }
        }
    }
}
