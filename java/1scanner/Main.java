import java.util.Scanner;

class Main {
  public static void main(String args[]){
    Scanner s = new Scanner(System.in);
    int n = 0;
    double sum = 0;
    while (s.hasNextInt()) {
      sum += s.nextInt();
      n++;
    }
    System.out.println(sum/n);
  }
} 