//// AMAN KUMAR SINGH   ,REG. NO: 0000062

import java.util.*;
class Pair{
	int a, b,w;
	Pair(int a,int b,int w){
		this.a=a;this.b=b;this.w=w;
	}
}
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
}

class Edge{
	int next;
	int weight;
	boolean exists;
	Edge(int next,int weight){
		this.next=next;
		this.weight=weight;
		this.exists=true;
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
		adj[x].addFirst(new Edge(y,w));
		adj[y].addFirst(new Edge(x,w));
	}
	void disable(Pair ed){
		int x=ed.a;
		int y=ed.b;
		for(int i=0;i<adj[x].size();i++)
			if(adj[x].get(i).next==y){
				adj[x].get(i).exists=false;
				break;
			}
		for(int i=0;i<adj[y].size();i++)
			if(adj[y].get(i).next==x){
				adj[y].get(i).exists=false;
				break;
			}
	}
	void enable(Pair ed){
		int x=ed.a;
		int y=ed.b;
		for(int i=0;i<adj[x].size();i++)
			if(adj[x].get(i).next==y){
				adj[x].get(i).exists=true;
				break;
			}
		for(int i=0;i<adj[y].size();i++)
			if(adj[y].get(i).next==x){
				adj[y].get(i).exists=true;
				break;
			}
	}
			
	void print(){
		for(int i=0;i<nodes;i++){
			System.out.print(i+": ");
			for(int j=0;j<adj[i].size();j++)
				System.out.print("("+adj[i].get(j).next+","+adj[i].get(j).weight+")");
			System.out.println();
		}
	}
	int MinCycle(ArrayList<Pair> arr){
		int min=Integer.MAX_VALUE;
		for(int i=0;i<arr.size();i++){
			Pair p=(Pair)arr.get(i);
			disable(p);
			int dist_xy=Dijkstra(p.a,p.b);
			if(dist_xy+p.w<min)
				min=dist_xy+p.w;
			enable(p);
		}
		return min;
	}
			
		
	int Dijkstra(int src,int dest){
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
		while(pQueue.isEmpty()==false){
			Distance cur=(Distance)pQueue.poll();
			//System.out.println("MINIMUN:"+cur.v+" "+cur.dist);
			if(visited[cur.v])
				continue;
			int curvtx=cur.v;
			result[curvtx]=cur.dist;
			visited[curvtx]=true;
			for(int i=0;i<adj[curvtx].size();i++){
				Edge frnd=(Edge)adj[curvtx].get(i);
				if(visited[frnd.next] || frnd.exists==false)
					continue;
				for(Distance obj:pQueue){
					if(obj.v==frnd.next){
						temp=obj.dist;
						break;
					}
				}
				if(result[curvtx]+frnd.weight<temp){
					int newpath=result[curvtx]+frnd.weight;
					pQueue.offer(new Distance(frnd.next,newpath));
				}
			}	
		}
		return result[dest];
	}
}

class Minc{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		S
		int n=sc.nextInt();
		int edges=sc.nextInt();
		ArrayList<Pair> arr=new ArrayList<Pair>();
		Graph graph=new Graph(n);
		for(int i=0;i<edges;i++){
			int a=sc.nextInt();
			int b=sc.nextInt();
			int c=sc.nextInt();
			graph.push_edge(a,b,c);
			arr.add(new Pair(a,b,c));
		}
		int ds=graph.Dijkstra(1,2);
		
		//graph.print();
		System.out.println(graph.MinCycle(arr));
	}
}
/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

ANS:14
*/
