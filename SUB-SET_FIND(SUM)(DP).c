/*FINDING A SUB-SET OF THE GIVEN ARRAY SUCH THAT SUM OF ELEMENTS IS EQUAL TO GIVEN VALUE (DP SOLUTION)*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define LL long long
#define or ||
#define and &&
#define s(n) scanf("%lld",&n)
#define ss(n,m) scanf("%lld%lld",&n,&m)
#define ssss(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define new_node (struct node *)malloc(sizeof(struct node))



LL int res[1000][10000];

void display(LL int tot,LL int n){
	LL int l,m;
for(l=0;l<n;l++){
	for(m=0;m<=tot;m++){
		printf("%lld ",res[l][m]);
	}
	printf("\n");
	}
}

int find_sum(LL int *arr,LL int n,LL int tot){
	LL int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<=tot;j++){
			if(j==0){     //FOR SUM=0,IT IS ALWAYS TRUE
				res[i][j]=1;
				continue;
			}
			if(i==0){
				if(j==arr[0])
					res[i][j]=1;    //FOR THE FIRST ROW i.e INCLUDING JUST arr[0].
				else
					res[i][j]=0;
			}
			else
				if(res[i-1][j]==1 or res[i-1][j-arr[i]]==1)
					res[i][j]=1;
				else
					res[i][j]=0;
		}
	}
	
	if(res[n-1][tot]==1)
		return(1);
	else
		return(0);
	
	
}

void find_set(LL int tot,int n,LL int exist,LL int *arr){
	LL int i,j,k,sum=0;
	if(exist){
		i=n-1;j=tot;
		//printf("I:%d J:%dval:%d\n",i,j,arr[i]);
		while(i!=0 and j!=0){
			if(res[i-1][j]==1){
				i=i-1;
			}
			else{
				sum+=arr[i];
			   printf("%lld ",arr[i]);    //PRINTS THE REQUIRED SUB_SET( CAN BE STORED IN AN ARRAY...)
				j=j-arr[i];
				i=i-1;
			}
		}
		if(sum<tot)
			printf("%lld ",arr[0]);    //TO ENSURE WHETHER TO ADD arr[0] OR NOT.
	}
	PRINTF("\n");
	return;
}

int main(){
LL int arr[10000],i,j,k,n,t,tot;
s(n);s(t);    //LENGTH OF ARRAY & NO. OF TEST CASES
for(i=0;i<n;i++)
	s(arr[i]);
while(t--){
	s(tot);            // INPUT SUM-VALUE
	if(find_sum(arr,n,tot)){
		//display(tot,n);
		printf("YES\n");
		find_set(tot,n,1,arr);
	}
	else
		printf("NO\n");
	
}
return 0;
}

			
			