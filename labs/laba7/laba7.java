import java.util.Scanner;
import static java.lang.Math.*;

public class laba7 {
    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        System.out.print("a: "); double a = scn.nextDouble();
        System.out.print("b: "); double b = scn.nextDouble();
        System.out.print("xn: "); double xn = scn.nextDouble();
        System.out.print("xk: "); double xk = scn.nextDouble();
        System.out.print("dx: "); double dx = scn.nextDouble();

        System.out.println(" _________________________");
        System.out.println(" |    x    |   z = f(x)  |");
        System.out.println(" _________________________");

        double z = 0;

        for (double x = xn; x <= xk; x += dx) {
            System.out.printf(" | %-9.3f|", x);
            z = x<=a? sin(abs(x)) : x>=b? tan(exp(x)) : cos(abs(x));
            System.out.printf(" %-10.3f|\n", z);
        }

        System.out.println(" _________________________");

        scn.close();

        return;
    }
}