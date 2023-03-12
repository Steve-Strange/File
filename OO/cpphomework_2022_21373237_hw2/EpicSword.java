class EpicSword extends Sword {
    private double evolveRatio;

    public EpicSword(int id, String name, long price, double sharpness, double evolveRatio) {
        super(id, name, price, sharpness);
        this.evolveRatio = evolveRatio;
    }

    @Override
    public void usedBy(Adventure name) {
        name.setHealth(name.getHealth() - 10);
        name.setExp(name.getExp() + 10);
        name.setMoney(name.getMoney() + getSharpness());
        System.out.println(name.getName() + " used " + getName() + " and earned " +
                getSharpness() + ".");
        setSharpness(getSharpness() * evolveRatio);
        System.out.println(getName() + "'s sharpness became " + getSharpness() + ".");
    }

    public void print() {
        System.out.format("The epicSword's id is %d, name is %s, sharpness is %f, " +
                "evolveRatio is %f.\n", getId(), getName(), getSharpness(), evolveRatio);
    }
}
