#include "include/SerialSelectionSort.h"

void SerialSelectionSort::sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int current_min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[current_min]) {
                current_min = j;
            }
        }
        std::swap(arr[current_min], arr[i]);
    }
}
