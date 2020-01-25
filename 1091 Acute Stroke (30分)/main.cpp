#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int x,y,z;	
};
int M,N,L,T;
int arr[1300][130][80];
bool vis[1300][130][80]={false};
int X[6]={1,0,0,-1,0,0};
int Y[6]={0,1,0,0,-1,0};
int Z[6]={0,0,1,0,0,-1};
bool judge(int x,int y,int z)
{
	if(x<0||x>=M||y<0||y>=N||z<0||z>=L)
		return false;
	if(arr[x][y][z]==0||vis[x][y][z]==true)
		return false;
	return true;
}
int bfs(int x,int y,int z)
{
	int cnt=0;
	queue<Node> q;
	Node temp;
	temp.x=x;
	temp.y=y;
	temp.z=z;
	q.push(temp);
	vis[x][y][z]=true;
	while(!q.empty())
	{
		Node top=q.front();
		q.pop();
		cnt++;
		for(int i=0;i<6;i++)
		{
			int tx=top.x+X[i];
			int ty=top.y+Y[i];
			int tz=top.z+Z[i];
			if(judge(tx,ty,tz))
			{
				vis[tx][ty][tz]=true;
				temp.x=tx;
				temp.y=ty;
				temp.z=tz;
				//bfs(temp.x,temp.y,temp.z);
				q.push(temp);
			}
		}
	}
	if(cnt>=T)
		return cnt;
	return 0;
}
int main() 
{
	cin>>M>>N>>L>>T;
	for(int i=0;i<L;i++)
	{
		for(int j=0;j<M;j++)
		{
			for(int k=0;k<N;k++)
			{
				cin>>arr[j][k][i];
			}
		}
	}
	int ans=0;
	for(int i=0;i<L;i++)
	{
		for(int j=0;j<M;j++)
		{
			for(int k=0;k<N;k++)
			{
				if(arr[j][k][i]!=0&&vis[j][k][i]==false)
				{
					ans+=bfs(j,k,i);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
