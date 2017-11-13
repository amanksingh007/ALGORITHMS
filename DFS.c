#include<stdio.h>
#include<stdlib.h>
#define or ||
#define and &&
#define s(n) scanf("%d",&n)
#define ss(n,m) scanf("%d%d",&n,&m)
#define new_node (struct node *)malloc(sizeof(struct node))
#define size 200000
                 /*STACK IMPLEMENTATION STARTS*/
int stack[size];
int top=-1;
void push(int itm){
	if(top<size)
		stack[++top]=itm;
	else{
		printf("STACK OVERFLOW");
	    exit(1);
	}
	return;
}

void pop(){
	if(top>-1)
		top--;
	else{
		printf("STACK UNDERFLOW");
        exit(1);
	}
return;
}

int peek(){
return(stack[top]);
}

int isempty(){
  if(top==-1)
      return(1);
  else 
	return(0);  
}
       
	              /*STACK IMPLEMENTATION ENDS*/
				  
				  /*ADJACENCY-LIST IMPLEMENTATION STARTS*/
				  
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
			   
void depth_first_search(int n,int src){
	int track[size],org[size],status[size];struct node *q;
	int i,j,last,k;
	for(i=1;i<=n;i++)
		track[i]=org[i]=status[i]=0;
		push(src);
        last=peek();
        i=0;
		status[src]=1;
        
        while(!isempty()){
           		last=peek();
				track[i]=last;
				i++;
                pop();				
		        q=p[last];
				if(q!=NULL){
					while(q!=NULL){
						if(status[q->data]!=1){
						push(q->data);
					    status[q->data]=1;
						}
						q=q->next;
					}
				}
		}
		for(j=0;j<i;j++){
			if(j!=(i-1))
				printf("%d-->",track[j]);
			else
				printf("%d\n",track[j]);
		   }
		  
}	
			   

int main(){
	int n,src,dest,i,j,k,start,end,last,t,edge;
		
		printf("ENTER NO OF NODES and EDGES\n");
		s(n);s(edge);
		while(edge--){
			ss(start,end);
			create(start,end);
			create(end,start);
		}
		
		//display(n);
		
		s(src);
		
		depth_first_search(n,src);
	
		return 0;
}
				 
				 