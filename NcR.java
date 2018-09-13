
import java.util.*;
import java.lang.*;
import java.io.*;
// NOTE : USE MEMOIZATION FOR OPTIMIZATION
class NcR {
    
    static public int nCr(int n,int r){
        long MOD=1000000007L;
        if(r>n) return 0;
        long ncr[][]=new long[n+1][n+1];
        for(int i=0;i<=n;i++)
            ncr[i][0]=1L;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%MOD;
                // Recurrence Used : nCr(n, r) = nCr(n-1, r-1) + nCr(n-1, r)
        return (int)ncr[n][r];
        
    } 
    
	public static void main (String[] args) {
	    Scanner sc=new Scanner(System.in);
	    int t=sc.nextInt();
	    while(t-->0){
	        System.out.println(nCr(sc.nextInt(),sc.nextInt()));
	    }
	}
}
