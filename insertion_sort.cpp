#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of the array :  ";
	cin>>n;
	int s[n];
	cout<<"Enter elements for the array : ";
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	
	cout<<"\n\nThe given set is :   ";
	for(int i=0;i<n;i++){
		cout<<" "<<s[i];
	}
	
	cout<<"\nInsertion sorting : \n\n";
	int count=0;
	int a=n-1;
	for(int i=1;i<n;i++){
		
		for(int j=i;j>0;j--){
			count++;
			if(s[j] < s[j-1]){
				swap(s[j],s[j-1]);
			}
			else{
				break;
			}
		}
		
	}
	
	cout<<"\n\nSorted Array :  ";
	for(int i=0;i<n;i++){
		cout<<s[i]<<" ";
	}
	
	cout<<"\nNumber of comparision : "<<count;
	
	return 0;
}
