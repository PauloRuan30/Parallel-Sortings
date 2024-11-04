#ifndef PARALLELMERGESORT_H
#define PARALLELMERGESORT_H

#include <vector>
class ParallelMergeSort {
public:
    static void parallelMergeSort(std::vector<int>& array, int left, int right);
};
#endif // PARALLELMERGESORT_H
