#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head=NULL;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void resverse(){
        Node* prev=NULL;
        Node* current=head;
        Node* next=NULL;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
    }
    void insert(int data,int pos){
        Node* newNode=new Node;
        newNode->data=data;
        if(pos==1){
            newNode->next=head;
            head=newNode;
            return;
        }
        Node* temp=head;
        int count=1;
        while(temp!=NULL && count<pos-1){
            temp=temp->next;
            count++;
        }
        if(temp==NULL){
            cout<<"Position is out of range"<<endl;
            return;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
};


int main(){
    int n;
    cin>>n;
    LinkedList l;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        Node* newNode=new Node;
        newNode->data=data;
        newNode->next=l.head;
        l.head=newNode;
    }
    l.display();
    l.insert(10,3);
    l.display();
    l.resverse();
    l.display();
    return 0;
}
