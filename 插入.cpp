#include <iostream>

using namespace std;

int main()
{
	int len,i,j;
	cout<<"input the lenth:"<<endl;
	cin>>len;
	double a[100];
	double key;
	cout << "input an array:" << endl;
	for(i=0;i<len;i++)
		cin>>a[i];

	//sort
	for(i=1;i<len;i++)
	{	
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	//
	cout<<"the sorted array is:"<<endl;
	for(i=0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 1;
}
