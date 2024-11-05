import SerialSorts.*;
import ParallelSorts.*;
import java.util.Random;
import java.util.concurrent.ExecutionException;

public class MainComparisonSorts {

    private static final int[] SIZES = {10, 100, 1000, 10000}; // Array sizes for scalability testing
    private static final int NUM_THREADS = 4; // Number of threads for parallel sorting

    public static void main(String[] args) throws InterruptedException, ExecutionException {
        System.out.println("Comparing Parallel and Serial Sorting Algorithms with Varying Array Sizes\n");

        for (int size : SIZES) {
            System.out.println("Array Size: " + size);
            int[] array = generateRandomArray(size);

            // Parallel sorting algorithms
            System.out.println("Parallel Sorts:");
            runAndTimeSort(array, "Parallel Merge Sort", (arr) -> ParallelMergeSort.parallelMergeSort(arr, NUM_THREADS));
            runAndTimeSort(array, "Parallel Bubble Sort", (arr) -> ParallelBubbleSort.parallelBubbleSort(arr, NUM_THREADS));
            runAndTimeSort(array, "Parallel Quick Sort", (arr) -> ParallelQuickSort.parallelQuickSort(arr, NUM_THREADS));
            runAndTimeSort(array, "Parallel Selection Sort", (arr) -> ParallelSelectionSort.parallelSelectionSort(arr, NUM_THREADS));
            runAndTimeSort(array, "Parallel Insertion Sort", (arr) -> ParallelInsertionSort.parallelInsertionSort(arr, NUM_THREADS));
            runAndTimeSort(array, "Parallel Counting Sort", (arr) -> ParallelCountingSort.parallelCountingSort(arr, 1000, NUM_THREADS)); // Assuming max value 1000 for Counting Sort

            // Serial sorting algorithms
            System.out.println("");
            System.out.println("Serial Sorts:");
            runAndTimeSort(array, "Serial Merge Sort", arr -> SerialMergeSort.sort(arr, arr.length));
            runAndTimeSort(array, "Serial Bubble Sort", SerialBubbleSort::sort);
            runAndTimeSort(array, "Serial Quick Sort", arr -> SerialQuickSort.sort(arr, 0, arr.length - 1));
            runAndTimeSort(array, "Serial Selection Sort", SerialSelectionSort::sort);
            runAndTimeSort(array, "Serial Insertion Sort", SerialInsertionSort::sort);
            runAndTimeSort(array, "Serial Counting Sort", SerialCountingSort::sort);

            System.out.println("--------------------------------------------------\n");
        }
    }

    /**
     * Runs a sorting algorithm on a cloned array and measures its execution time.
     *
     * @param originalArray The original unsorted array.
     * @param sortName      The name of the sorting algorithm (for display purposes).
     * @param sortMethod    The sorting algorithm method to execute.
     */
    private static void runAndTimeSort(int[] originalArray, String sortName, SortMethod sortMethod) {
        int[] array = originalArray.clone();
        long startTime = System.nanoTime();
        sortMethod.sort(array);
        long endTime = System.nanoTime();
        System.out.printf("%s Time: %d ns%n", sortName, (endTime - startTime));
    }

    /**
     * Generates a random integer array of specified size.
     *
     * @param size The size of the array to generate.
     * @return An array filled with random integers.
     */
    private static int[] generateRandomArray(int size) {
        Random random = new Random();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = random.nextInt(1000); // Random numbers between 0 and 1000
        }
        return array;
    }

    /**
     * Functional interface to represent a sorting method for use with lambda expressions.
     */
    @FunctionalInterface
    private interface SortMethod {
        void sort(int[] array);
    }
}
