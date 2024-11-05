#ifndef SERIALCOUNTINGSORT_H
#define SERIALCOUNTINGSORT_H

#include <vector>

class SerialCountingSort {
public:
    static void sort(std::vector<int>& a);
private:
    static int findMax(const std::vector<int>& a);
};

#endif // SERIAL_COUNTING_SORT_H
