#include <iostream>

using namespace std;

int multin(int time)//求2^time
{
	int mul=1;
	while(time--)
		mul*=2;
	return mul;
}


int main()
{
	int len,i,j,k,time,t;
	int p,q,r;
	double *ptr;
	cout<<"input the lenth:"<<endl;
	cin>>len;
	double a[100];
	double key;
	cout << "input an array:" << endl;
	for(i=0;i<len;i++)
		cin>>a[i];

	double b[100];
	for(i=0;i<len;i++)
		b[i]=a[i];

	int multin(int time);

	//sort

	time=0;
	while (time<=len)
	{
		if(multin(time)==len)
			break;
		if(multin(time)<len && multin(time+1)>len)
		{	
			time+=1;
			break;
		}
		time++;
	}//归并的层数
	
	for(t=1;t<=time;t++)
	{
		p=0;q=multin(t-1)+p-1;r=q+multin(t-1);
		if(t==time && r>=len )
			r=len-1;
		while(r<len)
		{
			i=p;j=q+1;k=p;   
			while(i<=q && j<=r)
			{
				if(b[i]>b[j])
				{
					a[k]=b[j];
					j++;k++;
				}
				else if(b[i]<=b[j])
				{
					a[k]=b[i];
					i++;k++;
				}
			}
			while(i<=q)
			{
				a[k++]=b[i++];
			}
			while(j<=r)
			{
				a[k++]=b[j++];
			}
			
			p+=multin(t);q=multin(t-1)+p-1;r=q+multin(t-1);
		}
		for(i=0;i<len;i++)
			b[i]=a[i];
	}

	//

	cout<<"the sorted array is:"<<endl;
	for(i=0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 1;
}

