import java.math.BigInteger;

public class Equipment implements Commodity {
    private int id;
    private String name;
    private BigInteger price;

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public BigInteger getPrice() {
        return price;
    }

    public void setPrice(BigInteger price) {
        this.price = price;
    }

    public Equipment(int id, String name, BigInteger price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }

    @Override
    public void usedBy(Adventurer name) throws Exception {

    }

    public String toString() {

        return null;
    }

    @Override
    public int compareTo(Commodity other) {

        return 0;
    }

    public Commodity deepClone() {
        return new Equipment(id, name, price);
    }
}
