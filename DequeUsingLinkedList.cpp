#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node*next;
        Node(int data){
        	this->data=data;
        	next=NULL;
		}
};

class DequeUsingLinkedList{
	Node*head;
	Node*rear;
	public:
		
		DequeUsingLinkedList(){
			head=NULL;
			rear=NULL;
		}
		
		
		bool isEmpty(){
			return head==NULL;
		}
		void push_front(int element){
			Node* newNode=new Node(element);
			if(head==NULL){
				head=rear=newNode;
				rear->next=head;
			}
			else{
				newNode->next=head;
				rear->next=newNode;
				head=newNode;
			}
			
		}
		void push_back(int element){
			Node* newNode=new Node(element);
			if(head==NULL){
				head=rear=newNode;
				rear->next=head;
			}
			else{
				rear->next=newNode;
				newNode->next=head;
				rear=newNode;
			}
			
		}
		
		int pop_front(){
			if(isEmpty()){
				cout<<"Deque is Empty"<<endl;
				return 0;
			}
			else{
				Node* temp=head;
				int x=head->data;
				if(head==rear){
					head=rear=NULL;
				}
				else{
					head=head->next;
					rear->next=head;
				}
				delete temp;
				return x;
				
			}
		}
		int pop_back(){
			if(isEmpty()){
				cout<<"Deque is Empty"<<endl;
				return 0;
			}
			else{
				Node* temp=rear;
				int x=rear->data;
				if(head==rear){
					head=rear=NULL;
				}
				else{
				
					Node*current=head;
					while(current->next!=rear){
						current=current->next;
					}
					current->next=head;
					rear=current;
					
				}
				delete temp;
				return x;
			}
		}
		
		void Display(){
			Node*temp=head;
			do{
				cout<<temp->data<<" ";
				temp=temp->next;
			}while(temp!=head);
			cout<<endl;
		}
		int getFront(){
			if(isEmpty()){
				cout<<"Deque is empty"<<endl;
				return 0;
			}
			else{
				return head->data;
			}
		}
		int getRear(){
			if(isEmpty()){
				cout<<"Deque is empty"<<endl;
				return 0;
			}
			else{
				return rear->data;
			}
		}
};

int main(){
	DequeUsingLinkedList d1;
	cout<<d1.isEmpty()<<endl;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(30);
	d1.Display();
	cout<<d1.isEmpty()<<endl;
	cout<<d1.getFront()<<endl;
	cout<<d1.getRear()<<endl;
	d1.pop_back();
	d1.pop_front();
	d1.Display();
	
	
	return 0;
}
