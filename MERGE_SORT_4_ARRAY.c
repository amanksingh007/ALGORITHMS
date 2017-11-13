#include<stdio.h>
#include<stdlib.h>
#define s(n) scanf("%d",&n)
#define and &&
#define or ||
int n;
void sort(int arr[],int l,int h);
void merge(int arr[],int low,int mid,int high);

void sort(int arr[],int l,int h){
	int m;
	m=(l+h)/2;
	if(l<h){
		sort(arr,l,m);
		sort(arr,m+1,h);
		merge(arr,l,m,h);
	}
}

void merge(int arr[],int low,int mid,int high){
	int i,k,temp[1000],l,h,m;
	l=low;
	m=mid+1;
	i=low;
	h=high;
	
	while((l<=mid) && (m<=high)){
		if(arr[l]<=arr[m]){
			temp[i]=arr[l];
			l++;
		}
		else{
			temp[i]=arr[m];
			m++;
		}
	//	printf("l:%d,i:%d,j:%d,temp[i]:%d\n",l,i,j,temp[i]);
      i++;
	}
	if(l>mid){
  
	  for(k=m;k<=high;k++){
	  temp[i]=arr[k];
	  i++;
  }
	}
	else{
  for(k=l;k<=mid;k++){
     temp[i]=arr[k];
      i++;
  }
	}
  for(k=low;k<=high;k++)
	  arr[k]=temp[k];
  return;
}
	
int main(){
	system("cls");
	int i;
	s(n);
	int a[1000];
	for(i=0;i<n;i++)
		s(a[i]);
	
	sort(a,0,n-1);
	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}