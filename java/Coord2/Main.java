import java.util.Scanner;

class Main {
  public static void main(String args[]){
    Line.main(args);
  }
}

class Coord {
  public int x;
  public int y;

  void print() {
    System.out.print( x+" "+y+" ");
  }
  void read(Scanner s) {
    x = s.nextInt();
    y = s.nextInt();
  }
}

class Line {
  public Coord start;
  public Coord finish;

  Line(Coord a, Coord b) {
    start = a;
    finish = b;
  }

  Line(Scanner s) {
    start.read(s);
    finish.read(s);
  }

  void print() {
    start.print();
    finish.print();
  }

  void move(int dx) {
    start.x += dx;
    finish.x += dx;
  }
  public static void main(String args[]){
    Scanner s = new Scanner(System.in);
    Coord a = new Coord();
    Coord b = new Coord();
    a.read(s);
    b.read(s);
    Line lin = new Line(a, b);

    int dx = s.nextInt();
    lin.move(dx);

    lin.print();
  }
}