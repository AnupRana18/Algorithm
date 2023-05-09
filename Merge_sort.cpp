#include <iostream>
#include <cstdlib>
#include<time.h>
using namespace std;

int q=0;
void merge(int arr[],int k,int m,int n){
	
	int size=(n-k)+1;
	int* c=new int[size];
	int i1=k,i2=m+1,i3=0;
	
	while(i1<=m && i2<=n){
		if(arr[i2]<arr[i1]){
			c[i3]=arr[i2];
			i2++;
		}
		else{
			c[i3]=arr[i1];
			i1++;
		}
		i3++;
		q=q+1;
	}
	
	while(i1<=m){
		c[i3++]=arr[i1++];
	}
	while(i2<=n){
		c[i3++]=arr[i2++];
	}
	
	i1=k;
	for(int i=0;i<size;i++)
	arr[i1++]=c[i];
	
	delete c;
	
}

void merge_sort(int arr[],int f,int l){
	
	if(f<l){
		int mid=(f+l)/2;
		merge_sort(arr,f,mid);
		merge_sort(arr,mid+1,l);
		merge(arr,f,mid,l);
	}
}

int main(){
	srand(time(0));
	int n;
	cout<<"Enter the size of array : ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements in the array : ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"\nThe array is : ";
	for(int i=0;i<n;i++)
	cout<<" "<<arr[i];
	
	merge_sort(arr,0,n-1);
	
	
	cout<<"\n\nThe sorted array : ";
	for(int i=0;i<n;i++)
	cout<<" "<<arr[i];
	
	cout<<"\n\nNumber of comprisons : "<<q;
}
