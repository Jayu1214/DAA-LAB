#include<bits/stdc++.h>
using namespace std;
void traversePriorityQueue(priority_queue<int,vector<int>,greater<int> > pq) {
    cout << "Traversing the priority queue inside the function:" << endl;
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
	cout << endl;
}
int om(int n,int files[]){
	priority_queue<int,vector<int>,greater<int> > pq;
	for(int i=0;i<n;i++){
		pq.push(files[i]);
	}
	int count =0;
	while(pq.size()>1){
		int first=pq.top();
		pq.pop();
		int sec=pq.top();
		pq.pop();		
		int temp=first+sec;
		count+=temp;
		pq.push(temp);
		traversePriorityQueue(pq);
	}
	return count;
}
int main()
{
    int n = 6;
    int files[] = { 2, 3, 4, 5, 6, 7 };
    cout << "Minimum Computations = "<< om(n, files);
 
    return 0;
}
