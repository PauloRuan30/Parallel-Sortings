#include <iostream>
#include <vector>
#include <random>
#include <chrono>
// Include headers for  sorting
#include "include/SerialMergeSort.h"
#include "include/SerialBubbleSort.h"
#include "include/SerialQuickSort.h"
#include "include/SerialSelectionSort.h"
// Include headers for parallel sorting
#include "include/ParallelMergeSort.h"
#include "include/ParallelBubbleSort.h"
#include "include/ParallelQuickSort.h"
#include "include/ParallelSelectionSort.h"

using namespace std;

// Function to generate random arrays
vector<int> generateRandomArray(int size, int maxValue) {
    vector<int> array(size);
    random_device rd;  // Obtain random number from hardware
    mt19937 eng(rd()); // Seed the generator
    uniform_int_distribution<> distr(0, maxValue); // Define the range

    for (int i = 0; i < size; i++) {
        array[i] = distr(eng); // Generate random numbers
    }
    return array;
}

// Function to test serial sorting algorithms
void testSerialSortingAlgorithms(const vector<int>& array) {
    vector<int> mergeSortArray = array;
    auto start = chrono::high_resolution_clock::now();
    SerialMergeSort::sort(mergeSortArray);
    auto end = chrono::high_resolution_clock::now();
    cout << "Serial Merge Sort time: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    vector<int> bubbleSortArray = array;
    start = chrono::high_resolution_clock::now();
    SerialBubbleSort::sort(bubbleSortArray);
    end = chrono::high_resolution_clock::now();
    cout << "Serial Bubble Sort time: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    vector<int> quickSortArray = array;
    start = chrono::high_resolution_clock::now();
    SerialQuickSort::sort(quickSortArray);
    end = chrono::high_resolution_clock::now();
    cout << "Serial Quick Sort time: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    vector<int> selectionSortArray = array;
    start = chrono::high_resolution_clock::now();
    SerialSelectionSort::sort(selectionSortArray);
    end = chrono::high_resolution_clock::now();
    cout << "Serial Selection Sort time: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;
}

void testParallelSortingAlgorithms(int size, int numThreads) {
    vector<int> array = generateRandomArray(size, 1000); // Random array between 0 and 1000

    // Parallel Merge Sort
    vector<int> mergeArray = array;
    auto start = chrono::high_resolution_clock::now();
    ParallelMergeSort::parallelMergeSort(mergeArray, numThreads);
    auto end = chrono::high_resolution_clock::now();
    cout << "Parallel Merge Sort Time for " << size << " elements: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    // Parallel Bubble Sort
    vector<int> bubbleArray = array;
    start = chrono::high_resolution_clock::now();
    ParallelBubbleSort::parallelBubbleSort(bubbleArray, numThreads);
    end = chrono::high_resolution_clock::now();
    cout << "Parallel Bubble Sort Time for " << size << " elements: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    // Parallel Quick Sort
    vector<int> quickArray = array;
    start = chrono::high_resolution_clock::now();
    ParallelQuickSort::parallelQuickSort(quickArray, numThreads);
    end = chrono::high_resolution_clock::now();
    cout << "Parallel Quick Sort Time for " << size << " elements: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    // Parallel Selection Sort
    vector<int> selectionArray = array;
    start = chrono::high_resolution_clock::now();
    ParallelSelectionSort::parallelSelectionSort(selectionArray, numThreads);
    end = chrono::high_resolution_clock::now();
    cout << "Parallel Selection Sort Time for " << size << " elements: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;
}

int main() {
    const vector<int> sizes = {10, 100, 1000}; // Different sizes for sample acquisition
    const int numThreads = 4; // Specify the number of threads here

    cout << "Comparing Serial Sorting Algorithms with Varying Array Sizes" << endl;
    for (int size : sizes) {
        cout << "\nTesting with array size: " << size << endl;
        vector<int> array = generateRandomArray(size, 1000); // Generate random array
        testSerialSortingAlgorithms(array);
    }

    cout << "\nComparing Parallel Sorting Algorithms with Varying Array Sizes" << endl;
    for (int size : sizes) {
        cout << "\nTesting with array size: " << size << endl;
        testParallelSortingAlgorithms(size, numThreads);
    }

    return 0;
}
