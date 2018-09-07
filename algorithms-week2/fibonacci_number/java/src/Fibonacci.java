import java.util.Scanner;
import java.util.ArrayList;

public class Fibonacci {
    private static long calc_fib(int n) {
        if (n <= 1)
            return n;

        return calc_fib(n - 1) + calc_fib(n - 2);
    }

    private static long fast_calc_fib(int n) {
        if (n <= 1) {
            return n;
        }

        ArrayList<Integer> fibs = new ArrayList<>();
        fibs.add(1);
        fibs.add(1);

        for (int i = 2; i < n; i++) {
            fibs.add(fibs.get(i-2) + fibs.get(i-1));
        }

        return fibs.get(n-1);
    }

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

//        System.out.println(calc_fib(n));
        System.out.println(fast_calc_fib(n));
    }
}
