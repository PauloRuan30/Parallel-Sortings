#include "include/ParallelInsertionSort.h"

void ParallelInsertionSort::parallelInsertionSort(std::vector<int>& array, int numThreads) {
    std::vector<std::thread> threads;
    int n = array.size();
    int chunkSize = n / numThreads;

    for (int i = 0; i < numThreads; i++) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? n : start + chunkSize;
        threads.emplace_back(insertionSort, std::ref(array), start, end);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    for (int size = chunkSize; size < n; size *= 2) {
        for (int left = 0; left < n - size; left += 2 * size) {
            int mid = left + size - 1;
            int right = std::min(left + 2 * size - 1, n - 1);
            merge(array, left, mid, right);
        }
    }
}

void ParallelInsertionSort::insertionSort(std::vector<int>& array, int start, int end) {
    for (int i = start + 1; i < end; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= start && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void ParallelInsertionSort::merge(std::vector<int>& array, int left, int mid, int right) {
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        temp[k++] = (array[i] <= array[j]) ? array[i++] : array[j++];
    }
    while (i <= mid) temp[k++] = array[i++];
    while (j <= right) temp[k++] = array[j++];

    for (int l = 0; l < temp.size(); l++) {
        array[left + l] = temp[l];
    }
}
