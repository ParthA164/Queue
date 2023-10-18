#include<iostream>
#include<queue>
using namespace std;

template <typename T>
class stackUsingTwoQueues{
	queue<T> q1;
	queue<T> q2;
	public:
		void push(T data){
			q2.push(data);
			while(!q1.empty()){
				q2.push(q1.front());
				q1.pop();
			}
			queue<T> q=q1;
			q1=q2;
			q2=q;
	
		}
		
		void pop(){
			if(q1.empty()){
				cout<<"stack is empty"<<endl;
				return;
			}
			q1.pop();
			return;
		}
		T top(){
				if(q1.empty()){
				cout<<"stack is empty"<<endl;
				return 0;
			}
		    return q1.front();
		} 
		T size(){
			return q1.size();
		}
		bool empty(){
			return q1.empty();
		}
				
};

int main(){
	stackUsingTwoQueues<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);
	cout<<st.size()<<endl;
	cout<<st.empty()<<endl;
	cout<<st.top()<<endl;
	st.pop();
	st.pop();
	cout<<st.size()<<endl;
	cout<<st.top()<<endl;
	
	
	return 0;
}
