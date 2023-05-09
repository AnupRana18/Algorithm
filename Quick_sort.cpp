#include <iostream>
#include <algorithm>
using namespace std;

int c=0;
void print(int * arr,int f,int l){
	cout<<"\n\n";
	for(int i=f;i<=l;i++){
		cout<<" "<<arr[i];
	}
}

int partition(int* arr,int p,int r){
	
	int x=arr[r];
	int i=p-1;
	for(int j=p;j<r;j++){
		c=c+1;
		if(arr[j]<x){
			i=i+1;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[r]);
	
	return i+1;
}

void quick_sort(int* arr,int p,int r){

	if(p>r)
	return;
	int q=partition(arr,p,r);
	quick_sort(arr,p,q-1);
	quick_sort(arr,q+1,r);
	
}

int main(){
	int n;
	int p=0;
	cout<<"Enter the number of elements you want in the array :";
	cin>>n;
	int* arr=new int[n];
	cout<<"\nEnter the elements of the array :";
	for(int i=0;i<n;i++)
	cin>>arr[i];


	int r=n-1;
	cout<<"\nThe array is :";
	for(int i=0;i<n;i++)
	cout<<arr[i]<<",";
	quick_sort(arr,p,r);
	cout<<"\n\nThe sorted array is :";
	for(int i=0;i<n;i++)
	cout<<arr[i]<<",";
	
	cout<<"\n\nThe number of compersions are :"<<c;
	
}
