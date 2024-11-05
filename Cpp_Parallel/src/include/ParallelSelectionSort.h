#ifndef PARALLELSELECTIONSORT_H
#define PARALLELSELECTIONSORT_H

#include <vector>
#include <thread>

class ParallelSelectionSort {
public:
    static void parallelSelectionSort(std::vector<int>& array, int numThreads);
private:
    static void selectionSortSegment(std::vector<int>& array, int start, int end);
};

#endif // PARALLELSELECTIONSORT_H
