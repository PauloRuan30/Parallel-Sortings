#include "include/ParallelQuickSort.h"

void ParallelQuickSort::parallelQuickSort(std::vector<int>& array, int numThreads) {
    quickSort(array, 0, array.size() - 1);
}

void ParallelQuickSort::quickSort(std::vector<int>& array, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        std::thread leftThread(quickSort, std::ref(array), low, pivotIndex - 1);
        std::thread rightThread(quickSort, std::ref(array), pivotIndex + 1, high);

        leftThread.join();
        rightThread.join();
    }
}

int ParallelQuickSort::partition(std::vector<int>& array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[high]);
    return i + 1;
}
