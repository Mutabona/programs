import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner scn = new Scanner(System.in);
        int n = 0;
        boolean f = true;
        while (scn.hasNext()) {
            if (scn.hasNextInt()) {
                scn.nextInt();
                n++;
                if (n > 10) {
                    break;
                }
            }
            else {
                f = false;
                scn.next();
            }
        }
        if ((n == 10) && f)
            System.out.print("YES");
        else 
            System.out.print("NO");
    }
}