import java.util.Scanner;

public class Inversions {
    // count number of inversions in a[lo..hi] via brute force (for debugging only)
    private static long brute(int[] a, int lo, int hi) {
        long inversions = 0;
        for (int i = lo; i < hi; i++)
            for (int j = i + 1; j < hi; j++)
                if (a[j] < a[i]) inversions++;
        return inversions;
    }

    private static long merge(int[] a, int[] aux, int lo, int mid, int hi) {
        long inversions = 0;

        for (int k = lo; k <= hi; k++) {
            aux[k] = a[k];
        }

        int i = lo, j = mid+1;
        for (int k = lo; k <= hi; k++) {
            if (i > mid) {
                a[k] = aux[j];
                j++;
            } else if (j > hi) {
                a[k] = aux[i];
                i++;
            } else if (aux[j] < aux[i]) {
                a[k] = aux[j];
                j++;
                inversions += (mid - i + 1);
            } else {
                a[k] = aux[i];
                i++;
            }
        }

        return inversions;
    }

    private static long count(int[] a, int[] b, int[] aux, int lo, int hi) {
        long inversions = 0;
        if (hi <= lo) {
            return inversions;
        }

        int mid = lo + (hi - lo) / 2;
        inversions += count(a, b, aux, lo, mid);
        inversions += count(a, b, aux, mid+1, hi);
        inversions += merge(b, aux, lo, mid, hi);
        return inversions;
    }

    private static long count(int[] a, int[] b, int left, int right) {
        int[] aux = new int[a.length];
        System.arraycopy(a, 0, b, 0, a.length);

        return count(a, b, aux, left, right-1);
    }

    private static long getNumberOfInversions(int[] a, int[] b, int left, int right) {
        long numberOfInversions = 0;
        if (right <= left + 1) {
            return numberOfInversions;
        }
        int ave = (left + right) / 2;
        numberOfInversions += getNumberOfInversions(a, b, left, ave);
        numberOfInversions += getNumberOfInversions(a, b, ave, right);
        //write your code here
        return numberOfInversions;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int[] b = new int[n];
        //System.out.println(getNumberOfInversions(a, b, 0, a.length));
        System.out.println(count(a, b, 0, a.length));
    }
}
