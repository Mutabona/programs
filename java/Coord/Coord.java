import java.util.Scanner;

class Coord {
  public int x;
  public int y;

  Coord() {

  }

  public void print() {
    System.out.println( "("+x+","+y+")");
  }
  void read(Scanner s) {
    x = s.nextInt();
    y = s.nextInt();
  }
  
  double length(Coord a) {
    int dx = x - a.x;
    int dy = y - a.y;
    return Math.sqrt(dx*dx+dy*dy);
  }
  static double length(Coord a, Coord b) {
    int dx = b.x - a.x;
    int dy = b.y - a.y;
    return Math.sqrt(dx*dx+dy*dy);
  }
  public static void main(String args[]){
    Scanner s = new Scanner(System.in);
    Coord t1 = new Coord();
    Coord t2 = new Coord();
    
    t1.read(s);
    t2.read(s);
    
    double res;
    res = Coord.length(t1, t2);
    System.out.println(res);
  }
}

class Main {
  public static void main(String args[]){
    Coord.main(args);
  }
}