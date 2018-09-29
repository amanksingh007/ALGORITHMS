import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.io.*;
class SegTreeLazy{
    int tree[];
	int lazy[];
    int arr[];
    int N;
    SegTreeLazy(int ar[],int n){
        tree=new int[10*n+1];
		lazy=new int[10*n+1];
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
            tree[curnode]=tree[2*curnode]+tree[2*curnode+1];
        }
    }
    public void update(int x,int y,int newvalue){
        updateRange(1,1,N,x,y,newvalue);
    }
    private void updateRange(int curnode,int start,int end,int x,int y,int newvalue){
		if(lazy[curnode]!=0){
			tree[curnode]+=(end-start+1)*lazy[curnode]; 
			if(start!=end){ 
				lazy[curnode*2]+=lazy[curnode]; 
				lazy[curnode*2+1]+=lazy[curnode]; 
			} 
			lazy[curnode]=0; 
		}
		if(start>end || start>y || end<x)
			return;
		if(start>=x && end<=y){
			//System.out.println("C:"+curnode+"S:"+start+"E:"+end);
			tree[curnode]+=(end-start+1)*newvalue; 
			if (start!=end) { 
				lazy[curnode*2]+=newvalue; 
				lazy[curnode*2+1]+=newvalue; 
			}
			return; 
		}
        int mid=(start+end)/2; 
		updateRange(curnode*2,start,mid,x,y,newvalue); 
		updateRange(curnode*2+1,mid+1,end,x,y,newvalue); 
        tree[curnode]=tree[curnode*2]+tree[curnode*2+1]; 
    }
    
    public int query(int left,int right){
        return getSum(1,1,N,left,right);
    }
     private int getSum(int curnode,int start,int end,int x,int y){
        if(lazy[curnode]!=0){
			tree[curnode]+=(end-start+1)*lazy[curnode]; 
			if (start!=end){ 
				lazy[curnode*2]+=lazy[curnode]; 
				lazy[curnode*2+1]+=lazy[curnode]; 
			} 
			lazy[curnode] = 0; 
		}
		if(start>end || start>y || end<x)
            return 0;
        if(x<=start && y>=end)
            return tree[curnode];
        int mid=(start+end)/2;
        int l=getSum(2*curnode,start,mid,x,y);
        int r=getSum(2*curnode+1,mid+1,end,x,y);
        return (l+r);
    }
    
}

class LazySegmentTree{
    public static void main(String args[] ) throws Exception{
		Reader sc=new Reader();
    /*   SPOJ SEGTREE PROBLEM */
		int q1=sc.nextInt();//Integer.parseInt(nmq[0]);
		int q2=sc.nextInt();//Integer.parseInt(nmq[1]);
		int n=sc.nextInt();//Integer.parseInt(nmq[2]);
		int arr[]=new int[n+1];
		StringBuilder sb=new StringBuilder("");
		SegTreeLazy seg=new SegTreeLazy(arr,n);
		while(q1-->0){
			int x=sc.nextInt();//Integer.parseInt(qu[0]);
			int y=sc.nextInt();//Integer.parseInt(qu[1]);
				seg.update(x+1,y+1,1);
		}
		while(q2-->0){
			int x=sc.nextInt()+1;//Integer.parseInt(br.readLine())+1;
				sb.append(""+seg.query(x,x)).append("\n");
		}
		//System.out.println("*********************************");
		System.out.println(sb.toString());
	}
	
	static class Reader{
        final private int BUFFER_SIZE = 1000006;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
 
        public Reader(){
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public Reader(String file_name) throws IOException{
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public String readLine() throws IOException{
            byte[] buf = new byte[100006]; // line length
            int cnt = 0, c;
            while((c=read())!=-1){
                if(c=='\n')
                    break;
                buf[cnt++]=(byte)c;
            }
            return new String(buf,0,cnt);
        }
 
        public int nextInt() throws IOException{
            int ret=0;
            byte c=read();
            while(c<=' ')
                c=read();
            boolean neg=(c=='-');
            if(neg)
                c=read();
            do{
                ret=ret*10+c-'0';
            }while((c=read())>='0' && c<='9');
            if(neg)
                return -ret;
            return ret;
        }
 
        public long nextLong() throws IOException{
            long ret=0;
            byte c=read();
            while(c<=' ')
                c=read();
            boolean neg=(c=='-');
            if(neg)
                c=read();
            do{
                ret=ret*10+c-'0';
            }
            while((c=read())>='0' && c<='9');
            if(neg)
                return -ret;
            return ret;
        }
 
        public double nextDouble() throws IOException{
            double ret=0,div = 1;
            byte c=read();
            while(c<=' ')
                c=read();
            boolean neg =(c=='-');
            if(neg)
                c=read();
            do{
                ret=ret*10+c-'0';
            }
            while((c=read())>='0' && c<='9');
			if(c=='.'){
                while ((c = read()) >= '0' && c <= '9'){
                    ret+=(c-'0')/(div*=10);
                }
            }
            if(neg)
                return -ret;
            return ret;
        }
 
        private void fillBuffer() throws IOException{
            bytesRead = din.read(buffer,bufferPointer=0,BUFFER_SIZE);
            if (bytesRead==-1)
                buffer[0]=-1;
        }
 
        private byte read() throws IOException{
            if (bufferPointer==bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
		public void close() throws IOException{
            if (din==null)
                return;
            din.close();
        }
    }
	
}
