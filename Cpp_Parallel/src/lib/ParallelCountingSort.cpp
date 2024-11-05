#include "include/ParallelCountingSort.h"

void ParallelCountingSort::parallelCountingSort(std::vector<int>& array, int max, int numThreads) {
    std::atomic<int>* countArray = new std::atomic<int>[max + 1];
    for (int i = 0; i <= max; ++i) {
        countArray[i] = 0;
    }

    std::vector<std::thread> threads;
    int n = array.size();
    int chunkSize = n / numThreads;

    for (int i = 0; i < numThreads; i++) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? n : start + chunkSize;
        threads.emplace_back(countElements, std::ref(array), countArray, start, end);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (countArray[i]-- > 0) {
            array[index++] = i;
        }
    }
    delete[] countArray;
}

void ParallelCountingSort::countElements(const std::vector<int>& array, std::atomic<int>* countArray, int start, int end) {
    for (int j = start; j < end; j++) {
        countArray[array[j]]++;
    }
}
