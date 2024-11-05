#ifndef PARALLELINSERTIONSORT_H
#define PARALLELINSERTIONSORT_H

#include <vector>
#include <thread>

class ParallelInsertionSort {
public:
    static void parallelInsertionSort(std::vector<int>& array, int numThreads);
private:
    static void insertionSort(std::vector<int>& array, int start, int end);
    static void merge(std::vector<int>& array, int left, int mid, int right);
};

#endif // PARALLELINSERTIONSORT_H
