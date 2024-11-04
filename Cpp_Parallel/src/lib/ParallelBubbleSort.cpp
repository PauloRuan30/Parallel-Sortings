#include "include/ParallelBubbleSort.h"
#include <iostream>
#include <vector>
#include <thread>
#include <future>

using namespace std;

void parallelBubbleSort(vector<int>& array, int numThreads) {
    int n = array.size();
    vector<future<void>> futures;

    for (int i = 0; i < n - 1; i++) {
        futures.push_back(async(launch::async, [&, i]() {
            for (int j = 0; j < n - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    swap(array[j], array[j + 1]);
                }
            }
        }));
    }

    for (auto& fut : futures) {
        fut.get();  // Wait for all tasks to finish
    }
}
