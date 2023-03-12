import java.math.BigInteger;

public interface Commodity extends Comparable<Commodity> {

    int getId();

    String getName();

    BigInteger getPrice();

    void usedBy(Adventurer adv) throws Exception;

    String toString();
}
