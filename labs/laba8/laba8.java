import java.util.Scanner;
import static java.lang.Math.*;

public class laba8 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        Array mass = new Array(scn);
        System.out.println("Absolute max value: " + mass.absMaxElement());
        System.out.println("Sum between first two positive elements: " + mass.sumBetweenPositive());
        mass.printArray();
        scn.close();
        return;
    }
}

class Array {
    private int amountOfElemts;
    private double[] array;

    public Array(Scanner scn) {
        System.out.print("Amount of elements: ");
        this.amountOfElemts = scn.nextInt();
        this.array = new double[amountOfElemts];
        getNumbers(scn);
    }

    private void getNumbers(Scanner scn) {
        for (int i = 0; i < amountOfElemts; i++) {
            System.out.print("a[" + i + "] = ");
            array[i] = scn.nextInt();
        }
        return;
    }

    protected double absMaxElement() {
        double maxElement = array[0];
        for (int i = 0; i < amountOfElemts; i++) {
            if (abs(array[i]) > abs(maxElement))
                maxElement = abs(array[i]);
        }
        return maxElement;
    }

    protected double sumBetweenPositive() {
        double sum = 0;
        int i = 0;
        while (i < amountOfElemts && array[i] <= 0)
            i++;
        i++;
        while (i < amountOfElemts && array[i] <= 0) {
            sum += array[i];
            i++;
        }
        return sum;
    }

    protected void printArray() {
        for (int i = 0; i < amountOfElemts; i++)
            System.out.println("a[" + i + "] = " + array[i]);
        return;
    }

    protected void strangeSort() {

    }

    protected void normalSort() {

    }
}