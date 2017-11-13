#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
	(*a)=(*b)^(*a)^((*b)=(*a));
	return;
}
int partition(int *a,int start,int end){
	int i,j=start,pivot=a[end];
	for(i=start;i<end;i++)
	{
		
		if(a[i]<=pivot)
		{  swap(&a[i],&a[j]);
			j++;
		}
	}
	swap(&a[j],&a[end]);
	return(j);
}
	
void sort(int *a,int left,int right){
	int p;
	if(left<right){
		p=partition(a,left,right);
		sort(a,left,p-1);
		sort(a,p+1,right);
	}
	else
		return;
}
		
	int main(){
	int *arr,n,i;
	printf("ENTER SIZE OF ARRAY:");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("ENTER THE ARRAY ELEMENTS\n");
	for(i=0;i<n;i++)
		scanf("%d",(arr+i));
	sort(arr,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	return 0;
}