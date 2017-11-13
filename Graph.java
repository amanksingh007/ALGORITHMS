import java.util.*;
import java.io.*;
@SuppressWarnings("unchecked")
class Graph{
	int nodes;
	LinkedList<Integer> adj[];
	Graph(int x){
		nodes=x;
		adj=new LinkedList[x+1];   // FOR 1-indexed GRAPH
		for(int i=0;i<=nodes;i++)
			adj[i]=new LinkedList<Integer>();
	}
	void push_edge(int u,int v){
		adj[u].add(v);             //USE addFirst()  FOR O(1)
		//adj[v].add(u);
		return;
	}
	void display(){
		for(int i=1;i<=nodes;i++){
			Iterator it=adj[i].iterator();
			while(it.hasNext()){
				//int x=it.next();
				System.out.print(it.next()+" ");
			}
			System.out.println();
		}
		return;
	}
	
	void run_dfs(int n,boolean visited[]){
	visited[n]=true;
	System.out.println(n);
	Iterator it=adj[n].iterator();
	while(it.hasNext()){
		Object v=it.next();
		if(!visited[(int)v])
			run_dfs((int)v,visited);
	}
	return;
	}
	
	void dfs(int src){
		boolean[] visited=new boolean[nodes+1];
		run_dfs(src,visited);
	}
	
	void bfs(int src,int dest){
		Queue<Integer> queue=new LinkedList<>();
		boolean visited[]=new boolean[nodes+1];
		int[] org=new int[3*nodes+1];int id_org=-1;
		int[] vertex=new int[3*nodes+1];int id_vtx=-1;
		queue.add(src);
		vertex[++id_vtx]=src;
		org[++id_org]=-1;
		boolean flag=false;
		while(queue.size()!=0){
			if(queue.peek()==dest)
				break;
			int last=queue.poll();
			visited[last]=true;
			Iterator<Integer> it=adj[last].iterator();
			while(it.hasNext()){
				Object o=it.next();
				if(!visited[(int)o]){
					visited[(int)o]=true;
					queue.add((int)o);
				    vertex[++id_vtx]=(int)o;
					org[++id_org]=last;
				}
				if((int)o==dest){
					flag=true;
					break;
			}
		}
		if(flag)
			break;
		}
		/*for(int i=0;i<=id_vtx;i++)
			System.out.println(vertex[i]+" "+org[i]);
		*/
		/*
		if(vertex[id_vtx]!=dest){
			System.out.println("UNREACHABLE");
			return;
		}
		*/
		int[] track=new int[nodes+1];
		int x,j;
		x=id_org;
		j=-1;track[++j]=dest;
		while(org[x]!=-1 && x>=0){
			track[++j]=org[x];
			while(vertex[x]!=track[j])
				x--;
		}
		
		System.out.printf("PATH IS :");	
		
		for(int i=j;i>=0;i--)
			if(i!=0)
			System.out.printf("%d-->",track[i]);
			else
			System.out.printf("%d",track[i]);
			System.out.printf("\n");
			//return(j);
	}
}
	
			