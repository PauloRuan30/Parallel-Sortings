#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "include/SerialBubbleSort.h"
#include "include/SerialCountingSort.h"
#include "include/SerialInsertionSort.h"
#include "include/SerialMergeSort.h"
#include "include/SerialQuickSort.h"
#include "include/SerialSelectionSort.h"
#include "include/ParallelBubbleSort.h"
#include "include/ParallelCountingSort.h"
#include "include/ParallelInsertionSort.h"
#include "include/ParallelMergeSort.h"
#include "include/ParallelQuickSort.h"
#include "include/ParallelSelectionSort.h"

const std::vector<int> SIZES = {10, 100, 1000, 10000};
const int NUM_THREADS = 4;

// For parallel sorting functions that require only an array and thread count
void runAndTimeSort(std::vector<int> originalArray, const std::string& sortName, 
                    void (*sortMethod)(std::vector<int>&, int), int numThreads) {
    auto start = std::chrono::high_resolution_clock::now();
    sortMethod(originalArray, numThreads);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;
    std::cout << sortName << " Time: " << duration.count() << " ns" << std::endl;
}

// For counting sort, which requires maxValue and numThreads
void runAndTimeSort(std::vector<int> originalArray, const std::string& sortName, 
                    void (*sortMethod)(std::vector<int>&, int, int), int maxValue, int numThreads) {
    auto start = std::chrono::high_resolution_clock::now();
    sortMethod(originalArray, maxValue, numThreads);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;
    std::cout << sortName << " Time: " << duration.count() << " ns" << std::endl;
}

// For serial sorting functions that require only an array
void runAndTimeSort(std::vector<int> originalArray, const std::string& sortName, 
                    void (*sortMethod)(std::vector<int>&)) {
    auto start = std::chrono::high_resolution_clock::now();
    sortMethod(originalArray);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;
    std::cout << sortName << " Time: " << duration.count() << " ns" << std::endl;
}

// For Serial Merge Sort
void runAndTimeSort(std::vector<int> originalArray, const std::string& sortName, 
                    void (*sortMethod)(std::vector<int>&, int)) {
    auto start = std::chrono::high_resolution_clock::now();
    sortMethod(originalArray, originalArray.size());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;
    std::cout << sortName << " Time: " << duration.count() << " ns" << std::endl;
}

// For Serial Quick Sort
void runAndTimeSort(std::vector<int> originalArray, const std::string& sortName, 
                    void (*sortMethod)(std::vector<int>&, int, int)) {
    auto start = std::chrono::high_resolution_clock::now();
    sortMethod(originalArray, 0, originalArray.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> duration = end - start;
    std::cout << sortName << " Time: " << duration.count() << " ns" << std::endl;
}

// Generates a random integer array of specified size
std::vector<int> generateRandomArray(int size) {
    std::vector<int> array(size);
    std::generate(array.begin(), array.end(), []() { return rand() % 1000; });
    return array;
}

int main() {
    std::cout << "Comparing Parallel and Serial Sorting Algorithms with Varying Array Sizes\n" << std::endl;

    for (int size : SIZES) {
        std::cout << "Array Size: " << size << std::endl;
        std::vector<int> array = generateRandomArray(size);

        // Parallel sorting algorithms
        std::cout << "Parallel Sorts:" << std::endl;
        runAndTimeSort(array, "Parallel Merge Sort", ParallelMergeSort::parallelMergeSort, NUM_THREADS);
        runAndTimeSort(array, "Parallel Quick Sort", ParallelQuickSort::parallelQuickSort, NUM_THREADS);
        runAndTimeSort(array, "Parallel Bubble Sort", ParallelBubbleSort::parallelBubbleSort, NUM_THREADS);
        runAndTimeSort(array, "Parallel Selection Sort", ParallelSelectionSort::parallelSelectionSort, NUM_THREADS);
        runAndTimeSort(array, "Parallel Insertion Sort", ParallelInsertionSort::parallelInsertionSort, NUM_THREADS);
        runAndTimeSort(array, "Parallel Counting Sort", ParallelCountingSort::parallelCountingSort, 1000, NUM_THREADS); // Assuming max value 1000 for Counting Sort
        
        // Serial sorting algorithms
        std::cout << "Serial Sorts:" << std::endl;
        runAndTimeSort(array, "Serial Merge Sort", 
            [](std::vector<int>& arr) { SerialMergeSort::sort(arr, arr.size()); });
        runAndTimeSort(array, "Serial Quick Sort", 
            [](std::vector<int>& arr) { SerialQuickSort::sort(arr, 0, arr.size() - 1); });
        runAndTimeSort(array, "Serial Bubble Sort", SerialBubbleSort::sort);
        runAndTimeSort(array, "Serial Selection Sort", SerialSelectionSort::sort);
        runAndTimeSort(array, "Serial Insertion Sort", SerialInsertionSort::sort);
        runAndTimeSort(array, "Serial Counting Sort", SerialCountingSort::sort);

        std::cout << "--------------------------------------------------\n" << std::endl;
    }

    return 0;
}
