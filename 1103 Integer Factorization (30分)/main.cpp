//1103 Integer Factorization (30��)
#include <bits/stdc++.h>
using namespace std;
int n, k, p, maxFacSum = -1;
vector<int> v, ans, tempAns;
void init()
{
	int temp=0,index=1;
	while(temp<=n)
	{
		v.push_back(temp);
		temp=pow(index,p);
		index++;
	}
}
void dfs(int index,int tempSum,int tempK,int facSum)
{
	// ����1��������k����
	if(tempK==k)
	{
		if(tempSum==n&&facSum>maxFacSum)
		{
			ans=tempAns;
			maxFacSum=facSum;
		}
		return ;
	}
	
	
	
	while(index>=1)
	{
		if(tempSum+v[index]<=n)
		{
			tempAns[tempK]=index;
			dfs(index,tempSum+v[index],tempK+1,facSum+index);
		}
		 // ����2�� δ������k������Ŀ��ֵС�ڵ���0
		if(index==1)
			return ;
		index--;
	}
}
int main() 
{
	cin>>n>>k>>p; 
	init();// ��ʼ�����е�������Ӧ����
	tempAns.resize(k);//����k���ռ� 
	dfs(v.size()-1,0,0,0);
	if(maxFacSum==-1)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	cout<<n<<"=";
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0)
			cout<<"+";
		cout<<ans[i]<<"^"<<p;
	}
	return 0;
}

////���ȳ�ʼ�����ܷ������������ӣ���������t = k ^ P��k <= N, t <=N������������һά����v[k]�С�
//Ȼ���������������������ĿҪ��Ľ���ǵ������������У�����ÿһ��dfs֮�󶼼���ָ���ĺͲ����л��ݣ�
//���������tempAns�У��ڷ�����������������У�ֻҪfacSum>maxFacSum�͸������к�ans��
//���ڵ�������ͬ�����У���ĿҪ�����ֵ�������һ�������������ǴӴ�ĵ�����ʼ���ǣ�
//�������������Ľ������������ͬ������£�һ�����ֵ������ȼ��ߵģ�
//���ԶԴ�������账������ϸ�ڿ����롣

