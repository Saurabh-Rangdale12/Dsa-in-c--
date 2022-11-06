#include<iostream>
using namespace std;

class circularQ{
    int arr[10];
    int head=-1,end=-1;
    int pointer = -1;
    public:
        void enqueue(int);
        void dequeue();
        bool isFull();
        bool isEmpty();
        void display();
};

void circularQ :: enqueue(int data){

    if(isFull()){
        return;
    }

    if(end == -1){
        arr[0] = data;
        end ++;
        head++;
    }

    else{
        end = ((end+1) % 10);
        arr[end] = data;
    }
}

bool circularQ :: isFull(){
    if(head == (end+1)%10){
        return true;
    }
    else
        return false;
}

void circularQ :: dequeue(){
    cout<<"\ndequeue: "<<arr[head]<<endl;;
    if(head >= 10)
        head = head%10;

    arr[head]= 0;
    head++;
    head = head%10;
}

void circularQ :: display(){
    cout<<"\n";
    int i = head;
    while(i!=end){
        cout<<" "<<arr[i];
        i=(i+1)%10;
    }
    cout<<" "<<arr[end];
}

int main(){
    circularQ q;
    int y = 1;
    int data;
    while(y){
        cout<<"Enqueue: ";
        cin>>data;
        q.enqueue(data);
        if(q.isFull()){
            cout<<"Array is Full";
            break;
        }
    }

    // q.enqueue(12);
    // q.enqueue(13);
    // q.enqueue(15);
    // q.enqueue(18);
    // q.enqueue(72);
    // q.enqueue(14);
    // q.enqueue(14);
    // q.enqueue(14);
    // q.enqueue(14);
    // q.enqueue(14);


    q.display();

    cout<<"\nNow Dequeing";
    q.dequeue();
    q.display();

    cout<<"\n45 push";
    q.enqueue(45);
    q.display();
    return 0;
}