#ifndef PARALLELSELECTIONSORT_H
#define PARALLELSELECTIONSORT_H

#include <vector>
class ParallelSelectionSort {
    public:
        static void parallelSelectionSort(std::vector<int>& array, int numThreads);
};
#endif // PARALLELSELECTIONSORT_H
