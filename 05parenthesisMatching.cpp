#include<iostream>
#include<string>
using namespace std;


class stack{
        int top;
        char arr[100];
    public:
        char* exp;
        bool isEmpty();
        bool isFull();
        void push(char);
        void pop();
        void display();
        bool matching();
        
};
bool stack :: isEmpty(){
    if(top == -1)
        return true;
    else
        return false;
}
bool stack :: isFull(){
    if(top == 100)
        return true;
    else
        return false;
}

void stack :: push(char data){
    if(isFull()){
        cout<<"Stack Overflow."<<endl;
        return;
    }
    else{
            top ++;
            arr[top] = data;
        }
    return;
}

void stack :: pop (){
    if(isEmpty()){
        cout << "Stack Underflow.";
        return ;
    }

    cout << "pop" <<arr[top];
    top--;
}

void stack :: display(){
    for(int i=0; i <= top; i++){
        cout << arr[i];
    }
}

bool stack :: matching(){
    top = -1;

    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '('){
            push('(');
        }
        else if(exp[i] == ')'){
            if(isEmpty()){
                return false;
            }
            pop();
        }
    }

    if(isEmpty()){
        return true;
    }
    else    
        return false;
}


int main(){
    stack str;
    str.exp = "(3*8)+8*5(7+6)";
    if(str.matching()){
        cout<<"\nParenthesis is Matching.\n";
    }
    else
        cout<<"\nParenthesis is not Matching.\n";

    return 0;
}
