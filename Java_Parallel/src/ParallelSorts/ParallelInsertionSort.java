package ParallelSorts;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ParallelInsertionSort {

    public static void parallelInsertionSort(int[] array, int numThreads) {
        ExecutorService executor = Executors.newFixedThreadPool(numThreads);
        int n = array.length;
        int chunkSize = n / numThreads;

        // Sort chunks in parallel
        for (int i = 0; i < numThreads; i++) {
            final int start = i * chunkSize;
            final int end = (i == numThreads - 1) ? n : start + chunkSize;
            executor.submit(() -> {
                insertionSort(array, start, end);
            });
        }

        executor.shutdown();
        while (!executor.isTerminated()) {}

        // Merge sorted chunks
        for (int size = chunkSize; size < n; size *= 2) {
            for (int left = 0; left < n - size; left += 2 * size) {
                int mid = left + size - 1;
                int right = Math.min(left + 2 * size - 1, n - 1);
                merge(array, left, mid, right);
            }
        }
    }

    private static void insertionSort(int[] array, int start, int end) {
        for (int i = start + 1; i < end; i++) {
            int key = array[i];
            int j = i - 1;
            while (j >= start && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }

    private static void merge(int[] array, int left, int mid, int right) {
        int[] temp = new int[right - left + 1];
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (array[i] <= array[j]) {
                temp[k++] = array[i++];
            } else {
                temp[k++] = array[j++];
            }
        }
        while (i <= mid) temp[k++] = array[i++];
        while (j <= right) temp[k++] = array[j++];

        System.arraycopy(temp, 0, array, left, temp.length);
    }
}
