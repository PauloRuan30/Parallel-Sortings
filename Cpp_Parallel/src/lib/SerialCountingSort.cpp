#include "include/SerialCountingSort.h";

void SerialCountingSort::sort(std::vector<int>& a) {
    int max = findMax(a);
    std::vector<int> count(max + 1, 0);

    for (int num : a) {
        count[num]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i]-- > 0) {
            a[index++] = i;
        }
    }
}

int SerialCountingSort::findMax(const std::vector<int>& a) {
    int max = a[0];
    for (int num : a) {
        if (num > max) max = num;
    }
    return max;
}
