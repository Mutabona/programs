import java.util.Scanner;

class vect {
    public int x, y;
    vect(int ix, int iy) {
        x = ix;
        y = iy;
    }

    public static int scMult(vect a, vect b) {
        int result = a.x*b.x + a.y*b.y;
        return result;
    }

    public double getLength() {
        double result = Math.sqrt(this.x*this.x+this.y*this.y);
        return result;
    }
    //public static double vcMult(vect a, vect b) {}

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        vect a = new vect(scn.nextInt(), scn.nextInt());
        vect b = new vect(scn.nextInt(), scn.nextInt());
        System.out.print(Math.acos(a.scMult(a, b)/(a.getLength()*b.getLength())));
    }
}