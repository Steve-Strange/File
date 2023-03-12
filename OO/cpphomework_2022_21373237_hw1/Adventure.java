import java.util.HashMap;

class Adventure {
    private int id;
    private String name;
    private HashMap<Integer, Bottle> bottles;

    public Adventure(int id, String name) {
        this.id = id;
        this.name = name;
        this.bottles = new HashMap<>();
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public HashMap<Integer, Bottle> getBottles() {
        return bottles;
    }
}
