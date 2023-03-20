import java.util.Scanner;

public class broadcast {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String ip[] = scanner.nextLine().split("\\.");
        String mask[] = scanner.nextLine().split("\\.");
        int w0 = ~Integer.parseInt(mask[0]) & 0xFF;
        int w1 = ~Integer.parseInt(mask[1]) & 0xFF;
        int w2 = ~Integer.parseInt(mask[2]) & 0xFF;
        int w3 = ~Integer.parseInt(mask[3]) & 0xFF;

        System.out.printf("%d.%d.%d.%d", (w0 | Integer.parseInt(ip[0])), (w1 | Integer.parseInt(ip[1])), (w2 | Integer.parseInt(ip[2])), (w3 | Integer.parseInt(ip[3])));
    }
}