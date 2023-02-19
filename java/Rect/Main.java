import java.util.Scanner;

class Main {
    public static void main(String args[]) {
      Rect.main(args);
    }
  }
  
  class Coord {
    public int x;
    public int y;
    
    Coord(Scanner s) {
        x = s.nextInt();
        y = s.nextInt();
    }

    public void print() {
        System.out.print(x + " " + y + " ");
    }
  }

  class Direction {
    public int dx;
    public int dy;
  
    Direction(Scanner s) {
      dx = s.nextInt();
      dy = s.nextInt();
    }
  }
  
  class Rect {
    public Coord lt;  // left top point
    public Coord rb;  // right bottom point
  
    Rect(Scanner s) {
      lt = new Coord(s);
      rb = new Coord(s);
    }

    void print() {
      lt.print();
      rb.print();
    }

    void move(Direction d) {
      lt.x += d.dx;
      lt.y += d.dy;
      rb.x += d.dx;
      rb.y += d.dy;
    }
  
    public static void main(String args[]) {
      Scanner s = new Scanner(System.in);

      Rect r = new Rect(s);
      Direction d = new Direction(s);
  
      // подвинуть прямоугольник
      r.move(d);
  
      // напечатать подвинутый прямоугольник
      r.print();
    }
  }