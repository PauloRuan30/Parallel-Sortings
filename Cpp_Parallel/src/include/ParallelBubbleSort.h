#ifndef PARALLELBUBBLESORT_H
#define PARALLELBUBBLESORT_H

#include <vector>
class  ParallelBubbleSort {
public:
    static void parallelBubbleSort(std::vector<int>& array, int numThreads);
};
#endif // PARALLELBUBBLESORT_H
