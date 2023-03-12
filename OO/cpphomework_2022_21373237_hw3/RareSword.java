import java.math.BigInteger;

class RareSword extends Sword {
    private final double extraExpBonus;

    public RareSword(int id, String name, BigInteger price,
                     double sharpness, double extraExpBonus) {
        super(id, name, price, sharpness);
        this.extraExpBonus = extraExpBonus;
    }

    @Override
    public void usedBy(Adventurer name) {
        name.setHealth(name.getHealth() - 10);
        name.setExp(name.getExp() + 10 + extraExpBonus);
        name.setMoney(name.getMoney() + getSharpness());
        System.out.println(name.getName() + " used " + getName() +
                " and earned " + getSharpness() + ".");
        System.out.println(name.getName() + " got extra exp " + extraExpBonus + ".");
    }

    @Override
    public String toString() {
        return "The rareSword's id is " + getId() +
                ", name is " + getName() +
                ", sharpness is " + getSharpness() +
                ", extraExpBonus is " + extraExpBonus + ".";
    }
}
