#ifndef SERIALMERGESORT_H
#define SERIALMERGESORT_H

#include <vector>

class SerialMergeSort {
public:
    static void sort(std::vector<int>& a, int n);
private:
    static void merge(std::vector<int>& a, std::vector<int>& left, std::vector<int>& right, int leftSize, int rightSize);
};

#endif // SERIAL_MERGE_SORT_H
