#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int data){
			this->data=data;
			next=NULL;
		}
};

class CircularQueueUsingLinkedList{
	Node*head;
	Node*tail;
	int size;
	public:
	CircularQueueUsingLinkedList(){
		head=NULL;
		tail=NULL;
		size=0;
	}
	void enqueue(int element){
		Node* newNode=new Node(element);
		if(head==NULL){
			head=tail=newNode;
			size++;
		    return;
		}
		newNode->next=head;
		tail->next=newNode;
		tail=newNode;
		size++;
		
	}
	int dequeue(){
		if(head==NULL){
			cout<<"Queue is Empty"<<endl;
			return 0;
		}
		int ans=tail->data;
		
		if(head==tail){
	     	head=tail=NULL;	
		}
		else{
			head=head->next;
			tail->next=head;
		}
		size--;
	}
	int getSize(){
		return size;
	}
	bool isEmpty(){
		return (head==NULL || size==0);
	}
	int peek(){
		if(isEmpty()){
			cout<<"Queue is Empty"<<endl;
			return 0;
		}
		return head->data;
	}
	void Display(){
		Node* temp=head;
		if(head==NULL){
			cout<<"Queue is Empty"<<endl;
			return;
		}
		if(head==tail){
			cout<<head->data<<endl;
		}
		else{
		do{
		cout<<temp->data<<" ";
		temp=temp->next;
		}while(temp!=head);
		cout<<endl;
	}
}
};

int main(){
	CircularQueueUsingLinkedList q1;
	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);
	q1.Display();
	q1.dequeue();
	q1.dequeue();
	q1.Display();
	q1.enqueue(50);
	q1.Display();
	cout<<q1.getSize()<<endl;
	cout<<q1.isEmpty()<<endl;
	cout<<q1.peek()<<endl;
	return 0;
  }
