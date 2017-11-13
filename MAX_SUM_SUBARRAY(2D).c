//   MAX_SUM_SUBARRAY(2D)
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define LL long long
#define and &&
#define or ||
#define max(a,b) (a>b)?a:b;
#define s(n) scanf("%lld",&n)
#define ss(n,m) scanf("%lld%lld",&n,&m)
#define sss(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)


LL int kadane(LL int *arr,LL int n){
	LL int i,curmax,res;
	curmax=arr[1];
	res=arr[1];
	for(i=2;i<=n;i++){
		curmax=max(arr[i],arr[i]+curmax);
		res=max(res,curmax);
	}
	return(res);
}


int main(){
	LL int arr[100][100],temp[100]={0},m,n,i,j,k,t,curmax,res,l;
	s(t);
	while(t--){
		curmax=-99999;res=-9999;
		ss(m,n);
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				s(arr[i][j]);
			}
		}
			
		for(i=1;i<=n;i++){
			for(j=i;j<=n;j++){
				for(k=1;k<=m;k++)
				temp[k]+=arr[k][j];
				curmax=kadane(temp,m);
				res=max(res,curmax);
			}
	         
			for(l=1;l<=n;l++)
				temp[l]=0;
			
		}
		
		printf("%lld\n",res);
	}
	
  return 0;
  }
		/*
3
4 5
2 1 -3 -4 5
0 6 3 4 1
2 -2 -1 4 -5
-3 3 1 0 3
*/		
				
				
			


