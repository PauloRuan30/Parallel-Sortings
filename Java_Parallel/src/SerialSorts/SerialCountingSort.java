package SerialSorts;

public class SerialCountingSort {
    public static void sort(int[] a) {
        int max = findMax(a);
        int[] count = new int[max + 1];

        for (int num : a) {
            count[num]++;
        }

        int index = 0;
        for (int i = 0; i <= max; i++) {
            while (count[i]-- > 0) {
                a[index++] = i;
            }
        }
    }

    private static int findMax(int[] a) {
        int max = a[0];
        for (int num : a) {
            if (num > max) max = num;
        }
        return max;
    }
}
