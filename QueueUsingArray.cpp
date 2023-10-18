#include<iostream>
#include<climits>
using namespace std;
template <typename T>
class QueueUsingArray{

T* data;
int NextIndex;
int FirstIndex;
int capacity;
int size;
public:
	QueueUsingArray(int totalSize){
	    data=new T[totalSize];
	    NextIndex=0;
	    FirstIndex=-1;
	    capacity=totalSize;
	    size=0;
	} 
	
	int Tsize(){
		return size;
	}
	bool isEmpty(){
		return size==0;
	}
	void enqueue(T element){
		if(size==capacity){
			cout<<"Queue is full"<<endl;
			return;
		}
		data[NextIndex]=element;
		NextIndex=(NextIndex+1)%capacity;
		size++;
		if(FirstIndex==-1){
			FirstIndex=0;
		}
	}
	T front(){
			if(isEmpty()){
			cout<<"Queue is empty"<<endl;
			return 0;
		}
		return data[FirstIndex];
		
	}
	T dequeue(){
		if(isEmpty()){
			cout<<"Queue is empty"<<endl;
			return 0;
		}
	    T deletedElement=data[FirstIndex];
		FirstIndex=(FirstIndex+1)%capacity;
		size--;
		if(size==0){
			FirstIndex=-1;
			NextIndex=0;
		}
		return deletedElement;
		
	}
	
	
};
int main(){
	QueueUsingArray<char> q1(6);
	q1.enqueue(101);
	q1.enqueue(102);
	q1.enqueue(103);
	q1.enqueue(104);
	q1.enqueue(105);
	q1.enqueue(106);
	q1.enqueue(107);
	cout<<q1.dequeue()<<endl;
	cout<<q1.dequeue()<<endl;
	cout<<q1.Tsize()<<endl;
	cout<<q1.isEmpty()<<endl;
	cout<<q1.front()<<endl;
	q1.enqueue(108);
	q1.enqueue(109);
	cout<<q1.Tsize()<<endl;
	cout<<q1.front()<<endl;
	q1.enqueue(110);
	

	
	return 0;
}
