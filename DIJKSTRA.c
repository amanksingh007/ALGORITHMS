//SINGLE SOURCE ALL SHORTEST PATH:DIJKSTRA ALGO
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
#define new_node (struct node *)malloc(sizeof(struct node))
#define size 1000
#define INF 9999999
int N;
int result[size];
			   /*ADJACENCY-LIST IMPLIMENTATION STARTS*/
			   
struct node{
int data;
int wt;
struct node *next;
};
struct node *p[size];

void create(int k,int neighbour,int weight){
	struct node *new,*q;
	struct node *ptr=p[k];
	new=new_node;
	new->next=NULL;
	new->data=neighbour;
	new->wt=weight;
	if(p[k]==NULL){
		p[k]=new;
	}
		else{
			new->next=p[k];
			p[k]=new;
		}
		return;
	}
	
	
	void display_list(int n){
		struct node *q=p[1];
	if(q==NULL)
		return;
	else{
		int i;
		while(i<=n){
			q=p[i];
			while(q!=NULL){
		    printf("%d %d |",q->data,q->wt);
		    q=q->next;
	       }
	    printf("\n");
		i++;
	} 
	}
	return;
}

                          /*ADJACENCY-LIST IMPLIMENTATION ENDS*/

                          /*HEAP IMPLEMENTATION BEGINS*/
struct vertex{
	int id;
	int value;
}arr[size];

 void swap(struct vertex *a,struct vertex *b){
	 struct vertex c;
	c=*a;
	*a=*b;
	*b=c;
 }

void min_heapify(struct vertex *arr,int i){
	int l,r,smallest,temp;
	l=2*i;
	r=2*i+1;
    if(l<=N and arr[l].value<arr[i].value)
		smallest=l;
	else
		smallest=i;
	if(r<=N and arr[r].value<arr[smallest].value)
		smallest=r;
	if(smallest!=i){
		swap(&arr[i],&arr[smallest]);
		
		/*struct node temp;
         temp.id=arr[i].id;
		arr[i].id=arr[smallest].id;
		arr[smallest].id=temp.id;
		
		temp.value=arr[i].value;
		arr[i].value=arr[smallest].value;
		arr[smallest].value=temp.value;
		*/
		min_heapify(arr,smallest);
	}
	    else
			return;
}

void build_min_heap(struct vertex *arr){
	int i;
	for(i=N/2;i>=1;i--)
		min_heapify(arr,i);
		
	return;
}

void heap_extract_min(struct vertex *arr,struct vertex *findmin){
	
	if(N<1){
		//printf("HEAP UNDERFLOW\n");
		//exit(1);
		return;
	}
	findmin->id=arr[1].id;
	findmin->value=arr[1].value;    //STORING RESULTS
	arr[1].id=arr[N].id;
	arr[1].value=arr[N].value;
	N=N-1;
	min_heapify(arr,1);
	return;
}

void update_min_heap(struct vertex *arr,int i,int key_val){
	if(i>N or i<1){
		printf("NOT A VALID ENTRY\n");
		return;
	}
	if(key_val>arr[i].value){
		arr[i].value=key_val;
		min_heapify(arr,i);
	}
	else
		if(key_val<arr[i].value){
			arr[i].value=key_val;
			while(i>1 and (arr[i].value<arr[i/2].value)){
				swap(&arr[i],&arr[i/2]);                     //HEAPIFYING UP
				i=i/2;
			}
		}
		return;
}/*
void insert_new_key(int *arr,int key_val){
	int i;
	N++;
	i=N;
	arr[N]=key_val;
	while(i>1 and arr[i]<arr[i/2]){
		swap(&arr[i],&arr[i/2]);
		i=i/2;
	}
	return;
}

void delete(int *arr,int i){
	int x;
	update_min_heap(arr,i,INT_MIN);
	x=heap_extract_min(arr);
	return;
}
*/
int heap_is_empty(){
	if(N<1)
		return(1);
	return(0);
}
void display_heap(struct vertex *arr){
	int i;
	for(i=1;i<=N;i++)
		printf("%d %d\n",arr[i].id,arr[i].value);
	return;
}

                          /*HEAP IMPLEMENTATION ENDS*/
int findpos(int idx){
	int i;
	for(i=1;i<=N;i++){
		if(arr[i].id==idx)
			return(i);
	}
}
						  
void sssp(int src){
	int visited[size+1]={0},frnd,weight,pos,newweight,curvalue,curid;
	struct vertex findmin;
	//display_heap(arr);
	while(!heap_is_empty()){
	    heap_extract_min(arr,&findmin);
		curid=findmin.id;
		curvalue=findmin.value;
		result[curid]=curvalue;
		//printf("%d ",result[curid]);
		visited[curid]=1;
		struct node *q=p[curid];
	//	printf("%d ",q->data);
		while(q!=NULL){
			//printf("%d ",q->data);
			if(!visited[q->data]){
				frnd=q->data;
				weight=q->wt;
				newweight=result[curid]+weight;
				pos=findpos(frnd);
				if(newweight<arr[pos].value)
					update_min_heap(arr,pos,newweight);//arr[pos].value=newweight;
			}
			q=q->next;
		}
	}
	return;
}
		


int main(){
	
	int i,j,max,x,y,w,t,edges,src,choice=1,tot;
	struct vertex findmin;
	s(N);s(edges);
	tot=N;
	t=edges;
	while(t--){
		sss(x,y,w);
		create(x,y,w);
		create(y,x,w);
	}
	//display_list(N);
	for(i=1;i<=N;i++){
		  arr[i].id=i;
		  arr[i].value=INF;
	}
	printf("ENTER SRC:");
	s(src);
	arr[src].value=0;
	build_min_heap(arr);
	sssp(src);
	for(i=1;i<=tot;i++)
		printf("%d  ",result[i]);
		return 0;
}