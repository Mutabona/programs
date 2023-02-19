import java.util.Scanner;

class Time {
  public int hour;
  public int min;

  public void print() {
    System.out.printf("%d:%d", hour, min);
  }
  public static void main(String args[]){
    Scanner s = new Scanner(System.in);
    Time t = new Time();
    t.hour = s.nextInt();
    t.min  = s.nextInt();
    t.print();
  }
}

class Main {
  public static void main(String args[]){
    Time.main(args);
  }
}