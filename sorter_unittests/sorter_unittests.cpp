#include <gtest/gtest.h>
#include "Sorter.h"

class PreBuiltSorter: public testing::Test{
    protected:
        std::vector<int> testVector = {5, 3, 7, 2, 8, 1, 6, 4};
        Sorter sorter = Sorter(testVector);
};


// Test Bubble Sort
TEST_F(PreBuiltSorter, BubbleSortTest) {
    sorter.BubbleSort();
    std::vector<int> sortedVector = {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(sorter.GetSortedVector(), sortedVector);
}

// Test Insertion Sort
TEST_F(PreBuiltSorter, InsertionSortTest) {
    sorter.InsertionSort();
    std::vector<int> sortedVector = {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(sorter.GetSortedVector(), sortedVector);
}

// Test Selection Sort
TEST_F(PreBuiltSorter, SelectionSortTest) {
    sorter.SelectionSort();
    std::vector<int> sortedVector = {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(sorter.GetSortedVector(), sortedVector);
}

// Test Merge Sort
TEST_F(PreBuiltSorter, MergeSortTest) {
    sorter.MergeSort();
    std::vector<int> sortedVector = {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(sorter.GetSortedVector(), sortedVector);
}

// Test Quick Sort
TEST_F(PreBuiltSorter, QuickSortTest) {
    sorter.QuickSort();
    std::vector<int> sortedVector = {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(sorter.GetSortedVector(), sortedVector);
}
