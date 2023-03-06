import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String s = scn.next();
        s = s.replaceAll("0", "---");
        s = s.replaceAll("1", "--x");
        s = s.replaceAll("2", "-w-");
        s = s.replaceAll("3", "-wx");
        s = s.replaceAll("4", "r--");
        s = s.replaceAll("5", "r-x");
        s = s.replaceAll("6", "rw-");
        s = s.replaceAll("7", "rwx");
        System.out.print(s);
    }
}
