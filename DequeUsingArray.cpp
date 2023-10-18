#include<iostream>
using namespace std;

class DequeUsingArray{
	int* data;
	int size;
	int front;
	int rear;
	public:
		DequeUsingArray(int size){
			this->size=size;
			data=new int[size];
			front=rear=-1;
		}
		bool isEmpty(){
			return front==-1;
		}
		bool isFull(){
			return ((front==0 && rear==size-1)  || front==(rear+1)%size);
		}
		void push_rear(int element){
			if(isFull()){
				cout<<"Deque is full"<<endl;
				return;
			}
			if(front==-1){
				front=rear=0;
			}
			else if(rear==size-1 && front!=0){
				rear=0;
			}
			else{
				rear++;
			}
			data[rear]=element;
		}
		void push_front(int element){
			if(isFull()){
				cout<<"Deque is full"<<endl;
				return ;
			}
			if(front==-1){
				front=rear=0;
			}
			else if(front==0 && rear!=size-1){
				front=size-1;
			}
			else{
				front--;
			}
			data[front]=element;
		}
		int  pop_front(){
			if(isEmpty()){
				cout<<"Deque is Empty"<<endl;
				return 0;
			}
			int x=data[front];
			data[front]=-1;
			if(front==rear){
				front=rear=-1;
			}
			else if(front==size-1){
				front=0;
			}
			else{
				front++;
			}
			return x;
		}
		int pop_back(){
			if(isEmpty()){
				cout<<"Deque is Empty"<<endl;
				return 0;
			}
			int x=data[rear];
			data[rear]=-1;
			if(front==rear){
				front=rear=-1;
			}
			else if(rear==0){
				rear=size-1;
			}
			else{
				rear--;
			}
			return x;
		}
		int getFront(){
			if(isEmpty()){
               cout<<"Deque is Empty"<<endl;
			   return 0;				
			}
			else{
				return data[front];
			}
			
		}
		int getRear(){
			if(isEmpty()){
				cout<<"Deque is Empty"<<endl;
				return 0;
			}
			else{
				return data[rear];
			}
		}
	   void Display(){
	   	int i=front;
	  do{
	   	cout<<data[i]<<" ";
	   	i=(i+1)%size;
	   }while(i!=(rear+1)%size);
}
};

int main(){
	DequeUsingArray d1(5);
	d1.push_front(10);
	d1.push_rear(20);
	d1.push_front(30);
	d1.push_rear(40);
	d1.push_front(100);
	d1.push_rear(200);
	cout<<d1.isFull()<<endl;
	cout<<d1.isEmpty()<<endl;
	cout<<d1.getFront()<<endl;
	cout<<d1.getRear()<<endl;
	cout<<d1.pop_back()<<endl;
	cout<<d1.pop_front()<<endl;
	d1.Display();
	return 0;
}
