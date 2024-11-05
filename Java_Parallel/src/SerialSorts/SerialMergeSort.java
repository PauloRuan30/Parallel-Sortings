package SerialSorts;

public class SerialMergeSort {
    public static void sort(int[] a, int n) {
        if (n < 2) return;

        int mid = n / 2;
        int[] left = new int[mid];
        int[] right = new int[n - mid];

        System.arraycopy(a, 0, left, 0, mid);
        System.arraycopy(a, mid, right, 0, n - mid);

        sort(left, mid);
        sort(right, n - mid);

        merge(a, left, right, mid, n - mid);
    }

    private static void merge(int[] a, int[] left, int[] right, int leftSize, int rightSize) {
        int i = 0, j = 0, k = 0;
        while (i < leftSize && j < rightSize) {
            a[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
        }
        while (i < leftSize) a[k++] = left[i++];
        while (j < rightSize) a[k++] = right[j++];
    }
}
