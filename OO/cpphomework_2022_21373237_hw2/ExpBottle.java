class ExpBottle extends Bottle {
    private double expRatio;

    public ExpBottle(int id, String name, long price, double capacity, double expRatio) {
        super(id, name, price, capacity);
        this.expRatio = expRatio;
    }

    @Override
    public void usedBy(Adventure name) throws Exception {
        if (!isFilled()) {
            throw new Exception("Failed to use " + getName() + " because it is empty.");
        }
        name.setHealth(name.getHealth() + getCapacity() * (0.1));
        setFilled(false);
        setPrice(getPrice() / 10);
        name.setExp(name.getExp() * expRatio);
        System.out.println(name.getName() + " drank " + getName() +
                " and recovered " + getCapacity() / 10 + ".");
        System.out.println(name.getName() + "'s exp became " + name.getExp() + ".");
    }

    public void print() {
        System.out.format("The expBottle's id is %d, name is %s, capacity" +
                        " is %f, filled is %b, expRatio is %f.\n", getId(),
                getName(), getCapacity(), isFilled(), expRatio);
    }
}