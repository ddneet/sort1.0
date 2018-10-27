#include<iostream>
using namespace std;

void merge_sort(int *arr1, int *arr2, int len1, int len2){
	int *newarr = (int*)calloc(len1+len2, sizeof(int));
	int p=0, q=0, i=0;
	while(p<len1 && q<len2){
		if(arr1[p]<=arr2[q])
			newarr[i++]=arr1[p++];
		else
			newarr[i++]=arr2[q++];
	}
	while(p<len1)
		newarr[i++]=arr1[p++];
	while(q<len2)
		newarr[i++]=arr2[q++];
	for(int i=0;i<len1+len2;i++)
		arr1[i]=newarr[i];
	free(newarr);
}

void total(int *arr, int len){
	if(len==2){
		if(arr[0]>arr[1])
			swap(arr[0],arr[1]);
	}else{
		total(arr,(len+1)/2);
		if(len-(len+1)/2>=2)
			total(&arr[(len+1)/2],len-(len+1)/2);
		merge_sort(arr,&arr[(len+1)/2],(len+1)/2,len-(len+1)/2);
	}
}

int main(){
	int Arr[]={4,1,2,16,10,3,8,7,9};
	int len=9;
	total(Arr,len);
	for(int i=0;i<len;i++)
		cout<<Arr[i]<<" ";
	cout<<endl;
	return 1;
}