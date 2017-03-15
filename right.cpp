#include <iostream>

using namespace std;

void rqiv(double arr[],int start,int end)
{
	int p,i,j;
	double k,pivot;
	pivot=arr[end];
	p=j=start;i=p-1;
	while(j<end)
	{
		if(arr[j]<=pivot)
		{
			i++;
			k=arr[j];
			arr[j]=arr[i];
			arr[i]=k;
			j++;
		}
		else 
			j++;
	}
	i++;
	k=arr[end];
	arr[end]=arr[i];
	arr[i]=k;
	if(start<i-1)
		rqiv(arr,start,i-1);
	if(end>i+1)
		rqiv(arr,i+1,end);
}

int main()
{
	int q,i,j,k,lenth;
	double arr[10];
	double pivot;
	cout<<"input lenth :"<<endl;
	cin>>lenth;
	cout<<"input the array :"<<endl;
	for(q=0;q<lenth;q++)
		cin>>arr[q];
	//sort
	rqiv(arr,0,lenth-1);
	//output
	cout<<"the sorted array is:"<<endl;
	for(q=0;q<lenth;q++)
		cout<<arr[q]<<" ";
	cout<<endl;
	return 1;
}