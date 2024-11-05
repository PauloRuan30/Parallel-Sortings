package SerialSorts;

public class SerialQuickSort {
    public static void sort(int[] a, int low, int high) {
        if (low < high) {
            int pivot = partition(a, high, low);
            sort(a, low, pivot - 1);
            sort(a, pivot + 1, high);
        }
    }

    private static int partition(int[] a, int high, int low) {
        int pivot = a[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (a[j] <= pivot) {
                i++;
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
        int finalTemp = a[high];
        a[high] = a[i + 1];
        a[i + 1] = finalTemp;
        return i + 1;
    }
}
