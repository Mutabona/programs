import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int k = scn.nextInt();
        int m = scn.nextInt();
        int n = scn.nextInt();
        int s[][][] = new int[k][m][n];
        int a[][][] = new int[k][m][n];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < m; j++) {
                for (int z = 0; z < n; z++) {
                    s[i][j][z] = scn.nextInt();
                }
            }
        }

        a[0][0][0] = s[0][0][0];

        for (int i = k-1; i > 0; i--) {
            a[i][0][0] = s[i][0][0] - s[i-1][0][0];
        }
        for (int i = m-1; i > 0; i--) {
            a[0][i][0] = s[0][i][0] - s[0][i-1][0];
        }
        for (int i = n-1; i > 0; i--) {
            a[0][0][i] = s[0][0][i] - s[0][0][i-1];
        }

        for (int i = 1; i < k; i++) {
            for (int j = 1; j < n; j++) {
                a[i][0][j] = s[i][0][j] - s[i][0][j-1] - s[i-1][0][j] + s[i-1][0][j-1];
            }
        }
        for (int i = 1; i < k; i++) {
            for (int j = 1; j < m; j++) {
                a[i][j][0] = s[i][j][0] - s[i][j-1][0] - s[i-1][j][0] + s[i-1][j-1][0];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                a[0][j][i] = s[0][j][i] - s[0][j][i-1] - s[0][j-1][i] + s[0][j-1][i-1];
            }
        }

        for (int i = 1; i < k; i++) {
            for (int j = 1; j < m; j++) {
                for (int z = 1; z < n; z++) {
                    a[i][j][z] = s[i][j][z] - s[i-1][j][z] - s[i][j-1][z] - s[i][j][z-1] + s[i-1][j-1][z] + s[i-1][j][z-1] + s[i][j-1][z-1] - s[i-1][j-1][z-1];
                }
            }
        }

        System.out.print("\n");
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < m; j++) {
                for (int z = 0; z < n; z++) {
                    System.out.print(a[i][j][z] + " ");
                }
                System.out.print("\n");
            }
            System.out.print("\n");
        }
        

        for (int i = 0; i < n; i++) {
            BigInteger num = s.nextBigInteger();
            sum = sum.add(num);
        }
    }
}