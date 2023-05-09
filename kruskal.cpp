#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest;
    int wt;
    Edge() {
        src = dest = wt = -1;
    }
    Edge(char s, char d, int w) {
        src = s;
        dest = d;
        wt = w;
    }
};

void merge(Edge arr[],int k,int m,int n);
void merge_sort(Edge arr[],int f,int l);

int find_parent(int parent[],int x){
	if(parent[x]==x){
		return parent[x];
	}
	parent[x]=find_parent(parent,parent[x]);
	return parent[x];
}

bool UNION(int parent[],int rank[],int x,int y){
	int x1=find_parent(parent,x);
	int y1=find_parent(parent,y);
	if(x1==y1){
		return true;
	}
	if(rank[x1] > rank[y1]){
		parent[y1]=x1;
		rank[x1]+=1;
	}
	else{
		parent[x1]=y1;
		rank[y1]+=1;
	}
	return false;
}


void kruskal(Edge arr[],char vertices[],int v,int e){
	cout<<"\n\nSpanning tree by Kruskal Mesthod : ";
	merge_sort(arr,0,e-1);
	int mst=0;
	Edge MST[v-1];
	int k=0;
	int parent[v];
	int rank[v];
	for(int i=0;i<v;i++){
		parent[i]=i;
		rank[i]=0;
	}
	
	for(int i=0;i<e;i++){
		int s=arr[i].src;
		int d=arr[i].dest;
		if( !UNION(parent,rank,s,d)){
			MST[k++]=arr[i];
			mst=mst+arr[i].wt;
		}
	}
	
	for(int i=0;i<v-1;i++){
		cout<<" \n"<<vertices[MST[i].src];
		cout<<" -> "<<vertices[MST[i].dest];
		cout<<" == "<<MST[i].wt;
	}
	cout<<"\nminimum cost of spanning tree : "<<mst;
	
	
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
	Edge edge[ed];
	
	for(int i=0;i<ed;i++){
		char s,d;
		int w;
		cout<<"\nEnter vetices and weight of Edge-"<<i+1<<" : ";
		cin>>s>>d>>w;
		int s1,d1;
		for(int j=0;j<ver;j++){
			if(vertices[j]==s){
				s1=j;
			}
			if(vertices[j]==d){
				d1=j;
			}
		}
		edge[i]=Edge(s1,d1,w);
	}
	
	kruskal(edge,vertices,ver,ed);
	
}
void merge(Edge arr[],int k,int m,int n){
	int size=(n-k)+1;
	Edge c[size];
	int i1=k,i2=m+1,i3=0;
	
	while(i1<=m && i2<=n){
		if(arr[i2].wt <arr[i1].wt){
			c[i3]=arr[i2];
			i2++;
		}
		else{
			c[i3]=arr[i1];
			i1++;
		}
		i3++;
//		cout<<"\nComprison :"<<q;
	}
	while(i1<=m){
		c[i3++]=arr[i1++];
	}
	while(i2<=n){
		c[i3++]=arr[i2++];
	}
	//copy c to arr
	i1=k;
	for(int i=0;i<size;i++)
	arr[i1++]=c[i];
	
	delete c;
	
}

void merge_sort(Edge arr[],int f,int l){
	if(f<l){
		int mid=(f+l)/2;
		merge_sort(arr,f,mid);
		merge_sort(arr,mid+1,l);
		merge(arr,f,mid,l);
	}
}
