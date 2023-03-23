import java.util.Scanner;
import java.util.Stack;
import java.io.Reader;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class brackets {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        Stack<Character> brackets = new Stack<Character>();
        boolean isCorrect = true;
        String bracketString = scn.nextLine();
        for (int i = 0; i < bracketString.length(); i++) {
            switch (bracketString.charAt(i)) {
                case '(':
                case '<':
                case '[':
                case '{':
                    brackets.push(bracketString.charAt(i));
                    break;
                case ')':
                    if (!brackets.isEmpty())
                        if (brackets.lastElement() == '(') {
                            brackets.pop();
                            break;
                        }
                    isCorrect = false;
                    break;
                case '>':
                    if (!brackets.isEmpty())
                        if (brackets.lastElement() == '<') {
                            brackets.pop();
                            break;
                        }
                    isCorrect = false;
                    break;
                case ']':
                    if (!brackets.isEmpty())
                        if (brackets.lastElement() == '[') {
                            brackets.pop();
                            break;
                        }
                    isCorrect = false;
                    break;
                case '}':
                    if (!brackets.isEmpty())
                        if (brackets.lastElement() == '{') {
                            brackets.pop();
                            break;
                        }
                    isCorrect = false;
                    break;
            }
        }
        if (brackets.isEmpty() && isCorrect)
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}