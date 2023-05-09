#include<iostream>
using namespace std;

void count_sort(int* arr,int n,int r1,int r2){
	int r=r2-r1+1;
	int* range=new int[r];
	for(int i=0;i<=r;i++){
		range[i]=0;
	}
	
	for(int i=0;i<n;i++){
//		int x=arr[i];
		int j=x-r1;
		if(range[j]){
			range[j]=range[j]+1;
		}
		else{
			range[j]=1;
		}
	}
	
	int key=0;
	for(int i=0;i<r;i++){
		int k=i+r1;
		int x=range[i];
		for(int j=0;j<x;j++){
			arr[key]=k;
			key++;	
		}
	}
	delete range;
}


int main(){
	int n,r1,r2;
	int* arr;
	cout<<"\nEnter the size of the array : ";
	cin>>n;
	arr=new int[n];
	cout<<"\nEnter the range of numbers entering : ";
	cin>>r1>>r2;
	
	cout<<"\nEnter the numbers : ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	count_sort(arr,n,r1,r2);
	
	cout<<"\n\nSorted array  : ";
	for(int i=0;i<n;i++){
		cout<<" "<<arr[i];
	}
	
	
}
