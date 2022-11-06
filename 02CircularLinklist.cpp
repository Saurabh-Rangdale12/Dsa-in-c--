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
            this->next = NULL;
        }
};

class Cll{
    public:
        node* head;
        Cll(){head = NULL;}
        void insertatend(int);
        void insertatfirst(int);
        void printlist();
};

void Cll :: insertatfirst(int data){
    node* newhead = new node(data);
    newhead ->next = head;
    node *temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newhead;
    head = newhead;
    return;
}

void Cll :: insertatend(int data){
    
    node *newnode = new node(data);
    node *temp = head;
    newnode -> next = head;
    
    if(head == NULL){
        newnode ->next = newnode;//head is null previously so we have to do it ad // newnode-> next = NULL;
        head = newnode;
        
        return;
    }
    
    while(temp->next!=head){
        temp = temp->next;   
    }
    
    temp->next = newnode;
    //cout<<newnode;
    return;
}


void Cll :: printlist(){
node* temp = head;

    if(head == NULL){
        cout <<"Empty List"<<endl;
        return;
    }
    cout<<"\nList Elements are:";
    
    do{
        cout << temp->data <<" ";
        temp = temp->next;
    }while(temp != head);
    cout<<endl;
}

int main(){
    
    Cll list;
   // list.head = new node(55);
    list.insertatend(12);
    list.insertatend(15);
    list.insertatend(17);
    list.insertatend(11);
    list.insertatend(19);
    list.insertatend(88);
    list.insertatfirst(100);
    list.insertatfirst(100);
    list.insertatfirst(100);
    list.insertatfirst(100);
    list.printlist();
    return 0;
}
