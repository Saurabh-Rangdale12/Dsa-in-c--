#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* prev;

        node(){
            data = 0;
            next = NULL;
            prev = NULL;
        }
        node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};
class DLink{
    node* head;
    public:
        DLink(){head = NULL;}
        void creatlist(int);
        void add(int);
        void addathead(int);
        void deleteene();
        void deletehead();
        void deletpos(int);
        void printlist();
};
void DLink ::creatlist(int data){
    node*newnode = new node(data);
    head = newnode;
}
void DLink :: add(int data){
    node*newnode = new node(data);
    node*temp=head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}
void DLink :: addathead(int data){
    node*newhead = new node(data);
    head->prev = newhead;
    newhead->next = head;
    head = newhead;
}

void DLink :: deleteene(){
    node*temp = head,*temp2 = head;
    while((temp->next)->next != NULL){
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp = temp->next;
    cout<<"\ndeleting end "<<temp->data;
    delete temp;
    temp2->next = NULL;
}

void DLink :: deletehead(){
    node*temp = head;
    node* temp2 = head;
    temp2 = temp2->next;
    head = temp2;
    delete temp;
    head->prev = NULL;
}

void DLink :: deletpos(int n){
    node*temp = head, *temp2;
    for(int i = 1; i< n; i++){
        temp = temp->next;
    }
    temp2 = temp->prev;
    temp2->next = temp->next;
    (temp->next)->prev = temp2;
    delete temp;
}

void DLink :: printlist(){
    node * temp = head;
    if(head == NULL){
        cout <<"\nEmpty List.\n";
        return;
    }

    cout <<"\nList Element are:";
    while(temp != NULL){
        cout << temp->data<<" ";
        temp = temp->next;
    }
    return;
}
int main(){
    DLink list;
    list.creatlist(15);
    list.add(45);
    list.add(47);
    list.add(41);
    list.add(49);
    list.add(47);
    list.addathead(100);
    list.printlist();
    list.deleteene();
    list.printlist();
    list.deletehead();
    list.printlist();
    list.deletpos(3);
    list.printlist();
    return 0;
}