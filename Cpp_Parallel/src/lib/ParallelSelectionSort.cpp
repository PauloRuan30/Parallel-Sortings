#include "include/ParallelSelectionSort.h"
#include <iostream>
#include <vector>
#include <thread>
#include <future>

using namespace std;

void parallelSelectionSort(vector<int>& array, int numThreads) {
    int n = array.size();
    vector<future<void>> futures;

    for (int i = 0; i < n - 1; i++) {
        futures.push_back(async(launch::async, [&, i]() {
            int currentMinIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (array[j] < array[currentMinIndex]) {
                    currentMinIndex = j;
                }
            }
            swap(array[i], array[currentMinIndex]);
        }));
    }

    for (auto& fut : futures) {
        fut.get();  // Wait for all tasks to finish
    }
}
