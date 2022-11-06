#include<iostream>
using namespace std;

int stack[100], n = 100, top =-1;
void push(int val){
    if(top>=n-1)
        cout<<"Stack Overflow"<<endl;
    else{
        top ++ ;
        stack[top] = val;
    }    
}
void pop(){
    if (top == -1)
        cout <<"Stack Underflow";
    else{
        cout <<"The popped Element is "<< stack[top]<<endl;
        top--;
    }
}
void display(){
    if(top>=0){
        cout <<"Stack element are:";
        for(int i= top; i>=0; i--){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
    else    
        cout<<"Stack is empty";
}
int main(){
    push(45);
    push(45);
    push(45);
    push(45);
    push(45);
    display();
    pop();
    pop();
    pop();
    display();

    return 0;
}
