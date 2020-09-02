void dfs(int u, vector<int> adj[],vector<bool> &visited, stack<int> &s) {
    visited[u]=true;
    for(auto &v: adj[u]) {
        if(!visited[v]) {
            dfs(v,adj,visited,s);
        }
    }
    s.push(u);
    return;
}
void dfs1(int u, vector<vector<int>> &adj1,vector<bool> &visited) {
    visited[u]=true;
    for(auto &v: adj1[u]) {
        if(!visited[v]) {
            dfs1(v,adj1,visited);
        }
    }
    return;
}
int kosaraju(int V, vector<int> adj[])
{
    stack<int> s;
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++) {
        if(!visited[i])
            dfs(i,adj,visited,s);
    }
    vector<vector<int>> adj1(V);
    for(int i=0;i<V;i++) {
        for(auto v:adj[i]) {
            adj1[v].push_back(i);
        }
    }
    for(int i=0;i<V;i++)
        visited[i]=false;
    int ans=0;
    while(!s.empty()) {
        int u=s.top();
        s.pop();
        if(!visited[u]) { 
            ans++;
            dfs1(u,adj1,visited);
        }
    }
    return ans;
}