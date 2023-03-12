class Sword extends Equipment {
    private double sharpness;

    public double getSharpness() {
        return sharpness;
    }

    public void setSharpness(double sharpness) {
        this.sharpness = sharpness;
    }

    public Sword(int id, String name, long price, double sharpness) {
        super(id, name, price);
        this.sharpness = sharpness;
    }

    @Override
    public void usedBy(Adventure name) {
        name.setHealth(name.getHealth() - 10);
        name.setExp(name.getExp() + 10);
        name.setMoney(name.getMoney() + sharpness);
        System.out.println(name.getName() + " used " + getName() +
                " and earned " + sharpness + ".");
    }

    public void print() {
        System.out.format("The sword's id is %d, name is %s, sharpness is %f" +
                ".\n", getId(), getName(), getSharpness());
    }
}

