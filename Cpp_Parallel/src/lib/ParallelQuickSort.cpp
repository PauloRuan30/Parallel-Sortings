#include "include/ParallelQuickSort.h"
#include <iostream>
#include <vector>
#include <thread>
#include <future>

using namespace std;

int partition(vector<int>& array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}

void parallelQuickSort(vector<int>& array, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);

        // Launch threads to sort the two partitions in parallel
        future<void> leftSort = async(launch::async, parallelQuickSort, ref(array), low, pivotIndex - 1);
        future<void> rightSort = async(launch::async, parallelQuickSort, ref(array), pivotIndex + 1, high);

        leftSort.get();   // Wait for the left half to be sorted
        rightSort.get();  // Wait for the right half to be sorted
    }
}
