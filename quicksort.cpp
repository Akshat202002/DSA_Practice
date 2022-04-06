#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Quick Sort using INT_MAX or INFINITY with first element as pivot
int partition(int A[], int l, int h){
    int pivot = A[l];
    int i = l;
    int j = h;
    
    do{
    	// Increment i as long as elements are smaller/equal to pivot
        do{i++;}while(A[i]<= pivot);
        
        // Decrement j as long as elements are larger than pivot
        do{j--;}while(A[j]>pivot);
        if(i<j){
            swap(&A[i], &A[j]);
        }
    }while(i<j);
    swap(&A[l], &A[j]);
    return j;
}

void quick_sort(int A[], int l, int h){
    int j;
    if(l<h){
        j = partition(A, l, h);
        
        //j will be infinity for first partition
        quick_sort(A, l, j);
        
        
        quick_sort(A, j+1, h);
        
    }
}

int main()
{
    int A[] = {20, 60, 10, 70, 90, 50, INT32_MAX}, n = 7;
    quick_sort(A, 0, n-1);
    
    for(int i =0; i<n-1;i++){
        cout << A[i] << " ";
        
    }
    return 0;
}
