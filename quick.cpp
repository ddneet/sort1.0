#include <iostream>

using namespace std;

void fqiv(double arr[],int start,int end)
{
	int q,i,j,k;
	double pivot;
	pivot=arr[start];
	i=start+1;j=end;
	while(i<j)
	{
		while(arr[i]<pivot && i<j-1)
			i++;
		while(arr[j]>pivot && j>i+1)
			j--;
		if(i==j-1 && arr[i]<pivot)
			i++;
		else if(i==j-1 && arr[i]>pivot && arr[j]>pivot)
			break;
		else
		{
			k=arr[i];
			arr[i]=arr[j];
			arr[j]=k;
		}
	}
	if(i==j && arr[i]<pivot)
		i++;
	k=arr[i-1];
	arr[i-1]=pivot;
	arr[start]=k;
	if(start<i-2)
		fqiv(arr,start,i-2);
	if(end>i)
		fqiv(arr,i,end);
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
	fqiv(arr,0,lenth-1);
	//output
	cout<<"the sorted array is:"<<endl;
	for(q=0;q<lenth;q++)
		cout<<arr[q]<<" ";
	cout<<endl;
	return 1;
}
