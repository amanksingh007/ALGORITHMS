import java.util.*;

class Distance implements Comparable<Distance>{
	int v;
	int dist;
	Distance(int id,int d){
		v=id;
		dist=d;
	}
	public int compareTo(Distance obj){
		return (this.dist-obj.dist);
	}
	@Override
    public boolean equals(Object o) {
        Distance element = (Distance) o;
        if (v != element.v) return false;
        return true;
    }

    @Override
    public int hashCode() {
        return v;
    }
}

class Edge{
	int next;
	int weight;
	Edge(int next,int weight){
		this.next=next;
		this.weight=weight;
	}
}
@SuppressWarnings("unchecked")
class Graph{
	LinkedList<Edge> adj[];
	int nodes;
	Graph(int n){
		this.nodes=n;
		adj=new LinkedList [n+1];
		for(int i=0;i<=nodes;i++)
			adj[i]=new LinkedList<Edge>();
	}
	void push_edge(int x,int y,int w){
		//System.out.println(x+""+y+""+w);
		adj[x].addFirst(new Edge(y,w));
		adj[y].addFirst(new Edge(x,w));
	}
	void print(){
		for(int i=0;i<nodes;i++){
			System.out.print(i+": ");
			for(int j=0;j<adj[i].size();j++)
				System.out.print("("+adj[i].get(j).next+","+adj[i].get(j).weight+")");
			System.out.println();
		}
	}
	void Dijkstra(int src){
		int INF=99999999;
		int temp=0;
		PriorityQueue<Distance> pQueue=new PriorityQueue<Distance>();
		int result[]=new int[nodes+1];
		boolean visited[]=new boolean[nodes+1];
		for(int i=1;i<=nodes;i++)
			if(i!=src)
				pQueue.offer(new Distance(i,INF));
			else
				pQueue.offer(new Distance(i,0));
			
		for(Distance d:pQueue)
			System.out.println(d.v+" "+d.dist);
		
		while(pQueue.isEmpty()==false){
			Distance cur=(Distance)pQueue.poll();
			System.out.println("MINIMUN:"+cur.v+" "+cur.dist);
			if(visited[cur.v])
				continue;
			int curvtx=cur.v;
			result[curvtx]=cur.dist;
			visited[curvtx]=true;
			for(int i=0;i<adj[curvtx].size();i++){
				Edge frnd=(Edge)adj[curvtx].get(i);
				if(visited[frnd.next])
					continue;
				for(Distance obj:pQueue){
					if(obj.v==frnd.next){
						temp=obj.dist;
						break;
					}
				}
				if(result[curvtx]+frnd.weight<temp){
					System.out.println("XXXX:"+frnd.next+" "+temp);
					int newpath=result[curvtx]+frnd.weight;
					//System.out.println(pQueue.remove(new Distance(frnd.next,temp)));
					pQueue.offer(new Distance(frnd.next,newpath));
				}
			}
			System.out.println("*************************");
			for(Distance d:pQueue)
				System.out.println(d.v+" "+d.dist);
			System.out.println("*************************");
		}
		for(Integer x:result)
			System.out.println(x+" ");
	}
}

class Djk{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int edges=sc.nextInt();
		Graph graph=new Graph(n+1);
		for(int i=0;i<edges;i++)
			graph.push_edge(sc.nextInt(),sc.nextInt(),sc.nextInt());
		graph.print();
		graph.Dijkstra(1);
	}
}
/*
5 6
1 2 1
1 3 5
2 3 2
3 5 3  
3 4 4
4 5 12
*/
