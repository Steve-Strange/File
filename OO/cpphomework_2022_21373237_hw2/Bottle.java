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

    public Bottle(int id, String name, long price, double capacity) {
        super(id, name, price);
        this.capacity = capacity;
        this.filled = true;
    }

    @Override
    public void usedBy(Adventure name) throws Exception {
        if (!isFilled()) {
            throw new Exception("Failed to use " + getName() + " because it is empty.");
        }
        name.setHealth(name.getHealth() + getCapacity() / 10);
        this.filled = false;
        setPrice(getPrice() / 10);
        System.out.println(name.getName() + " drank " + getName() +
                " and recovered " + getCapacity() / 10 + ".");
    }

//    @Override
//    public void usedBy(Adventurer user) throws Exception {
//        if (!isFilled()) {
//            throw new Exception("Failed to use " + getName() + " because it is empty.");
//        }
//        user.setHealth(user.getHealth() + capacity / 10);
//        setFilled(false);
//        setPrice(getPrice().divide(BigInteger.TEN));
//
//        System.out.println(user.getName() +
//                " drank " + getName() +
//                " and recovered " + capacity / 10 +
//                ".");
//    }

    public void print() {
        System.out.format("The bottle's id is %d, name is %s, capacity is %f, " +
                "filled is %b.\n", getId(), getName(), getCapacity(), isFilled());
    }
}