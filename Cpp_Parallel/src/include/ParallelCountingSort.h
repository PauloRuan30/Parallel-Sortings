#ifndef PARALLELCOUNTINGSORT_H
#define PARALLELCOUNTINGSORT_H

#include <vector>
#include <thread>
#include <atomic>

class ParallelCountingSort {
public:
    static void parallelCountingSort(std::vector<int>& array, int max, int numThreads);
private:
    static void countElements(const std::vector<int>& array, std::atomic<int>* countArray, int start, int end);
};

#endif // PARALLEL_COUNTING_SORT_H
