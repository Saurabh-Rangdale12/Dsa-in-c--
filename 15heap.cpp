#include <bits/stdc++.h>
using namespace std;

void insert(int heap[], int n){
    int temp , i= n;
    temp = heap[n];
    while(temp > heap[i/2] && i>=1){
        heap[i] = heap[i/2];
        i = i/2;
    }
    heap[i] = temp;
}

int delet(int heap[], int n){
    int temp, i,j,x, val;
    val = heap[1];
    x = heap[n];
    heap[1] = heap[n];
    heap[n] = val;
    i=1;
    j=i*2;
    while(j<=n -1){
        if(j<n-1 && heap[j+1]>heap[j])
            j = j+1;
        if(heap[i]<heap[j]){
            temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
            j=2*j;
        }
        else    
            break;
    }
    return val;
}

// void print(int heap[])

int main(){
    int heap[7] = {1,2,3,4,5,6,7};

    for(int i = 0; i<7; i++){
        insert(heap,i);
    }

    cout<<endl;
    for (int i = 0; i<7; i++){
        cout<<heap[i]<<" ";
    }
    return 0;
}
