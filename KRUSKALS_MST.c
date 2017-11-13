//MATCHING SUB-STRING O(n*m)/O(n+m)
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define LL long long
#define and &&
#define or ||
#define max(a,b) (a>b)?a:b;
#define s(n) scanf("%lld",&n)
#define ss(n,m) scanf("%lld%lld",&n,&m)
#define sss(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define size 100000

struct nodes{
	LL int vertex;
	LL int parent;        //STORES_THE_NODE_DETAILS
	LL int rank;
}node[size];

struct segment{
	LL int x;
	LL int y;                //STORES_THE_INPUT_EDGES
	LL int w;
}edge[size],temp[size];



void merge(LL int low,LL int mid,LL int high){
	LL int i,k,l,h,m;
	l=low;
	m=mid+1;
	i=low;
	h=high;
	
	while((l<=mid) && (m<=high)){
		if(edge[l].w<edge[m].w){
			temp[i]=edge[l];
			l++;
		}
		else
			if((edge[l].w==edge[m].w) and ((edge[l].w+edge[l].x+edge[l].y)<=(edge[m].w+edge[m].x+edge[m].y))){
			temp[i]=edge[l];
			//printf("x");
			l++;
		}
		
		else{
			temp[i]=edge[m];
			m++;
		}
		
	//	printf("l:%d,i:%d,j:%d,temp[i]:%d\n",l,i,j,temp[i]);
      i++;
	}
	if(l>mid){
  
	  for(k=m;k<=high;k++){
	  temp[i]=edge[k];
	  i++;
  }
	}
	else{
  for(k=l;k<=mid;k++){
     temp[i]=edge[k];
      i++;
  }
	}
  for(k=low;k<=high;k++)
	  edge[k]=temp[k];
  return;
}

void sort(LL int l,LL int h){
	LL int m;
	m=(l+h)/2;
	if(l<h){
		sort(l,m);
		sort(m+1,h);
		merge(l,m,h);
	}
}


int find_set(int a){
	int pa;
	pa=node[a].parent;
		while(1){
			if(node[pa].parent==pa)
				break;                 //   FINDING_PARENT_OF_a;
			else
				pa=node[pa].parent;
		}
		node[a].parent=pa;           //APPLYING_PATH_COMPRESSION;
	return(pa);
}

void union_set(int pa,int pb){
	int ra,rb;
	ra=node[pa].rank;
	rb=node[pb].rank;                          /*   WORK ON RANK  */
	  if(ra==rb){
			node[pb].parent=pa;
			(node[pa].rank)++;
			}
			else 
				if(ra>rb){
				node[pb].parent=pa;
			}
			else
			{
				node[pa].parent=pb;
			}
	
	return;
}


LL int kruskals(LL int n,LL int edgs){
	LL int mst[size]={0};     //STORES THE EDGES IN MST;
	LL int i=1,a,b,r,pa,pb,j=1,k=1,res=0,ra,rb;
	LL int pos[size];     //  STORES INDEX_NO. OF INCLUDED EDGES;
	while(i<=edgs){
		a=edge[i].x;b=edge[i].y;
		pa=find_set(a);
		pb=find_set(b);          // FINDING SETS
		
	//	printf("(%lld-%lld)\n",pa,pb);
		if(pa!=pb){
			union_set(pa,pb);    //MERGING THE TWO SETS
			mst[j]=a;
			mst[j+1]=b;
			j+=2;
			pos[k]=i;
			k++;
		}
		i++;
	}
   // for(i=1;i<=j-2;i+=2)                     //     PRINTS THE EDGES IN MST
		//printf("(%lld-%lld)\n",mst[i],mst[i+1]);
	for(i=1;i<k;i++)            
	  res+=edge[pos[i]].w;           //   CALCULATING THE MINIMUM SPANNING TREE COST

return(res);
}


int main(){
	LL int n,t,edges,a,b,r,res,edg,i,j,k,pa;
	s(t);
	
	while(t--){
		i=0;
		ss(n,edges);
		edg=edges;
		while(edg--){
			i++;
			sss(a,b,r);
			edge[i].x=a;
			edge[i].y=b;
			edge[i].w=r;
		}
		sort(1,edges);     //CHECK_CRITERIA_FOR_SORTING
		for(i=1;i<=n;i++){
			node[i].vertex=i;
			node[i].parent=i;
			node[i].rank=0;
		}
        res=kruskals(n,edges);
		
				  printf("%lld \n",res);
		
	}
	
	return 0;
}

/*
CRITICAL INPUT
1
4 4
1 2 1
2 4 1
1 3 2
3 4 1
*/



