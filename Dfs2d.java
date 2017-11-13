import java.io.*;
import java.util.*;
 
class Dfs2d{
	public static int minimum(int... args){
		int min=1000000000;
		for(int x:args)
			if(x<min)
				min=x;
		return min;
	}
	
			
	public static int find(int curx,int cury,int prvx,int prvy,int turn,char grid[][],boolean visited[][]){
		int m=grid.length;
		int n=grid[0].length;
		int a=-1,b=-1,c=-1,d=-1;
		
		if(curx<0 || cury<0 || curx>=m || cury>=n || grid[curx][cury]=='*')
			return (1<<7);
		if(visited[curx][cury])
			return (1<<7);
		if(grid[curx][cury]=='H')
			return turn;
	//	System.out.println(curx+" "+cury);
		visited[curx][cury]=true;
		if(curx==prvx && cury==prvy){
			a=find(curx+1,cury,curx,cury,turn,grid,visited);
			b=find(curx-1,cury,curx,cury,turn,grid,visited);
			c=find(curx,cury+1,curx,cury,turn,grid,visited);
			d=find(curx,cury-1,curx,cury,turn,grid,visited);
			return minimum(a,b,c,d);
		}
		else{
		if(curx==prvx){
			if(cury>prvy){
			    a=find(curx+1,cury,curx,cury,turn+1,grid,visited);
			    b=find(curx-1,cury,curx,cury,turn+1,grid,visited);
			    c=find(curx,cury+1,curx,cury,turn,grid,visited);
		   }
		   else
		   {
			   a=find(curx+1,cury,curx,cury,turn+1,grid,visited);
			   b=find(curx-1,cury,curx,cury,turn+1,grid,visited);
			   c=find(curx,cury-1,curx,cury,turn,grid,visited);
		   }
		}
		else{
			if(curx<prvx){
				a=find(curx,cury+1,curx,cury,turn+1,grid,visited);
		     	b=find(curx,cury-1,curx,cury,turn+1,grid,visited);
		    	c=find(curx-1,cury,curx,cury,turn,grid,visited);
			}
			else{
				a=find(curx,cury+1,curx,cury,turn+1,grid,visited);
		     	b=find(curx,cury-1,curx,cury,turn+1,grid,visited);
		    	c=find(curx+1,cury,curx,cury,turn,grid,visited);
			}
		}
		return minimum(a,b,c);
		//return ((c>((a>b)?a:b))?c:((a>b)?a:b));
		}
	}
	
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n=sc.nextInt();
		int m=sc.nextInt();
		char grid[][]=new char[n][m];
		boolean visited[][]=new boolean[n][m];
		int startx=0,starty=0;
		for(int i=0;i<n;i++){
			String str=sc.next();
				for(int j=0;j<str.length();j++){
					grid[i][j]=str.charAt(j);
			    	if(grid[i][j]=='V'){
				    	startx=i;
				    	starty=j;
				    }
			    }
		}
			int length=0;
	 //System.out.println(starty+" "+startx);
	 length=find(starty,startx,starty,startx,length,grid,visited);
	 if(length==(1<<7))
	 System.out.println("-1");
	 else
	 System.out.println(length);
	}
	
}       