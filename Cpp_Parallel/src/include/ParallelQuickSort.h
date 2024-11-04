#ifndef PARALLELQUICKSORT_H
#define PARALLELQUICKSORT_H

#include <vector>
class ParallelQuickSort {
public:
    static void parallelQuickSort(std::vector<int>& array, int low, int high);
};

#endif // PARALLELQUICKSORT_H
