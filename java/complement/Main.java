import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        String s = String.format("%8s", Integer.toBinaryString(n)).replace(' ', '0');
        System.out.print(s.substring(s.length()-8, s.length()));
    }
}