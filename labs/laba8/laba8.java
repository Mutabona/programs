import java.util.Scanner;
import static java.lang.Math.*;

public class laba8 {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        Array mass = new Array(scn);
        System.out.println("Absolute max value: " + mass.absMaxElement());
        System.out.println("Sum between first two positive elements: " + mass.sumBetweenPositive());
        int i = mass.strangeSort();
        mass.normalSort(0, i);
        mass.normalSort(i);
        mass.printArray();
        scn.close();
        return;
    }
}

class Array {
    private int amountOfElements;
    private double[] array;

    public Array(Scanner scn) {
        System.out.print("Amount of elements: ");
        this.amountOfElements = scn.nextInt();
        this.array = new double[amountOfElements];
        getNumbers(scn);
    }

    private void getNumbers(Scanner scn) {
        for (int i = 0; i < amountOfElements; i++) {
            System.out.print("a[" + i + "] = ");
            array[i] = scn.nextInt();
        }
        return;
    }

    protected double absMaxElement() {
        double maxElement = array[0];
        for (int i = 0; i < amountOfElements; i++) {
            if (abs(array[i]) > abs(maxElement))
                maxElement = abs(array[i]);
        }
        return maxElement;
    }

    protected double sumBetweenPositive() {
        double sum = 0;
        int i = 0;
        while (i < amountOfElements && array[i] <= 0)
            i++;
        i++;
        while (i < amountOfElements && array[i] <= 0) {
            sum += array[i];
            i++;
        }
        return sum;
    }

    protected void printArray() {
        for (int i = 0; i < amountOfElements; i++)
            System.out.println("a[" + i + "] = " + array[i]);
        return;
    }

    protected int strangeSort() {
        int count = 0;
        for (int i = 0; i < amountOfElements - 1; i++) {
            double temp = array[i];
            int imin = i;
            for (int j = i + 1; j < amountOfElements; j++) {
                if (array[j] < 1) {
                    imin = j;
                    temp = array[j];
                }
            }
            if (temp < 1) {
                count++;
            }
            array[imin] = array[i];
            array[i] = temp;
        }
        return count;
    }

    protected void normalSort(int start, int stop) {
        for (int i = start; i < stop - 1; i++) {
            double temp = array[i];
            int imax = i;
            for (int j = i + 1; j < stop; j++) {
                if (array[j] > temp) {
                    imax = j;
                    temp = array[j];
                }
            }
            array[imax] = array[i];
            array[i] = temp;
        }
    }

    protected void normalSort(int start) {
        int stop = amountOfElements;
        for (int i = start; i < stop - 1; i++) {
            double temp = array[i];
            int imax = i;
            for (int j = i + 1; j < stop; j++) {
                if (array[j] > temp) {
                    imax = j;
                    temp = array[j];
                }
            }
            array[imax] = array[i];
            array[i] = temp;
        }
    }
}