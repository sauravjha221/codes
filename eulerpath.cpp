#include<bits/stdc++.h>
using namespace std ;
vector<vector<int> > adj ;
map<pair<int,int> , bool > mark ;
int n , m,x,y ;
list<int> cyc ;
void tour(list<int>::iterator it ,int u)
{
	for(int j = 0 ;j <adj[u].size();j++)
	{
		int v = adj[u][j] ;
		if(!mark[{u,v}])
		{
			mark[{u,v}] = mark[{v,u}] = 1 ;
			tour(cyc.insert(it,u),v) ;
		}
	}
}
int main()
{
	cin>>n>>m ; adj.resize(n) ;
	for(int i =0;i<m;i++)
	{
		cin>>x>>y ;
		adj[x].push_back(y) ;
		adj[y].push_back(x) ;
		mark[{x,y}] = 0 ;
		mark[{y,x}] = 0 ;
	}
	tour(cyc.begin(),0) ;
	for(auto &no:cyc)cout<<no<<" ";
}