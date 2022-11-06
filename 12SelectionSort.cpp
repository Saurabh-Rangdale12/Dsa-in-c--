// big o = O(n^2)!!!

#include <iostream>
using namespace std;

class selectionsort{
    public:
        int*A;
        int j=0,k=0;
        int min=0;
        int n;
        void sort(){
            while(j<n){
                k = j;
                min = A[j];
                for(int i = j; i<n; i++){
                    if(min > A[i]){
                        min = A[i];
                        k = i;
                    }
                }
                int temp = A[j];
                A[j]  = min;
                A[k] =  temp;
            j++;
            }
        }
        
        
        void printarray(){
            for(int i= 0; i<n; i++){
                cout<<" "<<A[i];
            }
        }
};

int main(){
    selectionsort s;
    cout<<"Enter no. of elements";
    cin>>s.n;
    int nE = s.n;
    cout<<nE<<endl;
    s.A = new int(nE);
    for(int i = 0; i<nE; i++ ){
        int a;
        cin>>a;
        s.A[i] = a;
    }
    s.printarray();
    s.sort();
    s.printarray();

    return 0;
}