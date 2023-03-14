import java.util.regex.*;
import java.util.Scanner;

public class regex {
    public static void main(String[] args) {
        Pattern pattern = Pattern.compile("\\d{2}");
        int time = getNumber(pattern) + getNumber(pattern);
        System.out.printf("%02d:%02d", (time/60)%24, (time%60));
    }

    public static int getNumber(Pattern pattern) {
        Scanner scn = new Scanner(System.in);
        String text = scn.next();
        Matcher matcher = pattern.matcher(text);
        matcher.find();
        int minutes = (Integer.parseInt(text.substring(matcher.start(), matcher.end())))*60;
        matcher.find();
        minutes += Integer.parseInt(text.substring(matcher.start(), matcher.end()));
        return minutes;
    }
}

//Scanner in = new Scanner(System.in);
//in.useDelimiter("[.\\n]");


//Stack<Character> stack = new Stack<>();

//String[] time_line = in.nextLine().split("[: ]");

//Pattern p = Pattern.compile("\\d{1,3}\\.

//Matcher matcher = p.matcher(line);
//if (matcher.find()) {
//System.out.println(line.substring(matcher.start(), matcher.end()));