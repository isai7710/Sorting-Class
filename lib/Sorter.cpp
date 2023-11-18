#include "Sorter.h"
#include <iostream>
#include <chrono>
#include <thread>

void Sorter::BubbleSort(){
    copyVector = initialVector;
    
    for (int i = 0; i < vector_size; i++){
        for (int j = 0; j < vector_size-i-1; j++){
            if(copyVector[j] > copyVector[j+1]){
                int temp = copyVector[j];
                copyVector[j] = copyVector[j+1];
                copyVector[j+1] = temp;
            }
        }
    }
    return;
}

void Sorter::InsertionSort()
{
    copyVector = initialVector;
    
    for (int i = 1; i < vector_size; i++){
        int j = i - 1;
        int temp = copyVector[i];
        while (j >= 0 && copyVector[j] > temp){
            copyVector[j + 1] = copyVector[j];
            j--;
        }
        copyVector[j + 1] = temp;
    }
    return;
}

void Sorter::SelectionSort()
{
    copyVector = initialVector;

    for (int i = 0; i < vector_size; i++){
        int minIndex = i;
        for (int j = i + 1; j < vector_size; j++){
            if (copyVector[minIndex] > copyVector[j]){
                minIndex = j;
            }
        }
        if (minIndex != i){
            int temp = copyVector[i];
            copyVector[i] = copyVector[minIndex];
            copyVector[minIndex] = temp; 
        }
    }
    return;
}

void Sorter::MergeSort()
{
    copyVector = initialVector;
    MergeSorter(copyVector);

    return;
}

void Sorter::MergeSorter(std::vector<int> &v)
{
    if (v.size() == 1){
        return;
    }

    int mid = v.size()/2;
    std::vector<int> vleft(v.begin(), v.begin() + mid);
    std::vector<int> vright(v.begin() + mid, v.end());

    MergeSorter(vleft);
    MergeSorter(vright);

    Merger(v, vleft, vright);
}

void Sorter::Merger(std::vector<int>& mergedVector, const std::vector<int>& left, const std::vector<int>& right){
    int i = 0;  // starting index for left subvector
    int j = 0;  // starting index for right subvector
    int k = 0;  // starting index for resulting/merged vector

    // Compare elements of left and right subvectors and place them accordingly in merged vector
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            mergedVector[k] = left[i];
            i++;
        } 
        else {
            mergedVector[k] = right[j];
            j++;
        }
        k++;
    }
    // Above while loop breaks when all elements of either subvector have been placed accordingly 
    // (since the index i or j will be greater than left or right subvector size due to the ++), 
    // so the remaining elements of the right or left subvector still have to be placed in merged vector
    // Copy any remaining elements from left and right subvectors here
    while (i < left.size()) {
        mergedVector[k] = left[i];
        i++;
        k++;
    }
    while (j < right.size()) {
        mergedVector[k] = right[j];
        j++;
        k++;
    }
    return;
}

void Sorter::QuickSort(){
    copyVector = initialVector;
    QuickSorter(copyVector, 0, vector_size-1);

    return;
}

void Sorter::QuickSorter(std::vector<int>& v, int low, int high) {
    if (low < high) {
        int pivotIndex = Partition(v, low, high); // Find the pivot
        QuickSorter(v, low, pivotIndex - 1); // Recursively sort the left subarray
        QuickSorter(v, pivotIndex + 1, high); // Recursively sort the right subarray
    }
}

int Sorter::Partition(std::vector<int>& v, int low, int high) {
    //choose middle element as pivot and swap to the end of vector to perform partitioning on elements below
    int middle = low + (high - low) / 2;
    int pivot = v[middle];
    Swap(v[middle], v[high]);
    // follow through on white board, took me a minute but this works:
    int i = low - 1;
    int j = high;
    while (i<j) {
        do {
            i++;
        } while (v[i] < pivot);

        do {
            j--;
        } while (v[j] >= pivot);

        if(i < j){
            Swap(v[i], v[j]);
        }
    }
    Swap(v[high], v[i]);
    
    return i;
}

void Sorter::DisplayInitialVector(){
    std::cout << "\nInitial vector: " << std::endl;
    for(int i = 0; i < vector_size; i++){
        std::cout << initialVector[i] << " ";
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\n\n";
}

void Sorter::DisplaySortedVector(){
    std::cout << "\nSorted vector: " << std::endl;
    for(int i = 0; i < vector_size; i++){
        std::cout << copyVector[i] << " ";
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\n\n";
}

std::vector<int> Sorter::GetSortedVector()
{
    return copyVector;
}

void Sorter::Swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
