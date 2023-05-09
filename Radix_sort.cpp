#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

void print(int arr[],int n){
	cout<<"\nNumber is : ";
	for(int i=0;i<n;i++){
		cout<<" "<<arr[i];
	}
}

void count_sort(int arr[],int n,int d){
	int count[10]={0};
	int temp[n];
	
	for(int i=0;i<n;i++){
		int x=(arr[i]/d)%10;
		count[x]++;
	}
	
	int x=count[0];
	count[0]=0;
	for(int i=1;i<10;i++){
		int y=count[i];
		count[i]=x+count[i-1];
		x=y;
	}
	
	for(int i=0;i<n;i++){
		int x=(arr[i]/d)%10;
		temp[count[x]++]=arr[i];
	}
	
	for(int i=0;i<n;i++){
		arr[i]=temp[i];
	}
	
}

void radix_sort(int arr[],int n,int d){
	for(int i=0;i<d;i++){
		count_sort(arr,n,pow(10,i));
	}
}

int main(){
	int n;
	cout<<"Enter the size of the array :  ";
	cin>>n;
	int s[n];
	cout<<"Enter elements for the array : ";
	int max=0;
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(s[i]>max){
			max=s[i];
		}
	}
	
	int d=0;
	while(max){
		max=max/10;
		d++;
	}
	
	cout<<"\n\nThe given set is :   ";
	for(int i=0;i<n;i++){
		cout<<" "<<s[i];
	}
	
	radix_sort(s,n,d);
	
	print(s,n);
	return 0;
}
