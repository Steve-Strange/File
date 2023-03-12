import java.math.BigInteger;

class Bottle extends Equipment {

    private double capacity;
    private boolean filled;

    public double getCapacity() {
        return capacity;
    }

    public void setCapacity(double capacity) {
        this.capacity = capacity;
    }

    public boolean isFilled() {
        return filled;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    public Bottle(int id, String name, BigInteger price, double capacity) {
        super(id, name, price);
        this.capacity = capacity;
        this.filled = true;
    }

    @Override
    public void usedBy(Adventurer name) throws Exception {
        if (!isFilled()) {
            throw new Exception("Failed to use " + getName() + " because it is empty.");
        }
        name.setHealth(name.getHealth() + getCapacity() / 10);
        this.filled = false;
        setPrice(getPrice().divide(new BigInteger("10")));
        System.out.println(name.getName() + " drank " + getName() +
                " and recovered " + getCapacity() / 10 + ".");
    }

    public String toString() {
        return  "The bottle's id is " + getId() +
                ", name is " + getName() +
                ", capacity is " + capacity +
                ", filled is " + filled + ".";
    }
}