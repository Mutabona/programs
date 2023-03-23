import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Pattern;
import java.util.regex.*;

public class mac {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Pattern pattern = Pattern.compile("([a-fA-F0-9]{2}\\:){5}[a-fA-F0-9]{2}");
        ArrayList<String> stringList = new ArrayList<String>();
        while (scanner.hasNextLine()) {
            stringList.add(scanner.nextLine());
        }
        for (String string : stringList) {
            Matcher matcher = pattern.matcher(string);
            while (matcher.find()) {
                System.out.println(string.substring(matcher.start(), matcher.end()));
            }
        }
    }
}