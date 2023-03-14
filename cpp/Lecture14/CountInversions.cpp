/**
 * Count inversions in an array using divide and conquer strategy. 
 * 
 * Author: Guoxi Liu
 * Clemson University
 * Date: 03/13/2023
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int countInversions(std::vector<int> &vec, int left, int right) {
    // the array has less than 1 element
    if (right - left <= 1) return 0;
    
    // divide the problem 
    // n1: inversions in the left subarray
    // n2: inversions in the right subarray
    int mid = (left + right) / 2;
    int n1 = countInversions(vec, left, mid);
    int n2 = countInversions(vec, mid, right);

    // now we need to count inversions between these two arrays 
    int i = left, j = mid, k = 0, n3 = 0;
    std::vector<int> temp(right-left+1);
    while (i < mid && j < right) {
        if (vec[i] > vec[j]) {
            n3 += (mid - i);
            temp[k++] = vec[j++];
        }
        else {
            temp[k++] = vec[i++];
        }
    }

    // handle remaining elements 
    while (i < mid) temp[k++] = vec[i++];
    while (j < right) temp[k++] = vec[j++];

    // copy back to the original array 
    for (i = left; i < right; i++) {
        vec[i] = temp[i-left];
    }

    return (n1 + n2 + n3);
}

/**
 * Main entry of the program. 
*/
int main()
{
    // Use the in-class exercise as an example 
    std::vector<int> arr = {1, 20, 6, 4, 5};
    // std::vector<int> arr = {2, 1, 3, 1, 2};

    std::cout << "Number of inversions in the array: ";
    std::cout << countInversions(arr, 0, arr.size());
    std::cout << std::endl;
    
    return 0;
}