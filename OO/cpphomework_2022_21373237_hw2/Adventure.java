import java.util.HashMap;

class Adventure {
    private int id;
    private String name;
    private HashMap<Integer, Equipment> equipments;
    private double health;
    private double exp;
    private double money;

    public Adventure(int id, String name) {
        this.id = id;
        this.name = name;
        this.equipments = new HashMap<>();
        this.health = 100.0;
        this.exp = 0.0;
        this.money = 0.0;
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

    public HashMap<Integer, Equipment> getEquipments() {
        return equipments;
    }

    public void use(Equipment equipment) {
        try {
            equipment.usedBy(this);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    public void print() {
        System.out.format("The adventurer's id is %d, name is %s," +
                " health is %f, exp is %f, money is %f.\n", id, name, health, exp, money);
    }

}
