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
typedef pair<long long, long long> PII;
typedef vector<long long> VI;
typedef vector<LL> VLL;
typedef vector<PII> VPII;

int main() {
	#ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    VPII v;
    map<pair<long long,long long>,long long> m;
    map<long long,long long> a,b;
    for(long long i=0;i<n;i++){
    	long long x,y;
    	cin>>x>>y;
    	a[x]+=1;
    	b[y]+=1;
    	v.pb(make_pair(x,y));
    	m[make_pair(x,y)]+=1;
    }
    long long ans=0;
    map<long long, long long>::iterator itr; 
	for (itr = a.begin(); itr != a.end(); ++itr) { 
    	if(itr->second>1)
    		ans+=(itr->second)*(itr->second-1)/2;
    }
    for (itr = b.begin(); itr != b.end(); ++itr) { 
    	if(itr->second>1)
    		ans+=(itr->second)*(itr->second-1)/2;
    }
    for(long long i=0;i<n;i++){
    	if(m[v[i]]>1){
    		ans-=m[v[i]]*(m[v[i]]-1)/2;
    		m[v[i]]=0;
    	}
    }	
    cout<<ans<<endl;
	return 0;
}
