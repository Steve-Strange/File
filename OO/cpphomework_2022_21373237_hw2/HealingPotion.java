class HealingPotion extends Bottle {
    private double efficiency;

    public HealingPotion(int id, String name, long price, double capacity, double efficiency) {
        super(id, name, price, capacity);
        this.efficiency = efficiency;
    }

    @Override
    public void usedBy(Adventure name) throws Exception {
        if (!isFilled()) {
            throw new Exception("Failed to use " + getName() + " because it is empty.");
        }
        name.setHealth(name.getHealth() + getCapacity() * (0.1 + efficiency));
        setFilled(false);
        setPrice(getPrice() / 10);
        System.out.println(name.getName() + " drank " + getName() +
                " and recovered " + getCapacity() * (0.1) + ".");
        System.out.println(name.getName() + " recovered extra " +
                getCapacity() * (efficiency) + ".");

    }

    public void print() {
        System.out.format("The healingPotion's id is %d, name is %s, capacity is %f, " +
                        "filled is %b, efficiency is %f.\n", getId(),
                getName(), getCapacity(), isFilled(),
                efficiency);
    }
}
