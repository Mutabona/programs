import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        summator sum = new summator();
        System.out.print(sum.calculate());
    }
}

final class summator {
    public static int A;
    public static int B;
    public static int Sum;
    public static int calculate() {
        Scanner scn = new Scanner(System.in);
        A = scn.nextInt();
        B = scn.nextInt();
        Sum = A + B;
        return (Sum);
    }
}