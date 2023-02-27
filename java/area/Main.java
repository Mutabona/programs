import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		vect vectors[] = new vect[n];
		for (int i = 0; i < n; i++) {
			vectors[i] = new vect(scn.nextInt(), scn.nextInt());
		}
		double sum = 0;
        for (int i = 0; i < n - 1; i++) {
			sum += vectors[i].x*vectors[i+1].y;
		}
		sum += vectors[n-1].x*vectors[0].y;
		for (int i = 0; i < n - 1; i++) {
			sum -= vectors[i+1].x*vectors[i].y;
		}
		sum -= vectors[0].x*vectors[n-1].y;

		sum /= 2;
		System.out.print(Math.abs(sum));
    }
}

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
}