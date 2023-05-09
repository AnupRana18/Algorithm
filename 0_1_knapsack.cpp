#include<iostream>
#include<algorithm>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
	if (n == 0 || W == 0)
		return 0;

	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);

	else
		return max(
			val[n - 1]
				+ knapSack(W - wt[n - 1], wt, val, n - 1),
			knapSack(W, wt, val, n - 1));
}

int main()
{
	int n;
	cout<<"\nEnter number of items : ";
	cin>>n;
	int W;
	cout<<"\nEnter MAximum capacity : ";
	cin>>W;
	int profit[n] ;
	int weight[n] ;
	cout<<"\nEnter PROFIT and WEIGHT : \n";
	for(int i=0;i<n;i++){
		cout<<"For Item - "<<i+1<<" : ";
		cin>>profit[i]>>weight[i];
	}
	
	cout <<"\n\n optimal solution : "<< knapSack(W, weight, profit, n);
	return 0;
}


