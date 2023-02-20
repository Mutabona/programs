import java.util.Enumeration;
import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        String s[] = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = scn.next();
        }

        long mass[] = new long[50];

        for (int i = 49; i >= 0; i--) {
            long sum = 0;
            for (int j = 0; j < n; j++) {
                sum += (long)(s[j].charAt(i)) - 48;
            }
            mass[i] = sum;
        }

        for (int i = 49; i > 0; i--) {
            mass[i-1] += mass[i]/10;
            mass[i] %= 10;
        }

        Vector<Long> list = new Vector<Long>();
        while (mass[0] > 0) {
            list.add(0, mass[0]%10);
            mass[0] /= 10;
        }

        for (int i = 1; list.size() < 10; i++) {
            list.add(mass[i]);
        }

        Enumeration<Long> enumer = list.elements();
        n = 0;
        while(enumer.hasMoreElements() && (n < 10)) {
            System.out.print(enumer.nextElement());
            n++;
        }
    }
}