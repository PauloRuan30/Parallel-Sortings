#ifndef PARALLELMERGESORT_H
#define PARALLELMERGESORT_H

#include <vector>
#include <thread>
#include <algorithm>

class ParallelMergeSort {
public:
    static void parallelMergeSort(std::vector<int>& array, int numThreads);
private:
    static void mergeSort(std::vector<int>& array, int left, int right);
    static void merge(std::vector<int>& array, int left, int mid, int right);
};

#endif // PARALLELMERGESORT_H
