
#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
	int start, finish, profit;
};

bool maximum(Job s1, Job s2)
{
	return (s1.finish < s2.finish);
}

int SearchCompatible(Job arr[], int i)
{
	
	for (int j=i-1; j>=0; j--)
	{
		if (arr[j].finish <= arr[i-1].start)
			return j;
	}
	return -1;
}

int findMaxProfit(Job arr[], int n)
{
	if (n == 1) 
		return arr[n-1].profit;

	int x = arr[n-1].profit;
	int i = SearchCompatible(arr, n);
	if (i != -1)
		x += findMaxProfit(arr, i+1);

	int y = findMaxProfit(arr, n-1);

	return max(x, y);
}

int IntervalScheduling(Job arr[], int n){
	
	sort(arr, arr+n, maximum);

	return findMaxProfit(arr, n);
}

int main()
{
	
	int n;
	cout<<"Enter Number of Jobs : ";
	cin>>n;
	
	Job arr[n];
	cout<<"\nEnter Start time, Finish time and Profit : ";
	for(int i=0;i<n;i++){
		cout<<"\nFor JOB - "<<i+1<<"  : ";
		cin>>arr[i].start;
		cin>>arr[i].finish;
		cin>>arr[i].profit;
	}
	
	cout << "\n\nThe optimal profit is " << IntervalScheduling(arr, n);
	return 0;
}

