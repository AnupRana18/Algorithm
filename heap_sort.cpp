#include<iostream>
#include<algorithm>
using namespace std;

int q=0;

void print(int arr[],int n){
	cout<<"\nNumber is : ";
	for(int i=0;i<n;i++){
		cout<<" "<<arr[i];
	}
}

void build_max_heap(int arr[],int n,int j){
	int l=2*j+1;
	int r=2*j+2;
	int max=arr[j];
	int i=j;
	if(r<=n-1){
		q++;
		if(arr[r]>max){
			i=r;
			max=arr[r];
		}
	}
	if(arr[l]>max){
		i=l;
	}
	q++;
	swap(arr[i],arr[j]);
	
}

void heapify(int arr[],int n){
	int x=(n/2)-1;  //last non- leaf nodes
	for(int j=x;j>=0;j--){
		build_max_heap(arr,n,j);
	}
	swap(arr[0],arr[n-1]);
}

void heap_sort(int arr[],int n){
	int a=n;
	for(int i=1;i<n;i++){
		heapify(arr,a);
		a=a-1;
	}
}

int main(){
	int n;
	cout<<"Enter the size of the array :  ";
	cin>>n;
	int arr[n];
	cout<<"Enter elements for the array : ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	cout<<"\n\nThe given set is :   ";
	for(int i=0;i<n;i++){
		cout<<" "<<arr[i];
	}
	
	heap_sort(arr,n);
	
	cout<<"\n\n\n\nNew Sorted Array :  ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	cout<<"Number of comparisons : "<<q;
	
	return 0;
}
