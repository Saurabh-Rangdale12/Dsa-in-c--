#include<iostream>
using namespace std;

void bubble(int *A,int n){
    int isSorted;
    int temp;
    for(int i = 0; i<n-1 ; i++){//For Pass
        isSorted = 1;
        for(int j = 0; j<n-1-i; j++){//For Comparision
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted)
            return;
    }
}



void printSort(int *A, int n){
    cout<<endl;
    for(int i = 0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

int main(){
    int k;
    int* A;
    cout<<"\nNO of Element: ";
    cin>>k;
    for(int i= 0 ; i<k; i++){
        cin>>A[i];
    }
    bubble(A,k);
    printSort(A,k);
}
