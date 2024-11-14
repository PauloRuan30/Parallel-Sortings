#include "include/ParallelSelectionSort.h";

void ParallelSelectionSort::parallelSelectionSort(std::vector<int>& array, int numThreads) {
    std::vector<std::thread> threads;
    int n = array.size();

    for (int i = 0; i < n - 1; i++) {
        int outerIndex = i;
        threads.emplace_back([=, &array]() {
            selectionSortSegment(array, outerIndex + 1, n);
            std::swap(array[outerIndex], array[outerIndex + 1]);
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

void ParallelSelectionSort::selectionSortSegment(std::vector<int>& array, int start, int end) {
    int currentMinIndex = start;
    for (int j = start; j < end; j++) {
        if (array[j] < array[currentMinIndex]) {
            currentMinIndex = j;
        }
    }
    std::swap(array[start], array[currentMinIndex]);
}
