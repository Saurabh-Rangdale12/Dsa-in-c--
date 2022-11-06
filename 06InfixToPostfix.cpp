#include<iostream>
#include<string>
using namespace std;

class stack{
    public:
        char arr[100];
        int top = -1;
        void push(char);
        char pop ();
        bool isEmpty();
        bool isFull();
};

void stack :: push(char op){
    if(isFull())
        return;
    top++;
    arr[top] = op;
}

char stack :: pop(){
    if(isEmpty())
        return 0;
    char a;
    a = arr[top];
    top--;
    return a;
}

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

class toPostfix{
    public:
        string exp;
        string postfix;
        void converter();
        int precedence(char);
        void displaypostfix(){
            cout<<"\n----------display->>>"<<postfix<<endl;
            //cout <<"\n"<<exp;
        }
};

void toPostfix :: converter(){
    stack* array = new stack;
    postfix = new char (sizeof(exp));
    int i;
    int j=0;

    for(i = 0; exp[i] != '\0'; i++)
    {
        cout<<"\nfor loop checking for exp "<<i<< " " <<exp[i]<<endl;

        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            cout<<"\nIN if + - wala"<<endl;
            cout<<"precedence(exp[i]) = "<<precedence(exp[i])
                <<" precedence(array->arr[array->top]) = "<<precedence(array->arr[array->top])<<endl;
            if(precedence(exp[i]) > precedence(array->arr[array->top]))
            {
                array->push(this->exp[i]);
                cout<<"array->top["<<i<<"] = "<<array->arr[array->top];
            }
            else
            {
                while(precedence(exp[i]) <= precedence(array->arr[array->top]))
                {
                    postfix[j] = array->pop();
                    j++;
                }
                array->push(this->exp[i]);
                cout<<"array->top["<<i<<"] = "<<array->arr[array->top];
            }
        }

        else 
        {
            cout<<"j="<<j;
            postfix[j] = exp[i];
            cout<<"\npostfix[i]  else p = exp wala "<<postfix[j]<<endl;
            j++;
        }
    }

    while(!array->isEmpty())
    {
        postfix[j] = array->pop();
        j++;
    }

    postfix[j] = '\0';
    
    for(int j= 0; postfix[j] != '\0'; j++)
    {
        cout<<postfix[j];
    }

    cout<<"\n";
}


int toPostfix :: precedence(char op){
    if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-') 
        return 1;
    else    
        return 0;
}

int main(){
    toPostfix s;
    s.exp = "a+b-c*b+d/e";
    s.converter();
    //s.displaypostfix();
    return 0;
}