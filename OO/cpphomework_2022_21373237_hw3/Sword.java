import java.math.BigInteger;

class Sword extends Equipment {
    private double sharpness;

    public double getSharpness() {
        return sharpness;
    }

    public void setSharpness(double sharpness) {
        this.sharpness = sharpness;
    }

    public Sword(int id, String name, BigInteger price, double sharpness) {
        super(id, name, price);
        this.sharpness = sharpness;
    }

    @Override
    public void usedBy(Adventurer name) {
        name.setHealth(name.getHealth() - 10);
        name.setExp(name.getExp() + 10);
        name.setMoney(name.getMoney() + sharpness);
        System.out.println(name.getName() + " used " + getName() +
                " and earned " + sharpness + ".");
    }

    @Override
    public String toString() {
        return "The sword's id is " + getId() +
                ", name is " + getName() +
                ", sharpness is " + sharpness + ".";
    }
}

