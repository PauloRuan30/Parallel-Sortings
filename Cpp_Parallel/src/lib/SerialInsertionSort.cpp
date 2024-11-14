#include "include/SerialInsertionSort.h";

void SerialInsertionSort::sort(std::vector<int>& a) {
    for (int i = 1; i < a.size(); i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
