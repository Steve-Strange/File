import java.util.Scanner;
import java.util.HashMap;
import java.math.BigInteger;
import java.util.ArrayList;

public class Branch {

    private HashMap<Integer, Adventurer> adventurers;
    private String name;

    Branch(String name, HashMap<Integer, Adventurer> adventures) {
        this.name = name;
        HashMap<Integer, Adventurer> newAdventures = new HashMap<Integer, Adventurer>();
        

        // public Branch branchClone(String name) {
        //     HashMap<Integer, Adventurer> newAdventurers = new HashMap<>();
    
        //     for (Adventurer adventurer : this.adventurers.values()) {
        //         Adventurer clone = new Adventurer(adventurer.getId(),adventurer.getName());
        //         clone.setExp(adventurer.getExp());
        //         clone.setHealth(adventurer.getHealth());
        //         clone.setMoney(adventurer.getMoney());
        //         ArrayList<Commodity> newCommodities = new ArrayList<Commodity>();
        //         for(Commodity c : adventurer.getCommodities()) {
        //             if(c instanceof Equipment) {
        //                 Commodity temp =((Equipment)c).deepClone();
        //                 newCommodities.add(temp);
        //             }
        //             else if(c instanceof Adventurer) {
        //                 Adventurer temp = (Adventurer)c;
        //                 newCommodities.add(temp);
        //             }
        //         }
        //     }
    
        //     return new Branch(name, newAdventurers);
        }
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public HashMap<Integer, Adventurer> getAdventurers() {
        return adventurers;
    }

    public void select(int op, Scanner scanner) {
        switch (op) {
            case 1 : createAdventure(scanner);
                break;
            case 2 : addEquipment(scanner);
                break;
            case 3 : removeCommodity(scanner);
                break;
            case 4 : sumPrice(scanner);
                break;
            case 5 : maxPrice(scanner);
                break;
            case 6 : sumCount(scanner);
                break;
            case 7 : printComInfo(scanner);
                break;
            case 8 : useAll(scanner);
                break;
            case 9 : printAdvInfo(scanner);
                break;
            case 10 : hire(scanner);
                break;
            default: break;
        }
    }
    
    /*------------Operation------------*/

    public void createAdventure(Scanner scanner) {
        int advId = scanner.nextInt();
        String name = scanner.next();
        adventurers.put(advId, new Adventurer(advId, name));
    }

    public void addEquipment(Scanner scanner) {
        int advId = scanner.nextInt();
        int equipmentType = scanner.nextInt();
        int id = scanner.nextInt();
        String name = scanner.next();
        BigInteger price = scanner.nextBigInteger();
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
                adventurers.get(advId).getCommodities().add(id, new HealingPotion(id, name, price, capacity, efficiency));
            } else if (equipmentType == 3) {
                expRatio = scanner.nextDouble();
                adventurers.get(advId).getCommodities().add(id, new ExpBottle(id, name, price, capacity, expRatio));
            } else {
                adventurers.get(advId).getCommodities().add(id, new Bottle(id, name, price, capacity));
            }
        }
        if (equipmentType >= 4 && equipmentType <= 6) {
            sharpness = scanner.nextDouble();
            if (equipmentType == 5) {
                extraExpBonus = scanner.nextDouble();
                adventurers.get(advId).getCommodities().add(id, new RareSword(id, name, price, sharpness, extraExpBonus));
            } else if (equipmentType == 6) {
                evolveRatio = scanner.nextDouble();
                adventurers.get(advId).getCommodities().add(id, new EpicSword(id, name, price, sharpness, evolveRatio));
            } else {
                adventurers.get(advId).getCommodities().add(id, new Sword(id, name, price, sharpness));
            }
        }
    }

    public void removeCommodity(Scanner scanner) {
        int advId = scanner.nextInt();
        int commodityId = scanner.nextInt();
        adventurers.get(advId).getCommodities().remove(commodityId);
    }

    public void sumPrice(Scanner scanner) {
        int advId = scanner.nextInt();
        ArrayList<Commodity> commodities = adventurers.get(advId).getCommodities();
        BigInteger sum = new BigInteger("0");
        for (Commodity value : commodities) {
            sum = sum.add(value.getPrice());
        }
        System.out.println(sum);
    }

    public void maxPrice(Scanner scanner) {
        int advId = scanner.nextInt();
        ArrayList<Commodity> commodities = adventurers.get(advId).getCommodities();
        BigInteger maxPrice = new BigInteger("0");
        for (Commodity value : commodities) {
            if (value.getPrice().compareTo(maxPrice) > 0) {
                maxPrice = value.getPrice();
            }
        }
        System.out.println(maxPrice);
    }

    public void sumCount(Scanner scanner) {
        int advId = scanner.nextInt();
        System.out.println(adventurers.get(advId).getCommodities().size());
    }

    public void printComInfo(Scanner scanner) {
        System.out.println(adventurers.get(scanner.nextInt()).getCommodities().get(scanner.nextInt()).toString());
    }

    public void useAll(Scanner scanner) {
        int advId = scanner.nextInt();
        adventurers.get(advId).use();
    }

    public void printAdvInfo(Scanner scanner) {
        System.out.println(adventurers.get(scanner.nextInt()).toString());
    }

    public void hire(Scanner scanner) {
        int advId1 = scanner.nextInt();
        int advId2 = scanner.nextInt();
        adventurers.get(advId1).getCommodities().add(adventurers.get(advId2));
    }

}
