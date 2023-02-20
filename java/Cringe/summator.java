import java.lang.reflect.Type;
import java.util.Scanner;

import javax.xml.transform.Templates;

public static class summator<T extends Number> {

    private T A;
    private T B;
    private double Sum;

    private int calculate() {
        Sum = A.intValue() + B.intValue();
        return (int)Sum;
    }

    private double getSum() {
        Sum = A.doubleValue() + B.doubleValue();
        return Sum;
    }

    private void set_a(T a) {
        A = a;
    }

    private void set_b(T b) {
        B = b;
    }
}