#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define len(x) x.size()
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
#define mp(x, y) make_pair((x), (y))
#define show(x) cout<< #x <<" is "<< x <<"\n"

const int mod=1000000007;
//const int mod=998244353;

typedef vector<int> vi;
typedef vector<ll> vll;
 
ll f[300007]; 
  
ll pow(ll a, ll b, ll MOD) 
{ 
 ll x=1,y=a;  
 while(b > 0) 
 	{ 
 		if(b%2 == 1) 
 	{ 
 		x=(x*y); 
 		if(x>MOD) x%=MOD; 
 	} 
 	y = (y*y); 
 	if(y>MOD) y%=MOD;  
 	b /= 2; 
 	} 
 return x; 
}  
 
ll InverseEuler(ll n, ll MOD) 
{ 
 return pow(n,MOD-2,MOD); 
} 
  
ll C(ll n, ll r, ll MOD) 
{ 
  
 return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD; 
} 
 

void solve() {
	
}
 
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	// f[0] = 1; 
	// for(int i = 1 ; i <= 300006 ; i++) 
	// 	f[i] = (f[i-1]*i)%INF; 
	int t=1;
	//cin>>t;
	while(t--)
		solve();
	return 0;
}
