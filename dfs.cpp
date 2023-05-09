#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;


void DFS(vector<int> l[],char vertices[],int v,int e){
	cout<<"\n                   Calling DFS...";
	vector<int> layer;
	vector<int> dfs;
	bool discovered[v]={false};
	int k=0;
	layer.push_back(0);
	
	cout<<"\nSTART traversing : \n";
	while(!layer.empty()){
		int x=layer.back();
		cout<<"\n vertices : "<<x;
		if(discovered[x]==false){
			dfs.push_back(x);
			layer.pop_back();
			discovered[x]=true;
			cout<<" : ADD to DFS tree......\n";
		}
		else{
			layer.pop_back();
			cout<<" : ALREADY added to DFS tree......\n";
			continue;;
		}
		
		for(int i=0;i<l[x].size();i++){
			int key=l[x][i];
			cout<<"\n        "<<key;
			if(discovered[key]==false){
				cout<<" add in STACK.";
				layer.push_back(key);
			}
			else{
				cout<<" DFS tree";
			}
		}
		
	}
	
	cout<<"\n\n----------------FINALLY-------------\n";
	cout<<"DFS :  ";
	for(int i=0;i<dfs.size();i++){
		cout<<" "<<vertices[dfs[i]];
	}
}

int main(){
	int ver,ed;
	cout<<"Enter number of vertices : ";
	cin>>ver;
	cout<<"\nEnter number of edges : ";
	cin>>ed;
	
	char vertices[ver];
	cout<<"Enter vertices of the graph : ";
	for(int i=0;i<ver;i++){
		cin>>vertices[i];
	}
	vector<int> l[ver];
	
	cout<<"\nEnter vetices of Edges : ";
	for(int i=0;i<ed;i++){
		char s,d;
		cout<<"\nEdge-"<<i+1<<" : ";
		cin>>s>>d;
		int s1,d1;
		for(int j=0;j<ver;j++){
			if(vertices[j]==s){
				s1=j;
			}
			if(vertices[j]==d){
				d1=j;
			}
		}
		l[s1].push_back(d1);
		l[d1].push_back(s1);
	}
	
	DFS(l,vertices,ver,ed);
	
	return 0;
}

