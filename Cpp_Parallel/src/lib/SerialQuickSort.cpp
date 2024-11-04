#include "include/SerialQuickSort.h"

void SerialQuickSort::quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pivotIndex = i + 1;
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void SerialQuickSort::sort(std::vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}
