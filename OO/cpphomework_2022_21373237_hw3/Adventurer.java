import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;

class Adventurer implements Commodity {
    private int id;
    private String name;
    private ArrayList<Commodity> commodities;
    private double health;
    private double exp;
    private double money;

    public Adventurer(int id, String name) {
        this.id = id;
        this.name = name;
        this.commodities = new ArrayList<>();
        this.health = 100.0;
        this.exp = 0.0;
        this.money = 0.0;
    }
    @Override
    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getHealth() {
        return health;
    }

    public void setHealth(double health) {
        this.health = health;
    }

    public double getExp() {
        return exp;
    }

    public void setExp(double exp) {
        this.exp = exp;
    }

    public double getMoney() {
        return money;
    }

    public void setMoney(double money) {
        this.money = money;
    }

    public ArrayList<Commodity> getCommodities() {
        return commodities;
    }

    @Override
    public BigInteger getPrice() {
        BigInteger price = new BigInteger("0");
        for (Commodity x : commodities) {
            price = price.add(x.getPrice());
        }
        return price;
    }

    @Override
    public void usedBy(Adventurer name) throws Exception {

        Collections.sort(commodities);
        for (Commodity commodity : commodities) {
            try {
                commodity.usedBy(name);
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }

    public void use() {
        Collections.sort(commodities);
        for (Commodity x : commodities) {
            try {
                x.usedBy(this);
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }

    }

    public String toString() {
        return "The adventurer's id is " + id +
                ", name is " + name +
                ", health is " + health +
                ", exp is " + exp +
                ", money is " + money + ".";
    }

    @Override   //重写排序
    public int compareTo(Commodity other) {
        if (this.getPrice().compareTo(other.getPrice()) > 0) { return 1; }
        else if (this.getPrice().compareTo(other.getPrice()) > 0) { return -1; }
        return this.getId() - other.getId();
    }
}
