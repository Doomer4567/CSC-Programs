package Projects.Java.Relearn_Java;
import java.util.Scanner;


// Main Class
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("input x");
        int x = scan.nextInt();
        System.out.println("input y");
        int y = scan.nextInt();
        int z;
        while (y != 0) {
            z = x % y;
            x = y;
            y = z;
        }
        System.out.println(x);
    }
}