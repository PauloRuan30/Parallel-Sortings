#include "include/SerialMergeSort.h";

void SerialMergeSort::sort(std::vector<int>& a, int n) {
    if (n < 2) return;

    int mid = n / 2;
    std::vector<int> left(a.begin(), a.begin() + mid);
    std::vector<int> right(a.begin() + mid, a.end());

    sort(left, mid);
    sort(right, n - mid);

    merge(a, left, right, mid, n - mid);
}

void SerialMergeSort::merge(std::vector<int>& a, std::vector<int>& left, std::vector<int>& right, int leftSize, int rightSize) {
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        a[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    }
    while (i < leftSize) a[k++] = left[i++];
    while (j < rightSize) a[k++] = right[j++];
}
