public class Equipment {
    private int id;
    private String name;
    private long price;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public long getPrice() {
        return price;
    }

    public void setPrice(long price) {
        this.price = price;
    }

    public Equipment(int id, String name, long price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }

    public void print() {

    }

    public void usedBy(Adventure name) throws Exception {

    }
}
