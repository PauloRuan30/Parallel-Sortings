#include "include/ParallelMergeSort.h"

void ParallelMergeSort::parallelMergeSort(std::vector<int>& array, int numThreads) {
    mergeSort(array, 0, array.size() - 1);
}

void ParallelMergeSort::mergeSort(std::vector<int>& array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        std::thread leftThread(mergeSort, std::ref(array), left, mid);
        std::thread rightThread(mergeSort, std::ref(array), mid + 1, right);

        leftThread.join();
        rightThread.join();
        merge(array, left, mid, right);
    }
}

void ParallelMergeSort::merge(std::vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> leftArray(array.begin() + left, array.begin() + mid + 1);
    std::vector<int> rightArray(array.begin() + mid + 1, array.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        array[k++] = (leftArray[i] <= rightArray[j]) ? leftArray[i++] : rightArray[j++];
    }

    while (i < n1) array[k++] = leftArray[i++];
    while (j < n2) array[k++] = rightArray[j++];
}
