import java.util.Scanner;
import static java.lang.Math.*;

public class laba6_1 {
    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        System.out.print("a: "); double a = scn.nextDouble();
        System.out.print("b: "); double b = scn.nextDouble();
        System.out.print("x: "); double x = scn.nextDouble();
        double z;
        if (x<=a)
            z = sin(abs(x));
        else if (x>=b)
            z = tan(exp(x));
        else
            z =cos(abs(x));
        System.out.println("z = " + z);

        scn.close();

        return;
    }
}