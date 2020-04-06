#include <bits/stdc++.h> 
using namespace std; 

class Graph { 
    int V; 
  
    list<int>* adj; 
  
    void DFSUtil(int v, bool visited[]); 
  
public: 
    Graph(int V); 
  
    void addEdge(int v, int w); 
    int NumberOfconnectedComponents(); 
}; 
int Graph::NumberOfconnectedComponents() 
{ 
    bool* visited = new bool[V]; 
    int count = 0; 
    for (int v = 0; v < V; v++) 
        visited[v] = false; 
  
    for (int v = 0; v < V; v++) { 
        if (visited[v] == false) { 
            DFSUtil(v, visited); 
            count += 1; 
           // cout<<endl;
        } 
    } 
  
    return count; 
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
	
    visited[v] = true; 
  
    list<int>::iterator i; 
	//cout<<v<<" ";
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 
  
int main() 
{	int n,m;
	cin>>n>>m;
	
    Graph g(n); 
    vector<vector<int> > vec; 
    for(int i=0;i<n;i++){
    	int x;
    	cin>>x;
    	vector<int> v;
    	for(int j=0;j<x;j++){
    		int z;
    		cin>>z;
    		v.push_back(z);
    	}
    	sort(v.begin(),v.end());
    	vec.push_back(v);
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<vec[i].size();j++){
    		for(int k=i;k<n;k++){
    			if(binary_search(vec[k].begin(), vec[k].end(), vec[i][j]))
    				g.addEdge(i,k);
    		}
    	}
    }
    cout << g.NumberOfconnectedComponents()-1; 
  
    return 0; 
} 
