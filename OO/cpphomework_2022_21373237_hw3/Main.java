import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    
    public static void main(String[] argv) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Branch> branches = new ArrayList<>();

        Branch presentBranch = new Branch("1",new HashMap<>());
        branches.add(presentBranch);

        int opCount = scanner.nextInt();
        for(int i=0;i<opCount;i++) {
            int op=scanner.nextInt();
            if(op<=10) {
                presentBranch.select(op, scanner);
            }
            else if(op==11) {
                
            }
        }



        scanner.close();
    }
}
