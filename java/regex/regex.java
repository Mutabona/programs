import java.util.regex.*;
import java.util.Scanner;

public class regex {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        Pattern pattern = Pattern.compile("\\d{2}");
        String text = scn.next();
        Matcher matcher = pattern.matcher(text);
        matcher.find();
        System.out.print(text.substring(matcher.start(), matcher.end()));
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