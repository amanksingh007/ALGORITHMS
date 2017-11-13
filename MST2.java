import java.util.*;
class Edge implements Comparable<Edge>{
	int a;
	int b;
	int wt;
	Edge(int a,int b,int wt){
		this.a=a;this.b=b;this.wt=wt;
	}
	public int compareTo(Edge edge){
		if(wt==edge.wt)
			return 0;
		else
		if(wt<edge.wt)
			return -1;
		else
			return 1;
	}
}
class Sets{
	int tot_nodes;
	int rank[];
	int parent[];
	ArrayList<Edge> mstEdges;
	Sets(int tot_nodes){
		rank=new int[tot_nodes+2];
		parent=new int[tot_nodes+2];
		this.tot_nodes=tot_nodes;
		mstEdges=new ArrayList<Edge>();
		for(int i=0;i<=tot_nodes;i++){
			parent[i]=i;
			rank[i]=0;
		}
	}
	void reset(){
		for(int i=0;i<=tot_nodes;i++){
			parent[i]=i;
			rank[i]=0;
		}
	}
	int find_set(int node){
		//System.out.println(":"+node+":");
		if(parent[node]!=node)
			parent[node]=find_set(parent[node]);
		return parent[node];
	}
	void union(int node1,int node2){
		int parent1=find_set(node1);
		int parent2=find_set(node2);
		//System.out.println(parent1+" "+parent2);
		if(parent1==parent2)
			return;
		if(rank[parent1]==rank[parent2]){
			parent[parent1]=parent2;
			rank[parent2]++;
		}
		else 
			if(rank[parent1]>rank[parent2])
			parent[parent2]=parent1;
		else
			parent[parent2]=parent1;
		return;
	}
	void print_sets(){
		for(int i=1;i<=tot_nodes;i++)
			System.out.print(find_set(i)+" ");
		return;
	}
	public int kruskals(ArrayList<Edge> edges){
		reset();
		int cost=0;
		for(Edge e:edges){
			int p1=find_set(e.a);
			int p2=find_set(e.b);
			if(p1!=p2){
				cost+=e.wt;
				union(e.a,e.b);
				mstEdges.add(e);
			}
	    }
		for(Edge e:mstEdges)
			System.out.println(e.a+" "+e.b+" "+e.wt);
		return cost;
	}
	public int kruskals2(ArrayList<Edge> edges,Edge ed){
		int cost=0;
		reset();
		for(Edge e:edges){
			if(e.a==ed.a && e.b==ed.b)
				continue;
			int p1=find_set(e.a);
			int p2=find_set(e.b);
			if(p1!=p2){
				cost+=e.wt;
				union(e.a,e.b);
				//mstEdges.add(e);
			}
	    }
		return cost;
	}
	int SecondMst(ArrayList<Edge> edges){
		int mst=kruskals(edges);
		int s=0,e=0,w=0;
		int ans=Integer.MAX_VALUE;int mst2=0;
		for(Edge x:mstEdges){
			mst2=kruskals2(edges,x);
			if(mst2<ans){
				ans=mst2;s=x.a;e=x.b;w=x.wt;
			}
		}
		System.out.println("DELETED:"+s+" "+e+" "+w);
		return mst2;
	}
}
			
    		
class MST2{
	public static void main(String args[]){
		Scanner sc =new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		ArrayList<Edge> edges=new ArrayList<Edge>();
		Sets set=new Sets(n);
		for(int i=0;i<m;i++)
			edges.add(new Edge(sc.nextInt(),sc.nextInt(),sc.nextInt()));
		Collections.sort(edges);
		//for(Edge ed:edges)
			//System.out.println(ed.wt);
		System.out.println("SECOND MST: "+set.SecondMst(edges));
		
		return;
	}
}
	
		
		
	
		
			
		
	