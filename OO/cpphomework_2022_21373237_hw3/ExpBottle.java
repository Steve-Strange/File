import java.math.BigInteger;

class ExpBottle extends Bottle {
    private double expRatio;

    public ExpBottle(int id, String name, BigInteger price, double capacity, double expRatio) {
        super(id, name, price, capacity);
        this.expRatio = expRatio;
    }

    @Override
    public void usedBy(Adventurer name) throws Exception {
        if (!isFilled()) {
            throw new Exception("Failed to use " + getName() + " because it is empty.");
        }
        name.setHealth(name.getHealth() + getCapacity() * (0.1));
        setFilled(false);
        setPrice(getPrice().divide(BigInteger.valueOf(10)));
        name.setExp(name.getExp() * expRatio);
        System.out.println(name.getName() + " drank " + getName() +
                " and recovered " + getCapacity() / 10 + ".");
        System.out.println(name.getName() + "'s exp became " + name.getExp() + ".");
    }

    @Override
    public String toString() {
        return "The expBottle's id is " + getId() +
                ", name is " + getName() +
                ", capacity is " + getCapacity() +
                ", filled is " + isFilled() +
                ", expRatio is " + expRatio + ".";
    }
}