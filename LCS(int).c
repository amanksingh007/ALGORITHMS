#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define and &&
#define or ||
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b

int LCS[10001][10001];

void find_LCS_DP(int m,int *arr1,int n,int *arr2){
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(arr1[j]==arr2[i])
				LCS[i][j]=LCS[i-1][j-1]+1;
				else
					LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
       return;
}

void print_LCS(int m,int n){
  int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%d ",LCS[i][j]);
		}
		printf("\n");
	}
	return;
}

void get_LCS(int m,int *arr1,int n,int *arr2,int *res){
	int i=n,j=m,l=LCS[n][m];
	while(i>0 and j>0){
		if(arr1[j]==arr2[i]){
			res[--l]=arr1[j];
			j--;i--;
		}
			else
				if(LCS[i][j]==LCS[i-1][j])
					i--;
				else
					j--;
	}
	return;
}
	
int main(){
    int m,n,i,j;
	int arr1[10002],arr2[10002],res[10004];
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
		scanf("%d",&arr1[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&arr2[i]);
	find_LCS_DP(m,arr1,n,arr2);
	//print_LCS(m,n);
	get_LCS(m,arr1,n,arr2,res);
	for(i=0;i<LCS[n][m];i++)
		printf("%d ",res[i]);
	return;
}
	