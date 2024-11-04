#ifndef SERIALQUICKSORT_H
#define SERIALQUICKSORT_H

#include <vector>

class SerialQuickSort {
public:
    static void sort(std::vector<int>& arr);
    
private:
    static void quickSort(std::vector<int>& arr, int low, int high);
};

#endif // SERIALQUICKSORT_H
