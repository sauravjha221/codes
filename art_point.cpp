#include<bits/stdc++.h>
using namespace std ;
#define INF 1000000007
class graph
{
	public :
	int V ;
	vector<vector<int> > adj ;
	vector<bool> vis ;
	vector<int> par ;
	graph(int V) ;
	void addedge(int x,int y) ;


	vector<bool> articulation_vertex ;
	vector<int> dfs_low , dfs_num ;
	void art() ;
	int dfsroot,cnt,rcnt ;
	void dfs(int) ;
};

graph::graph(int V)
{
	this->V = V ;
	adj.resize(V) ;
	vis.assign(V,0) ; par.assign(V,-1) ;
	articulation_vertex.assign(V,0) ;
	dfs_low.assign(V,INF) ;dfs_num.assign(V,INF) ;
	cnt = 0;
}

void graph::addedge(int x,int y)
{
	adj[x].push_back(y) ; 
	adj[y].push_back(x) ;
}

void graph::dfs(int i)
{
	vis[i] = 1 ; 
	dfs_num[i] = dfs_low[i] = ++cnt ;
	for(auto it = adj[i].begin();it!=adj[i].end();it++)
	{
		if(!vis[*it])
		{
			//cout<<i<<" "<<dfsroot<<endl ;
			if(i==this->dfsroot) this->rcnt++ ;
			
			par[*it] = i ;
			dfs(*it) ;
			if(dfs_low[*it]>=dfs_num[i]) articulation_vertex[i] = true ;
			dfs_low[i] = min(dfs_low[i],dfs_low[*it]) ;
		}	
		else if(*it != par[i]) dfs_low[i] = min(dfs_low[i],dfs_num[*it]) ;
	}
}
void graph::art()
{
	for(int i = 0;i<V;i++)
	{
		if(!vis[i])
		{
			this->rcnt = 0;
			this->dfsroot = i ;
			dfs(i) ;
			//cout<<dfsroot<<" "<<cnt<<endl ;
			articulation_vertex[i] = (rcnt > 1) ;
		}
	}
	for(int i = 0;i<V;i++)if(articulation_vertex[i]) cout<<i<<" ";
}
int main()
{
	int n,m, x, y;
	cin>>n>>m;
	graph g(n) ;
	for(int i = 0;i<m;i++)
	{
		cin>>x>>y ;
		g.addedge(x,y) ;
	}
    g.art() ;
}
