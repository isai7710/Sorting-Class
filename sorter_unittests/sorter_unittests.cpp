#include <gtest/gtest.h>
#include "Sorter.h"

class PreBuiltSorter: public testing::Test{
    protected:
        std::vector<int> testVector = {5, 3, 7, 2, 8, 1, 6, 4};
        Sorter sorter = Sorter(testVector);
};


// Test Bubble Sort
TEST_F(PreBuiltSorter, GivenPreBuiltSorter_WhenCheckingBubbleSort_ExpectValuesInOrder) {
    sorter.BubbleSort();
    std::vector<int> sortedVector = {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(sorter.GetSortedVector(), sortedVector);
}

// Test Insertion Sort
TEST_F(PreBuiltSorter, GivenPreBuiltSorter_WhenCheckingInsertionSort_ExpectValuesInOrder) {
    sorter.InsertionSort();
    std::vector<int> sortedVector = {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(sorter.GetSortedVector(), sortedVector);
}

// Test Selection Sort
TEST_F(PreBuiltSorter, GivenPreBuiltSorter_WhenCheckingSelectionSort_ExpectValuesInOrder) {
    sorter.SelectionSort();
    std::vector<int> sortedVector = {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(sorter.GetSortedVector(), sortedVector);
}

// Test Merge Sort
TEST_F(PreBuiltSorter, GivenPreBuiltSorter_WhenCheckingMergeSort_ExpectValuesInOrder) {
    sorter.MergeSort();
    std::vector<int> sortedVector = {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(sorter.GetSortedVector(), sortedVector);
}

// Test Quick Sort
TEST_F(PreBuiltSorter, GivenPreBuiltSorter_WhenCheckingQuickSort_ExpectValuesInOrder) {
    sorter.QuickSort();
    std::vector<int> sortedVector = {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_EQ(sorter.GetSortedVector(), sortedVector);
}
