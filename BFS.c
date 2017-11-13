#include<stdio.h>
#include<stdlib.h>
#define or ||
#define and &&
#define s(n) scanf("%d",&n)
#define ss(n,m) scanf("%d%d",&n,&m)
#define new_node (struct node *)malloc(sizeof(struct node))
#define size 20000

               /*QUEUE IMPLIMENTATION STARTS*/
int front=-1; 
int rear=-1;
int queue[size];


void enqueue(int itm){
if(rear==-1 and front==-1){
   ++rear;front++;
   queue[rear]=itm;
}
else
   queue[++rear]=itm;
return;
}

void dequeue(){
	front++;
return;
}
	
int peek(){
	return(queue[front]);
}

               /*QUEUE IMPLIMENTATION ENDS*/

			   
			   /*ADJACENCY-LIST IMPLIMENTATION STARTS*/
			   
struct node{
int data;
struct node *next;
};
struct node *p[size];

void create(int k,int item){
	struct node *new,*q;
	struct node *ptr=p[k];
	new=new_node;
	new->next=NULL;
	new->data=item;
	if(p[k]==NULL){
		p[k]=new;
	}
		else{
			new->next=p[k];
			p[k]=new;
		}
		return;
	}
	
	
	void display(int n){
		struct node *q=p[1];
	if(q==NULL)
		return;
	else{
		int i;
		while(i<=n){
			q=p[i];
			while(q!=NULL){
		    printf("%d ",q->data);
		    q=q->next;
	       }
	    printf("\n");
		i++;
	} 
	}
	return;
}

               /*ADJACENCY-LIST IMPLIMENTATION ENDS*/

int breadth_first_search(int src,int dest){
	int status[size]={0},org[size]={0},track[size]={0},last,i,j,k,x;
	struct node *q;
	front=rear=-1;
		enqueue(src);
		status[src]=1;
		org[0]=0;i=1;
		while(1){
			last=peek();
			dequeue();
			 q=p[last];
			 if(q==NULL){
				//printf("NO PATH\n");
			    return;
				
			 }
			 else{
			while(q!=NULL){
				if(status[q->data]==0){
				enqueue(q->data);
				org[i]=last;
				status[q->data]=1;
				i++;
				}
				if(peek()==dest or queue[rear]==dest)
					break;
				q=q->next;
			}
			if(peek()==dest or queue[rear]==dest)
					break;
			 }
		}
		
	/*	printf("REAR:%d\n",peek());
			for(i=0;i<=rear;i++)
				printf("%d ",queue[i]);
			printf("\n");
			for(j=0;j<i;j++)
				printf("%d ",org[j]);
			*/
			
			
			j=0;track[0]=dest;x=k=rear;
			while(org[x]!=0 and k>=0){
				track[++j]=org[x];
				//k--;
				while(queue[k]!=track[j])
					 k--;
				 x=k;
			}
			printf("PATH IS :");
			for(i=j;i>=0;i--)
				if(i!=0)
				printf("%d-->",track[i]);
			    else
				printf("%d",track[i]);
			
			printf("\n");
			return(j);
	
}
			   
			   
			   
			   
	
	int main(){
		int n,src,dest,edge,start,end;
		struct node *q;
		printf("ENTER NO OF NODES and EDGES\n");
		s(n);s(edge);
		
		while(edge--){
			ss(start,end);
			create(start,end);
			create(end,start);
		}
		//display(n);
		        
		printf("ENTER SOURCE then DESTINATION\n");
		s(src);
		s(dest);
		            printf("%d",breadth_first_search(src,dest));
                //    breadth_first_search(1,8);     // CAN BE CALLED MULTIPLE TIMES
			      //  breadth_first_search(3,6);
		return 0;
	}
		
		