#ifndef SERIALMERGESORT_H
#define SERIALMERGESORT_H

#include <vector>

class SerialMergeSort {
public:
    static void sort(std::vector<int>& arr);
    
private:
    static void merge(std::vector<int>& arr, int left, int mid, int right);
    static void mergeSort(std::vector<int>& arr, int left, int right);
};

#endif // SERIALMERGESORT_H
