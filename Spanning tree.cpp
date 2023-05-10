#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
		int s1,s2;
		node(int s,int d,int x,node* ptr){
			next=ptr;
			s1=s;
			s2=d;
			data=x;
		}
};

class link{
	private:
		node *head;
	public:
		link(){
			head=0;
		}
		
		bool isempty(){
			if(head==0){
				return true;
			}
			return false;
		}
		
		void add_to_head(int s,int d,int x){
			head=new node(s,d,x,head);
		}
		
		void add_to_end(int s,int d,int x){
			if(head==0){
				add_to_head(s,d,x);
				return;
			}
			node *ptr=head;
			while(ptr->next){
				ptr=ptr->next;
			}
			ptr->next=new node(s,d,x,0);
			return;
		}
		
		void add_sorted(int s,int d,int x){
			if(head==0){
				add_to_head(s,d,x);
				return;
			}
			node *ptr=head;
			if(x < ptr->data){
				add_to_head(s,d,x);
				return;
			}
			node *temp=ptr;
			while(ptr->next){
				temp=ptr->next;
				if(x < temp->data){
					ptr->next=new node(s,d,x,temp);
					return;
				}
				ptr=ptr->next;
			}
			ptr->next=new node(s,d,x,0);
		}
		
		node* HEAD(){
			return head;
		}
		
		void remove_head(){
			head=head->next;
		}
		
		void delete_node(int s,int d){
			node *ptr=head;
			if((ptr->s1==s & ptr->s2==d) || (ptr->s2==s & ptr->s1==d)){
				head=head->next;
				return;
			}
			
			node* prev=ptr;
			ptr=ptr->next;
			
			while(ptr){
				if((ptr->s1==s & ptr->s2==d) || (ptr->s2==s & ptr->s1==d)){
					prev->next=ptr->next;
					delete ptr;
					return;
				}
				ptr=ptr->next;
			}
		}
		
		void display(){
			node *ptr=head;
			cout<<"\n\nEndges in the graph :\n";
			cout<<"        "<<" Weight ";
			while(ptr){
				cout<<"\n"<<ptr->s1<<" --> "<<ptr->s2<<"  "<<ptr->data;
				ptr=ptr->next;
			}
		}
		
};


class spanning{
	private:
		link* l;
		int n;
		int edge;
		char* vertices;
	
	public:
		spanning(){
			cout<<"\nenter Number of vertices : ";
			cin>>n;
			vertices=new char[n];
			l=new link[n];
			cout<<"Enter number of edges : ";
			cin>>edge;
			cout<<"\nEnter vesrtices og the graph  : ";
			for(int i=0;i<n;i++){
				cin>>vertices[i];
			}
			
			for(int i=0;i<edge;i++){
				char v1,v2;
				int e1,e2;
				int wt;
				cout<<"\nEnter vertices of Edge-"<<i+1<<" : ";
				cin>>v1>>v2;
//				cout<<"\nEnter Weight og Edge-"<<v1<<v2<<" : ";
				cin>>wt;
				int k1=0,k2=0;
				for(int j=0;j<n;j++){
					if(v1==vertices[j]){
						e1=j;
						k1=1;
					}
					if(v2==vertices[j]){
						e2=j;
						k2=1;
					}
					if(k1==1 & k2==1){
						break;
					}
				}
				
				if(k1==0 || k2==0){
					cout<<"\nvertice -"<<v1<<" Or "<<v2<<" is exist in graph ";
					i--;
					continue;
				}
				
				l[e1].add_to_end(e1,e2,wt);
				l[e2].add_to_end(e2,e1,wt);
			}
		}
		
		void prims(char v){
//			cout<<"\nSTART BFS\n";
			int k;
			bool discovered[n];
			for(int i=0;i<n;i++){
				if(vertices[i]==v){
					k=i;
				}
				discovered[i]=false;
			}
			
			link span,MST;
			int i=0;
			discovered[k]=true;
			
			while(i!=n){
				node *ptr=l[k].HEAD();
				while(ptr){
					int d=ptr->s2;
					if(discovered[d]==false){
						span.add_sorted(k,d,ptr->data);
					}
					ptr=ptr->next;
				}
				
				node *temp=span.HEAD();
				bool key = true;
				while(key==true && temp){
					int d=temp->s2;
					k=temp->s2;
					if(discovered[d]==false){
						MST.add_to_end(temp->s1,temp->s2,temp->data);
						span.delete_node(temp->s1,d);
						key=false;
						discovered[d]=true;
					}
					temp=temp->next;
				}
				
				i++;
			}
			
			MST.display();	
		}
		
		
		void display(){
			for(int i=0;i<n;i++){
				cout<<"\n"<<vertices[i]<<" -> ";
				l[i].display();
			}
		}
};


int main(){
	spanning g;\
	char a;
	cout<<"\n\n Enter the vertice from where spanning tree start : ";
	cin>>a;
	g.prims(a);
}

