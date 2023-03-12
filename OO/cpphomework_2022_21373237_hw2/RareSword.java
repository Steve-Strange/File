class RareSword extends Sword {
    private double extraExpBonus;

    public RareSword(int id, String name, long price, double sharpness, double extraExpBonus) {
        super(id, name, price, sharpness);
        this.extraExpBonus = extraExpBonus;
    }

    @Override
    public void usedBy(Adventure name) {
        name.setHealth(name.getHealth() - 10);
        name.setExp(name.getExp() + 10 + extraExpBonus);
        name.setMoney(name.getMoney() + getSharpness());
        System.out.println(name.getName() + " used " + getName() +
                " and earned " + getSharpness() + ".");
        System.out.println(name.getName() + " got extra exp " + extraExpBonus + ".");
    }

    public void print() {
        System.out.format("The rareSword's id is %d, name is %s, sharpness is %f, " +
                "extraExpBonus is %f.\n", getId(), getName(), getSharpness(), extraExpBonus);
    }
}
