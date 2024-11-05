#ifndef PARALLELQUICKSORT_H
#define PARALLELQUICKSORT_H

#include <vector>
#include <thread>

class ParallelQuickSort {
public:
    static void parallelQuickSort(std::vector<int>& array, int numThreads);
private:
    static void quickSort(std::vector<int>& array, int low, int high);
    static int partition(std::vector<int>& array, int low, int high);
};

#endif // PARALLELQUICKSORT_H
