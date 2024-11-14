#ifndef SERIALQUICKSORT_H
#define SERIALQUICKSORT_H

#include <vector>

class SerialQuickSort {
public:
    static void sort(std::vector<int>& a, int low, int high);
private:
    static int partition(std::vector<int>& a, int low, int high);
};

#endif // SERIALQUICKSORT_H
