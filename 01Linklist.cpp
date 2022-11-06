#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(){
            data = 0;
            next = NULL;
        }

        Node(int data){
            this->data = data; //this->data used to call local variable 
            this->next = NULL;
        }
};

class Linklist{
    Node* head;
    public:
        Linklist(){head = NULL;}

        void insertNode(int);
        void printList();
        void deleteNode(int);
        void deletefirst();
        void deleteend();
        void insertNodeat(int , int);
        void insertatend(int);
        void insertathead(int);
};

void Linklist :: insertatend(int data){
    Node *temp = head, *newNode = new Node(data);
    for(int i=1; temp->next != NULL; i++){
        temp = temp -> next;
    }
    temp -> next = newNode;
    return;
}

void Linklist :: insertathead(int data){
    Node *nhead = new Node(data);
    nhead ->next = head;
    head = nhead;
}

void Linklist :: insertNodeat(int data, int position){
    Node *temp1=head ,*temp2 = head ,*newNode;
    int i;
    int j;
    Node *count = head;
    for(j=1; count->next != NULL; j++){
        count = count->next;
    }
    if(j<position){
        cout <<"Invalid no.";
        return;
    }
    for(i = 1; i<position -1 ; i++){
        
        temp1 = temp1 ->next;
        temp2 = temp2 ->next;
    }
    
    temp1 = temp1 -> next;
    newNode = new Node(data);
    newNode->next = temp1;
    temp1 = newNode;
    temp2 -> next = temp1;
    return;
}

void Linklist :: insertNode(int data){
    Node* newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

void Linklist :: deleteNode(int nodeoffset){
    Node* temp1 = head, *temp2 = NULL;
    int ListLen = 0;

    if(head == NULL){
        cout <<"List empty." <<endl;
        return;
    }

    while(temp1 != NULL){
        temp1 = temp1->next;
        ListLen++;
    }

    if(ListLen < nodeoffset){
        cout <<"index out of range"<<endl;
        return;
    }

    temp1 = head;

    if(nodeoffset == 1){
        head = head->next;
        delete temp1;
        return;
    }

    while(nodeoffset-- > 1){
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;
    delete temp1;

}

void Linklist :: deletefirst(){
    Node * temp = head;
    head = head -> next;
    delete temp;
}

void Linklist :: deleteend(){
    Node* temp = head, *temp2 = head;
    int i;
    for(i= 1; (temp->next)->next != NULL; i++){
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp = temp->next;
    delete temp;
    
    temp2->next = NULL;    
}

void Linklist :: printList(){
    Node* temp = head;

    if(head == NULL){
        cout <<"Empty List"<<endl;
        return;
    }
    cout<<"\nList Elements are:";
    while(temp != NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Linklist list;

    int size;
    cout<<"Enter list size:";
    cin>>size;
    for(int i=1; i<=size; i++){
        int a;
        cout <<"enter element:";
        cin>>a;
        list.insertNode(a);
    }

    list.printList();

    /*int a;
    cout <<"Enter no. of the node delete to.";
    cin >>a;
    list.deleteNode(a);
    list.printList();
    
    int ele, pos;
    cout<<"Enter element and its position:";
    cin>>ele>>pos;
    list.insertNodeat(ele,pos);
    list.printList();
    
    int end;
    cout<<"Insert at end:";
    cin>>end;
    list.insertatend(end);
    list.printList();

    int first;
    cout <<"insert at first:";
    cin>>first;
    list.insertathead(first);
    list.printList();

    list.deletefirst();
    list.printList();*/

    list.deleteend();
    list.printList();

    return 0;
}