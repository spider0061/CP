#include<bits/stdc++.h>
using namespace std;

#define show(x) cout<< #x <<" is "<< x <<"\n"
#define pb(t) push_back(t)
#define len(t) t.size()
#define all(t) t.begin(),t.end()
#define fs first
#define sc second
#define mp(x, y) make_pair((x), (y))

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<PII> VPII;

const int N=1000001;
vector<int> adj[N];
vector<int> col[2];
int mark[N]={0};
int vis[N]={0};


bool dfs(int v,int color=2){
	mark[v]=color;
	vis[v]=1;
	col[color-1].pb(v);
	for(auto u: adj[v]){
		if(vis[u]==0){
			if(dfs(u,3-color)==false){
				return false;
			}
		}
		if(mark[u]==color)
			return false;
	}
	return true;
}

int main() {
	#ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    //cout<<mark[100];
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u-1].pb(v-1);
		adj[v-1].pb(u-1);
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			if(adj[i].size()==0)
				continue;
			
			if(!dfs(i)){
				//show(i);
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	for(auto x: col){
		cout<<x.size()<<endl;
		for(auto y:x)
			cout<<y+1<<" ";
		cout<<endl;
	}
	return 0;
}
