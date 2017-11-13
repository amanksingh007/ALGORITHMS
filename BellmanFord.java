import java.util.*;

class Edge{
	int start;
	int end;
	int weight;
	boolean flag;
	Edge(int start,int end,int weight){
		this.start=start;
		this.end=end;
		this.weight=weight;
		flag=true;
	}
}
class Graph{
	ArrayList<Edge> edges;
	int nodes;
	Graph(int nodes){
		this.nodes=nodes+1;
		edges=new ArrayList<Edge>();
	}
	void addEdge(int x,int y,int w){
		edges.add(new Edge(x,y,w));
	}
	int BF(int src,int dest){
		int INF=Integer.MAX_VALUE;
		int dist[]=new int[nodes];
		int parent[]=new int[nodes];
		Arrays.fill(dist,INF);
		dist[src]=0;
		boolean flag=true;
		for(int vv=0;vv<nodes-1;vv++){
			for(int i=0;i<edges.size();i++){
				Edge current=(Edge)edges.get(i);
				int u=current.start;int v=current.end;int w=current.weight;
				if(u==INF && v==INF)
					continue;
				if(dist[v]>dist[u]+w){
					dist[v]=dist[u]+w;
					parent[v]=u;
				}
				/*else
					if(dist[u]>dist[v]+w){
						dist[u]=dist[v]+w;
						parent[v]=u;
				}*/
			}
		}
		for(int i=0;i<edges.size();i++){
				Edge current=(Edge)edges.get(i);
				int u=current.start;int v=current.end;int w=current.weight;
				if(u==INF && v==INF)
					continue;
				if(dist[v]>dist[u]+w){
					System.out.println("NEGATIVE CYCLE EXISTS");
					System.exit(0);
				}
			}
			//System.out.println("SRC: "+src+"  "+"DEST: "+dest);
		for(Integer x:dist)
			System.out.print(x+" ");
		return dist[dest];
	}
	
	void min_weighted_cycle(){
		int minCycle=Integer.MAX_VALUE;
		int tot=edges.size();
		for(int e=0;e<tot;e++){
			Edge cur=(Edge)edges.remove(e);
			int temp=BF(cur.start,cur.end)+cur.weight;
			System.out.println("DISTANCE:"+temp);
			if(temp<minCycle)
				minCycle=temp;
			edges.add(e,cur);
		}
		System.out.println("THE MINIMUM WEIGHTED CYCLE IS"+((minCycle<Integer.MAX_VALUE)?minCycle:"NO CYCLE"));
	}
}

class BellmanFord{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		ArrayList<Edge> edges=new ArrayList<Edge>();
		System.out.println("Enter n , edges , (u,v,w) & source");
		int n=sc.nextInt();
		int edg=sc.nextInt();
		int dest[]=new int[n+1];
		Graph graph=new Graph(n);
		for(int i=0;i<edg;i++)
			graph.addEdge(sc.nextInt(),sc.nextInt(),sc.nextInt());
		int x=graph.BF(sc.nextInt(),3);
		//graph.min_weighted_cycle();
	}
}
		

