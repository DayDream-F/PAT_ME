//1076 Forwards on Weibo (30分)
#include <iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> G[1010];
bool vis[1010];
int N, L, K;
struct node
{
	int id,layer;//用于标记id 和当前层数 
};
int BFS(node u)
{
	vis[u.id] = true;
	queue<node> q;
	q.push(u);
	int cnt=1;
	while (!q.empty())
	{
		node front = q.front();
	//	cout<<front<<" ";
		q.pop();
		int frontid=front.id;
		for (int v = 0; v < G[frontid].size(); v++)
		{
			int nextid=G[frontid][v];
			if (vis[nextid] == false&&front.layer<L)
			{
				node temp={nextid,front.layer+1};
				q.push(temp);
				//cout << G[front][v] << " ";
				vis[nextid] = true;
				cnt++;
			}
		}
	
	}
	return cnt;
}
int main()
{
	cin >> N >> L;
	for (int i = 1; i <= N; i++)
	{
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			int follow;
			cin >> follow;
			G[follow].push_back(i);
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int query;
		cin >> query;
		node u={query,0}; 
		cout<<BFS(u)<<endl;
		fill(vis, vis + 1010, false);
	}
	return 0;
}
