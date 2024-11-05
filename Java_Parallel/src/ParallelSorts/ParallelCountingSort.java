package ParallelSorts;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicIntegerArray;

public class ParallelCountingSort {

    public static void parallelCountingSort(int[] array, int max, int numThreads) {
        AtomicIntegerArray countArray = new AtomicIntegerArray(max + 1);
        ExecutorService executor = Executors.newFixedThreadPool(numThreads);
        int n = array.length;
        int chunkSize = n / numThreads;

        // Count elements in parallel
        for (int i = 0; i < numThreads; i++) {
            final int start = i * chunkSize;
            final int end = (i == numThreads - 1) ? n : start + chunkSize;
            executor.submit(() -> {
                for (int j = start; j < end; j++) {
                    countArray.incrementAndGet(array[j]);
                }
            });
        }

        executor.shutdown();
        while (!executor.isTerminated()) {}

        // Write sorted elements back to array
        int index = 0;
        for (int i = 0; i <= max; i++) {
            while (countArray.get(i) > 0) {
                array[index++] = i;
                countArray.decrementAndGet(i);
            }
        }
    }
}
