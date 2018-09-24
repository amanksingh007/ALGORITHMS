import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
class SegTree{
    int tree[];
    int arr[];
    int N;
    SegTree(int ar[],int n){
        tree=new int[3*n+1];
        arr=ar.clone();
        N=n;
        build(1,1,N);          // 1-based indexing
    }
    private void build(int curnode,int start,int end){
        if(start==end)
            tree[curnode]=arr[start];
        else{
            int mid=(start+end)/2;
            build(2*curnode,start,mid);
            build(2*curnode+1,mid+1,end);
            tree[curnode]=Math.min(tree[2*curnode],tree[2*curnode+1]);   //Range Minimum
        }
    }
    public void update(int index,int newvalue){
        updateNode(1,1,N,index,newvalue);
    }
    private void updateNode(int curnode,int start,int end,int index,int newvalue){
        if(start==end)
            tree[curnode]=newvalue;
        else{
            int mid=(start+end)/2;
            if(start<=index && index<=mid)
                updateNode(2*curnode,start,mid,index,newvalue);
            else
                updateNode(2*curnode+1,mid+1,end,index,newvalue);
            tree[curnode]=Math.min(tree[2*curnode],tree[2*curnode+1]);
        }
    }
    
    public int query(int left,int right){
        return getMin(1,1,N,left,right);
    }
     private int getMin(int curnode,int start,int end,int left,int right){
        if(left>end || right<start)
            return Integer.MAX_VALUE;
        if(left<=start && right>=end)
            return tree[curnode];
        int mid=(start+end)/2;
        int l=getMin(2*curnode,start,mid,left,right);
        int r=getMin(2*curnode+1,mid+1,end,left,right);
        return Math.min(l,r);
    }
    
}

class SegmentTree {
    public static void main(String args[] ) throws Exception {
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer str=new StringTokenizer(br.readLine());
    int n=Integer.parseInt(str.nextToken());
    int q=Integer.parseInt(str.nextToken());
    int arr[]=new int[++n];arr[0]=Integer.MAX_VALUE;
    str=new StringTokenizer(br.readLine());
    for(int i=1;i<n;arr[i++]=Integer.parseInt(str.nextToken()));
    SegTree tree=new SegTree(arr,n-1);
    while(q-->0){
        str=new StringTokenizer(br.readLine());
        if(str.nextToken().equals("q")){
            System.out.println(tree.query(Integer.parseInt(str.nextToken()),
                            Integer.parseInt(str.nextToken())));
                            
            
        }
        else
        {
            tree.update(Integer.parseInt(str.nextToken()),
                            Integer.parseInt(str.nextToken()));
        }
    }
    }
}
