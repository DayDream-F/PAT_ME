//1003 Emergency (25分) 
#include <bits/stdc++.h>
using namespace std;
int const INF=INT_MAX;
int n,m,c1,c2;
struct Node
{
	int ver,dis;	
};
vector<Node> G[505];
int team[505];
int dis[505];
bool vis[505];
int num[505],t[505];
void Dijkstra(int s)
{
	fill(dis,dis+n,INF);
	dis[s]=0;
	t[s]=team[s];
	num[s]=1;
	for(int i=0;i<n;i++)
	{
		int u=-1,min=INF;
		for(int j=0;j<n;j++)
		{
			if(vis[j]==false&&dis[j]<min)
			{
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) 
			return ;
		vis[u]=true;
		for(int v=0;v<G[u].size();v++)
		{
			int next=G[u][v].ver;
			if(vis[next]==false&&G[u][v].dis!=INF)
			{
				if(G[u][v].dis+dis[u]<dis[next])
				{
					dis[next]=dis[u]+G[u][v].dis;
					t[next]=t[u]+team[next];
					num[next]=num[u];
				}
				else if(G[u][v].dis+dis[u]==dis[next])
				{
					if(t[u]+team[next]>t[next])
					{
						t[next]=t[u]+team[next];
					}
					num[next]=num[next]+num[u];
				} 
				
			}
		}
	}
}
int main() 
{	
	cin>>n>>m>>c1>>c2;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		team[i]=t;
	}
	for(int j=0;j<m;j++) 
	{
		int c3,c4,dis2;
		cin>>c3>>c4>>dis2;
		
		Node temp={c4,dis2};
		Node temp2={c3,dis2};
		G[c3].push_back(temp);
		G[c4].push_back(temp2);//此处注意，有路径即为相互连通 
	}
	Dijkstra(c1);
	cout<<num[c2]<<" "<<t[c2]<<endl; 
	return 0;
}
