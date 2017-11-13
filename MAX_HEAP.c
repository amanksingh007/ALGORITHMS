//MAXIMUM_BINARY_HEAP
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define LL long long
#define and &&
#define or ||
#define max(a,b) (a>b)?a:b;
#define s(n) scanf("%d",&n)
#define ss(n,m) scanf("%d%d",&n,&m)
#define sss(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define size 100000
int N;
 void swap(int *a,int *b){
	*a=*b^*a^(*b=*a);
 }

void max_heapify(int *arr,int i){
	int l,r,largest,temp;
	l=2*i;
	r=2*i+1;
    if(l<=N and arr[l]>arr[i])
		largest=l;
	else
		largest=i;
	if(r<=N and arr[r]>arr[largest])
		largest=r;
	if(largest!=i){
		swap(&arr[i],&arr[largest]);
		max_heapify(arr,largest);
	}
	    else
			return;
}

void build_max_heap(int *arr){
	int i;
	for(i=N/2;i>=1;i--)
		max_heapify(arr,i);
		
	return;
}

int heap_extract_max(int *arr){
	int max;
	if(N<1){
		printf("HEAP UNDERFLOW\n");
		exit(1);
	}
	max=arr[1];
	arr[1]=arr[N];
	N=N-1;
	max_heapify(arr,1);
	return(max);
}
void update_max_heap(int *arr,int i,int key_val){
	if(i>N){
		printf("NOT A VALID ENTRY\n");
		return;
	}
	if(key_val<arr[i]){
		arr[i]=key_val;
		max_heapify(arr,i);
	}
	else
		if(key_val>arr[i]){
			arr[i]=key_val;
			while(i>1 and (arr[i]>arr[i/2])){
				swap(&arr[i],&arr[i/2]);                     //HEAPIFYING UP
				i=i/2;
			}
		}
		return;
}
void insert_new_key(int *arr,int key_val){
	int i;
	N++;
	i=N;
	arr[N]=key_val;
	while(i>1 and arr[i]>arr[i/2]){
		swap(&arr[i],&arr[i/2]);
		i=i/2;
	}
	return;
}

void delete(int *arr,int i){
	int x;
	update_max_heap(arr,i,INT_MAX);
	x=heap_extract_max(arr);
	return;
}

void display(int *arr){
	int i;
	for(i=1;i<=N;i++)
		printf("%d ",arr[i]);
	return;
}

int main(){
	int i,j,max,arr[size],x,y;int choice=1;
	s(N);
	for(i=1;i<=N;i++)
		s(arr[i]);
	build_max_heap(arr);
	//display(arr);
	printf("1-FIND MAX() ,2-UPDATE_KEY(i,val) ,3-INSERT_NEW_KEY(val) ,4-DELETE(i) ,5-DISPLAY()\n");
	while(1){
		s(choice);
		switch(choice){
		case 0:exit(1);
		       break;
		case 1:printf("%d \n",heap_extract_max(arr));
		       break;
	    case 2:ss(x,y);
		       update_max_heap(arr,x,y);
			   break;
	    case 3:s(x);
		       insert_new_key(arr,x);
			   break;
		case 4:s(x);
		      delete(arr,x);
		       break;
		case 5:display(arr);
		       break;
			   
	}		   
	}
	
	
		return 0;
}