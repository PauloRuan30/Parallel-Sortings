#ifndef PARALLELBUBBLESORT_H
#define PARALLELBUBBLESORT_H

#include <vector>
#include <thread>
#include <algorithm>

class ParallelBubbleSort {
public:
    static void parallelBubbleSort(std::vector<int>& array, int numThreads);
private:
    static void bubbleSortSegment(std::vector<int>& array, int start, int end);
};

#endif // PARALLELBUBBLESORT_H
