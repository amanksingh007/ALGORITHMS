     // THE FENWICK TREE
#include<stdio.h>
#include<stdlib.h>
#define or ||
#define s(n) scanf("%d",&n)

int BIT[1000], a[1000], n;
/*void update(int x, int val)
{
      for(; x <= n; x += x&-x){
       // BIT[x]=1;
		BIT[x] += val;
	  }
}*/
void update(int x, int val){
	while(x<=n){
		BIT[x] += val;
		if(x%2==1)
			x+=1;
		else{
			if(!(x&(x-1)))//x==1 or x==2 or x==4 or x==8 or x==16 or x==32
				x=x<<1;
				else x+=2;
		}
	}
		return;
	}



/*int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x){
        sum += BIT[x];
		//printf("%3.0d ",sum);
	 }
     return sum;
}*/
int query(int x)
{
     int sum = 0;
	 while(x>0){

		 if(x%2==1){
			 sum+=BIT[x];
			 x--;
		 }
		 else{
		 if(!(x&(x-1))){
			 sum+=BIT[x];
			 x=x>>1;
		 }
			 else{
				 sum+=BIT[x];
				 x-=2;
			 }
		 }
	 }
	 return;
}



int main(){
	int t,i,j,x,type;
		//printf("ENTER SIZE & THEN ELEMENTS OF THE ARRAY:");
	//s(n);
    n=31;
	for(i=1;i<=n;i++){
		//s(a[i]);
		a[i]=i;
		update(i,a[i]);
	}
	//printf("ENTER NO. OF QUERIES:");
	printf("\n");
	for(i=1;i<=n;i++)
		printf("%2.0d ",BIT[i]);
	s(t);

	while(t--){
		printf("ENTER TYPE OF QUERIES:");
		s(type);
		switch(type){
			case 0:printf("ENTER INDEX & UPDATED VALUE FOR QUERIES:");
			       s(j);s(x);
				   update(j,x);
				   break;
		    case 1:printf("ENTER INDEX-VALUE FOR PREFIX-SUM CALCULATION QUERIES:");
			       s(j);
				   printf("%d\n",query(j));
				   break;
		    default:printf("WRONG CHOICE\n");
		}
		for(i=1;i<=n;i++)
		printf("%3.0d ",BIT[i]);
	}
	return 0;
}
