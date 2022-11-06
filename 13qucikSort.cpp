//Small error is there!!!!!!!!!!
//big O is Normal/best case is O(log n) ;
// Worst case is O(n^2);

#include<iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int i, int j){
    int pivot;
    pivot  = i;
    i++;
    
    if(j>i){
        while(arr[j]>arr[pivot]){
            j--;
        }
        while(arr[i] <= arr[pivot]){
            i++;
        }

        if(i<j){
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[j],arr[pivot]);
    pivot = j;
    
    return pivot;
}

void quicksort(int arr[], int i, int j){
    if(i<j){
        int pivot = partition(arr, i, j);
        quicksort(arr,i,pivot-1);
        quicksort(arr,pivot+1,j);
    }
}

int main(){
    int arr[] = {56,65,34,89,22};
    int n = 5;
    quicksort(arr,0,n-1);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
    // printsort(arr,n);
}