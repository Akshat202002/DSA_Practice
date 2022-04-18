#include <iostream>
using namespace std;

// swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// merge function which merges two sorted arrays
void Merge(int A[], int l, int mid, int h)
{
    // variable to store the size of left(i) and right subarrays(j) and
    // k is the index of the resultant array
    int i = l, j = mid + 1, k = l;
    // create a temp array
    int B[100];

    // copy data to temp array
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    // copy remaining elements from left array
    for (; i <= mid; i++)
        B[k++] = A[i];
    // copy remaining elements from right array
    for (; j <= h; j++)
        B[k++] = A[j];
    // copy back to original array
    for (i = l; i <= h; i++)
        A[i] = B[i];
}

// merge sort function which sorts the array
void MergeSort(int A[], int l, int h)
{
    int mid;
    if (l < h)
    {
        // find the mid index
        mid = (l + h) / 2;
        // sort the left subarray
        MergeSort(A, l, mid);
        // sort the right subarray
        MergeSort(A, mid + 1, h);
        // merge the two subarrays
        Merge(A, l, mid, h);
    }
}
int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
    MergeSort(A, 0, n);
    for (i = 0; i < 10; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}
