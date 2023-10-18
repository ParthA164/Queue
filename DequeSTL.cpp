#include<iostream>
#include<queue>
using namespace std;

int main(){
deque<int> d1;
cout<<d1.empty()<<endl;
d1.push_front(10);
d1.push_back(20);
d1.push_front(30);
cout<<d1.size()<<endl;
cout<<d1.empty()<<endl;
cout<<d1.front()<<endl;
cout<<d1.back()<<endl;
d1.pop_back();
d1.pop_front();
cout<<d1.front()<<endl;
cout<<d1.size()<<endl;
d1.pop_back();
cout<<d1.empty()<<endl;
	
	
	return 0;
}
