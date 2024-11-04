#include "include/ParallelMergeSort.h"
#include <iostream>
#include <vector>
#include <thread>
#include <future>

using namespace std;

void merge(vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArray(array.begin() + left, array.begin() + mid + 1);
    vector<int> rightArray(array.begin() + mid + 1, array.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k++] = leftArray[i++];
        } else {
            array[k++] = rightArray[j++];
        }
    }

    while (i < n1) array[k++] = leftArray[i++];
    while (j < n2) array[k++] = rightArray[j++];
}

void parallelMergeSort(vector<int>& array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Launch threads to sort the two halves in parallel
        future<void> leftSort = async(launch::async, parallelMergeSort, ref(array), left, mid);
        future<void> rightSort = async(launch::async, parallelMergeSort, ref(array), mid + 1, right);

        leftSort.get();   // Wait for the left half to be sorted
        rightSort.get();  // Wait for the right half to be sorted

        merge(array, left, mid, right);
    }
}
