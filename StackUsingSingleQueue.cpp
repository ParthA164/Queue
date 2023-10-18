#include<iostream>
#include<queue>
using namespace std;
template <typename T> 
class StackUsingSingleQueue{
	queue<T> q;
	public:
		void push(T data){
			int n=q.size();
			q.push(data);
			for(int i=0;i<n;i++){
				q.push(q.front());
				q.pop();
			}
		}
		
		void pop(){
				if(empty()){
				cout<<"Stack is Empty"<<endl;
				return;
			}
			q.pop();
		}
		T size(){
			return q.size();
		}
		bool empty(){
			return q.empty();
		}
		T top(){
			if(empty()){
				cout<<"Stack is Empty"<<endl;
				return 0;
			}
			return q.front();
		}
};

int main(){
	StackUsingSingleQueue<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	st.push(60);
	cout<<st.size()<<endl;
	cout<<st.top()<<endl;
	cout<<st.empty()<<endl;
	st.pop();
	st.pop();
	cout<<st.top()<<endl;
	cout<<st.size()<<endl;
	
	return 0;
}
