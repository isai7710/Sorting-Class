#ifndef SORTER_H
#define SORTER_H

#include <vector>

class Sorter {
public:
    Sorter(std::vector<int> v) 
        : initialVector(v), vector_size(v.size()) {}
    void BubbleSort();
    void InsertionSort();
    void SelectionSort();
    void MergeSort();
    void QuickSort();
    
    /*
    void RadixSort();
    */
    void DisplayInitialVector();
    void DisplaySortedVector();
    std::vector<int> GetSortedVector();

private:
    std::vector<int> initialVector;
    std::vector<int> copyVector;
    int vector_size;

    void MergeSorter(std::vector<int>& v);
    void Merger(std::vector<int> &resultingVec, const std::vector<int>& left, const std::vector<int>& right);
    void QuickSorter(std::vector<int>& v, int low, int high);
    int Partition(std::vector<int>& v, int low, int high);

    void Swap(int& a, int& b);
};

#endif