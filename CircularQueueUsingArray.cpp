#include<iostream>
using namespace std;

class CircularQueue{
	int* data;
	int front;
	int rear;
	int capacity;
	public:
		CircularQueue(int size){
			capacity=size;
			data=new int[size];
			front=-1;
			rear=-1;
		}
		bool isEmpty(){
			return (front==-1);
		}
		bool isFull(){
			return ((front==0 && rear==capacity-1) || front==(rear+1)%capacity);
		}
		void enqueue(int element){
			if((front==0 && rear==capacity-1) || front==(rear+1)%capacity){
				cout<<"Queue is Full"<<endl;
			    return;
			}
			if(front==-1){
				front=rear=0;
			}
			else if(rear==capacity-1 && front!=0){
				rear=0;
			}
			else{
				rear++;
			}
			data[rear]=element;
			
		}
		int dequeue(){
			if(front==-1){
				cout<<"Queue is empty"<<endl;
				return 0;
			}
			int temp=data[front];
			data[front]=-1;
			if(front==rear){
				front=rear=-1;
			}
			else if(front==capacity-1){
				front=0;
			}
			else{
				front++;
			}
			return temp;
		}
		int peek(){
			if(front==-1){
				cout<<"Queue is empty"<<endl;
				return 0;
			}
			return data[front];
		}
		void Display(){
				if(front==-1){
				cout<<"Queue is empty"<<endl;
				return;
			}
			int i=front;
			do{
				cout<<data[i]<<" ";
				i=(i+1)%capacity;
			}while(i!=front);
			cout<<endl;
		}
		
};

int main(){
	  CircularQueue q1(4);
	  q1.enqueue(10);
	  q1.enqueue(20);
	  q1.enqueue(30);
	  q1.enqueue(40);
	  q1.Display();
	  cout<<q1.peek()<<endl;
	  cout<<q1.dequeue()<<endl;
	  q1.Display();
	  q1.enqueue(50);
	  q1.Display();
	  cout<<q1.isFull()<<endl;
	  cout<<q1.isEmpty()<<endl;
	  cout<<q1.dequeue()<<endl;
	  q1.Display();
	  cout<<q1.isFull()<<endl;
	  
	
	return 0;
}
