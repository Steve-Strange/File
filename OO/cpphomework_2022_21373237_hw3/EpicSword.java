import java.math.BigInteger;

class EpicSword extends Sword {
    private final double evolveRatio;

    public EpicSword(int id, String name, BigInteger price, double sharpness, double evolveRatio) {
        super(id, name, price, sharpness);
        this.evolveRatio = evolveRatio;
    }

    @Override
    public void usedBy(Adventurer name) {
        name.setHealth(name.getHealth() - 10);
        name.setExp(name.getExp() + 10);
        name.setMoney(name.getMoney() + getSharpness());
        System.out.println(name.getName() + " used " + getName() + " and earned " +
                getSharpness() + ".");
        setSharpness(getSharpness() * evolveRatio);
        System.out.println(getName() + "'s sharpness became " + getSharpness() + ".");
    }

    @Override
    public String toString() {
        return "The epicSword's id is " + getId() +
                ", name is " + getName() +
                ", sharpness is " + getSharpness() +
                ", evolveRatio is " + evolveRatio + ".";
    }
}
