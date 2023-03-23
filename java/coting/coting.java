import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.*;

public class coting {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Pattern pattern = Pattern.compile(scanner.nextLine());
        String string = scanner.nextLine();
        Matcher matcher = pattern.matcher(string);
        int start = 0;
        int counter = 0;
        while (matcher.find(start)) {
            counter++;
            start = matcher.start() + 1;
        }
        System.out.println(counter);
    }
}