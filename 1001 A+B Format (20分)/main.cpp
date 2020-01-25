#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int a,b,c;
	cin>>a>>b;
	c=a+b;
	string res=to_string(c);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i];
		if(res[i]=='-')
			continue;
		if((i+1)%3==res.size()%3&&(i!=res.size()-1))//×¢Òâ´Ó×óÍùÓÒÊý 
			cout<<",";
	}
	return 0;
}
