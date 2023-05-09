#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

void bucket_sort(float arr[],int n){
	
	vector<float> v[10];
	
	for(int i=0;i<n;i++){
		int x=arr[i]*10;
		v[x].push_back(arr[i]);
	}
	
	for(int i=0;i<10;i++){
		sort(v[i].begin(),v[i].end());
	}
	
	int k=0;
	for(int i=0;i<10;i++){
		for(int j=0;j<v[i].size();j++){
			arr[k]=v[i][j];
			k++;
		}
	}
	
}

int main(){
	int n;
	cout<<"Enter the size of the array :  ";
	cin>>n;
	float s[n];
	cout<<"Enter elements for the array : ";
	int max=0;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	
	cout<<"\n\nThe given set is :   ";
	for(int i=0;i<n;i++){
		cout<<" "<<s[i];
	}
	
	bucket_sort(s,n);
	
	cout<<"\n\nThe sorted set is :   ";
	for(int i=0;i<n;i++){
		cout<<" "<<s[i];
	}
	return 0;
}
