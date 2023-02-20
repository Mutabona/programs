import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] mass = new int[n];
        for (int i = 0; i < n; i++) {
            mass[i] = scn.nextInt();
        }
        for (int i = 0; i < n; i++) {
            System.out.print(mass[i] + " ");
        }
        for (int i = 0; i < n; i++) {
            System.out.print(mass[i] + " ");
        }
    }
}
