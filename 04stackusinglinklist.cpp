#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(){
        data = 0;
        next = NULL;
    }
    node(int data){
        this->data = data;
        this->next = next;
    }
};

class stack{
    node* top = NULL;
    node* head;
    int count = 0;
    public:
        stack(){head= NULL,top=NULL;};
        void create(int);
        void push(int);
        void pop();
        void peek(int);
        void display();
};

void stack :: create(int data){
    node*nhead = new node(data);
    head = nhead;
    count++;
}

void stack :: push(int data){
    node* newnode = new node(data);
    node*temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    top = newnode;
    count++;
}

void stack :: pop(){
    node*temp,*temp2;
    temp = head;
    temp2 = head;
    while((temp->next)->next != NULL){
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp = temp-> next;
    cout<<"\npop: "<<temp->data<<endl;
    delete temp;
    temp2->next = NULL;
    count--;
}

void stack::peek(int n){
    node*temp = head;
    if(n>count){
        cout << "Invalid No.";
        return;
    }
    for(int i = 1;i< n; i++){
        temp = temp->next;
    }
    cout << "\nPeek at "<<n<<"is "<<temp->data;
}

void stack :: display(){
    node*temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != NULL);
}
int main(){
    stack s;
    s.create(40);
    s.push(12);
    s.push(18);
    s.push(14);
    s.push(17);
    s.display();
    s.pop();
    s.display();
    s.peek(3);
    
    return 0;
}
