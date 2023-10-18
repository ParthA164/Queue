#include<iostream>
#include<queue>
using namespace std;


int main(){
	
	int arr[5]={4,2,1,3,5};
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=0;i<5;i++){
		pq.push(arr[i]);
	}
	pq.pop();
	cout<<pq.top()<<endl;
	cout<<pq.size()<<endl;
	cout<<pq.empty()<<endl;
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	
	return 0;
}
