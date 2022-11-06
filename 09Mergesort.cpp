//Time Complexity: O(n log(n))

#include<iostream>
using namespace std;

void merge(int A[], int mid, int low, int high){
    int i,j,k,B[100];
    i = low;
    j = mid + 1;
    k = low;

    while(i<=mid && j<= high){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++;
            k++;
        }
        else{
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while ( i<= mid){
        B[k]= A[i];
        i++;
        k++;
    }
    while(j<=high){
        B[k] = A [j];
        j++;
        k++;
    }
    for(int i= low; i<=high; i++){
        A[i] = B[i];
    }
}

void printsort(int arr[], int n){
    cout<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void mergeSort(int arr[],int low, int high){
    int mid;
    if(low < high){
        mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr,mid,low,high);
    }
}


int main(){
    int A[7];
    for(int i = 0; i< 7; i++){
        cout<<"Enter Element:";
        cin>>A[i];
    }
    for(int i = 0; i< 7; i++){
        cout<<A[i]<<" ";
    }
    int arr[]= {16,45,19,51,32,10,23};
    int n = 7;
    mergeSort(arr,0,6);
    printsort(arr,n);
    return 0;
}

