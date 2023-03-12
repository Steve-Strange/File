import java.math.BigInteger;

class HealingPotion extends Bottle {
    private double efficiency;

    public HealingPotion(int id, String name, BigInteger price,
                         double capacity, double efficiency) {
        super(id, name, price, capacity);
        this.efficiency = efficiency;
    }

    @Override
    public void usedBy(Adventurer name) throws Exception {
        if (!isFilled()) {
            throw new Exception("Failed to use " + getName() + " because it is empty.");
        }
        name.setHealth(name.getHealth() + getCapacity() * (0.1 + efficiency));
        setFilled(false);
        setPrice(getPrice().divide(new BigInteger("10")));
        System.out.println(name.getName() + " drank " + getName() +
                " and recovered " + getCapacity() * (0.1) + ".");
        System.out.println(name.getName() + " recovered extra " +
                getCapacity() * (efficiency) + ".");

    }

    @Override
    public String toString() {
        return "The healingPotion's id is " + getId() +
                ", name is " + getName() +
                ", capacity is " + getCapacity() +
                ", filled is " + isFilled() +
                ", efficiency is " + efficiency + ".";
    }
}
