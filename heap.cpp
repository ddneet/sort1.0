#include <iostream>
#include"node.cpp"
using namespace std;

void max1(node &n)
{
	double k;
	if(n.rchild!=nullptr)
	{
		max1(*n.lchild);
		max1(*n.rchild);
		if(n.lchild->val>n.val && n.rchild->val>n.val)
		{
			if(n.lchild->val >= n.rchild->val)
			{
				k=n.lchild->val;
				n.lchild->val=n.val;
				n.val=k;
			}
			else if(n.lchild->val < n.rchild->val)
			{
				k=n.rchild->val;
				n.rchild->val=n.val;
				n.val=k;
			}
		}
		else if(n.lchild->val>n.val)
		{
			k=n.lchild->val;
			n.lchild->val=n.val;
			n.val=k;
		}
		else if(n.rchild->val>n.val)
		{
			k=n.rchild->val;
			n.rchild->val=n.val;
			n.val=k;
		}
	}
	else if(n.lchild!=nullptr)
	{
		if(n.lchild->val>n.val)
		{	
			k=n.lchild->val;
			n.lchild->val=n.val;
			n.val=k;
		}
	}
	if(n.rchild!=nullptr)
	{
		max1(*n.lchild);
		max1(*n.rchild);
	}
	else if(n.lchild!=nullptr)
	{
		if(n.lchild->val>n.val)
		{	
			k=n.lchild->val;
			n.lchild->val=n.val;
			n.val=k;
		}
	}
}

int main()
{
	int q,i,j,k,lenth;
	double arr[10];
	double pivot;
	node n[10];
	cout<<"input lenth :"<<endl;
	cin>>lenth;
	cout<<"input the array :"<<endl;
	for(q=1;q<=lenth;q++)
	{
		cin>>arr[q];
		n[q].num=q;
		n[q].val=arr[q];
	}
	n[1].lchild=&n[2];
	n[1].rchild=&n[3];
	for(q=2;q<=lenth;q++)
	{
		n[q].parent=&n[q/2];
		if(q*2<=lenth)
			n[q].lchild=&n[q*2];
		else
			n[q].lchild=nullptr;
		if(q*2+1<=lenth)
			n[q].rchild=&n[q*2+1];
		else
			n[q].rchild=nullptr;
	}
	//sort
	max1(n[1]);
	i=lenth;
	while(i>1)
	{
		arr[i]=n[1].val;
		n[1].val=n[i].val;
		if(n[i].parent->rchild!=nullptr)
			n[i].parent->rchild=nullptr;
		else
			n[i].parent->lchild=nullptr;
		max1(n[1]);
		i--;
	}
	arr[1]=n[1].val;

	//output
	cout<<"the sorted array is:"<<endl;
	for(q=1;q<=lenth;q++)
		cout<<arr[q]<<" ";
	cout<<endl;
	return 1;
}