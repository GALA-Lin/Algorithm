#include<iostream>
using namespace std;

class Stack{
    int top;
    int *arr;
    int size;
public:
    Stack(int s){
        size=s;
        arr=new int[size];
        top=-1;
    }
    bool isEmpty(){
        return (top==-1);
    }
    bool isFull(){
        return (top==size-1);
    }
    void push(int x){
        if(isFull()){
            cout<<"Stack is full"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        int x=arr[top];
        top--;
        return x;
    }
    int peek(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
};

int main(){
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<"Top element is "<<s.peek()<<endl;
    s.pop();
    cout<<"Top element is "<<s.peek()<<endl;
    s.pop();
    cout<<"Top element is "<<s.peek()<<endl;
    s.pop();
    cout<<"Top element is "<<s.peek()<<endl;
    s.pop();
    cout<<"Top element is "<<s.peek()<<endl;
    s.pop();
    cout<<"Top element is "<<s.peek()<<endl;
    return 0;
}