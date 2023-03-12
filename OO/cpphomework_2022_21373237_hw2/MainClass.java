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

    public static void createEquipment(Scanner scanner, HashMap<Integer, Adventure> adventures) {
        int advId = scanner.nextInt();
        int equipmentType = scanner.nextInt();
        int id = scanner.nextInt();
        String name = scanner.next();
        long price = scanner.nextLong();
        double capacity;
        double efficiency;
        double expRatio;
        double sharpness;
        double extraExpBonus;
        double evolveRatio;
        if (equipmentType >= 1 && equipmentType <= 3) {
            capacity = scanner.nextDouble();
            if (equipmentType == 2) {
                efficiency = scanner.nextDouble();
                adventures.get(advId).getEquipments().
                        put(id, new HealingPotion(id, name, price, capacity, efficiency));
            } else if (equipmentType == 3) {
                expRatio = scanner.nextDouble();
                adventures.get(advId).getEquipments().
                        put(id, new ExpBottle(id, name, price, capacity, expRatio));
            } else {
                adventures.get(advId).getEquipments().
                        put(id, new Bottle(id, name, price, capacity));
            }
        }
        if (equipmentType >= 4 && equipmentType <= 6) {
            sharpness = scanner.nextDouble();
            if (equipmentType == 5) {
                extraExpBonus = scanner.nextDouble();
                adventures.get(advId).getEquipments().
                        put(id, new RareSword(id, name, price, sharpness, extraExpBonus));
            } else if (equipmentType == 6) {
                evolveRatio = scanner.nextDouble();
                adventures.get(advId).getEquipments().
                        put(id, new EpicSword(id, name, price, sharpness, evolveRatio));
            } else {
                adventures.get(advId).getEquipments().
                        put(id, new Sword(id, name, price, sharpness));
            }
        }
    }

    public static void sumPrice(Scanner scanner, HashMap<Integer, Adventure> adventures) {
        int advId = scanner.nextInt();
        HashMap<Integer, Equipment> a = adventures.get(advId).getEquipments();
        BigInteger sum = new BigInteger("0");
        for (Equipment value : a.values()) {
            BigInteger temp = BigInteger.valueOf(value.getPrice());
            sum = sum.add(temp);
        }
        System.out.println(sum);
    }

    public static void maxPrice(Scanner scanner, HashMap<Integer, Adventure> adventures) {
        int advId = scanner.nextInt();
        HashMap<Integer, Equipment> a = adventures.get(advId).getEquipments();
        long maxPrice = 0;
        for (Equipment value : a.values()) {
            if (value.getPrice() > maxPrice) {
                maxPrice = value.getPrice();
            }
        }
        System.out.println(maxPrice);
    }

    public static void sumCount(Scanner scanner, HashMap<Integer, Adventure> adventures) {
        int advId = scanner.nextInt();
        System.out.println(adventures.get(advId).getEquipments().size());
    }

    public static void select(int m, Scanner scanner) {
        HashMap<Integer, Adventure> adventures = new HashMap<>();
        for (int i = 0; i < m; i++) {
            int op = scanner.nextInt();
            if (op == 1) {
                createAdventure(scanner, adventures);
            } else if (op == 2) {
                createEquipment(scanner, adventures);
            } else if (op == 3) {
                int advId = scanner.nextInt();
                int equipmentId = scanner.nextInt();
                adventures.get(advId).getEquipments().remove(equipmentId);
            } else if (op == 4) {
                sumPrice(scanner, adventures);
            } else if (op == 5) {
                maxPrice(scanner, adventures);
            } else if (op == 6) {
                sumCount(scanner, adventures);
            } else if (op == 7) {
                adventures.get(scanner.nextInt()).getEquipments().get(scanner.nextInt()).print();
            } else if (op == 8) {
                int advId = scanner.nextInt();
                int equipmentId = scanner.nextInt();
                adventures.get(advId).use(adventures.get(advId).getEquipments().get(equipmentId));
            } else if (op == 9) {
                int advId = scanner.nextInt();
                adventures.get(advId).print();
            }
        }
    }
}
