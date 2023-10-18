#include<iostream>
using namespace std;
template<typename T>
class Node {
    	public :
    	T data;
    	Node *next;

    	Node(T data) {
        	this->data = data;
        	next = NULL;
    	}
	};
template<typename T>
class Queue {
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            return 0; // or some other appropriate error value
        }
        size--;
        Node<T> *temp = head;
        head = head->next;
        T data = temp->data;
        delete temp; // Don't forget to free the memory
        return data;
    }

    T front() {
        if (isEmpty()) {
            return 0; // or some other appropriate error value
        }
        return head->data;
    }
};


int main(){
	Queue<char> q1;
	q1.enqueue(101);
	q1.enqueue(102);
	q1.enqueue(103);
	q1.enqueue(104);
	q1.enqueue(105);
	q1.enqueue(106);
	cout<<q1.getSize()<<endl;;
	cout<<q1.dequeue()<<endl;
	cout<<q1.dequeue()<<endl;
	cout<<q1.getSize()<<endl;
	cout<<q1.front()<<endl;
	cout<<q1.isEmpty()<<endl;
	return 0;
}
