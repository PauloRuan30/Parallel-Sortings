#include "include/SerialSelectionSort.h"

void SerialSelectionSort::sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int currentMin = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[currentMin]) {
                currentMin = j;
            }
        }
        std::swap(arr[currentMin], arr[i]);
    }
}
