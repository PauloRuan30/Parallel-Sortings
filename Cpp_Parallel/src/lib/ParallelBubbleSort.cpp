#include "include/ParallelBubbleSort.h"

void ParallelBubbleSort::parallelBubbleSort(std::vector<int>& array, int numThreads) {
    int n = array.size();
    std::vector<std::thread> threads;

    for (int i = 0; i < n - 1; i++) {
        int outerIndex = i;
        threads.emplace_back([=, &array]() {
            bubbleSortSegment(array, 0, n - outerIndex - 1);
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

void ParallelBubbleSort::bubbleSortSegment(std::vector<int>& array, int start, int end) {
    for (int j = start; j < end; j++) {
        if (array[j] > array[j + 1]) {
            std::swap(array[j], array[j + 1]);
        }
    }
}
