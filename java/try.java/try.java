try {
    a = x / y;
    System.out.println("Division by successful");
} catch (ArithmeticException e) {
    //System.out.println("Division by zero");
} finally {
    return;
}