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

int main() {
	#ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cna=0,cnb=0,ans1=0,ans2=0;
    for(int i=0;i<n;i++){
    	if(s[i]=='a')
    		cna++;
    	if(s[i]=='b')
    		cnb++;
    }
    vector<int> A;
	for(int i=0;i<n;i++){
		if(s[i]=='a')
			A.pb(i);
	}
	if(cna<=k)
		ans1=n;
	else {
		int z=cna-k,tmp=0;
		//show(A.size());
		for(int i=0;i<=z;i++){
			tmp=0;
			if(i==0){
				tmp=A[A.size()-z];
				
			}
			else if(i==z){
				tmp=n-1-A[i-1];
			}
			else{
				// show(i);
				//  show(A[i-1]);
				//  show(A[A.size()-z+i]);
				tmp=A[A.size()-z+i]-1-A[i-1];
				
			}
			//show(tmp);
			if(tmp>ans1)
				ans1=tmp;
			
		}
		//cout<<ans1<<endl;
		
	}
	vector<int> B;
	for(int i=0;i<n;i++){
		if(s[i]=='b')
			B.pb(i);
	}
	if(cnb<=k)
		ans2=n;
	else {
		int z=cnb-k,tmp=0;
		//show(B.size());
		for(int i=0;i<=z;i++){
			tmp=0;
			if(i==0){
				tmp=B[B.size()-z];
				
			}
			else if(i==z){
				tmp=n-1-B[i-1];
			}
			else{
				// show(A[i-1]);
				// show(A[A.size()-i]);
				tmp=B[B.size()-z+i]-1-B[i-1];
				
			}
			//show(tmp);
			if(tmp>ans2)
				ans2=tmp;
			
		}
		//cout<<ans1<<endl;
		
	}
	// show(ans1);
	// show(ans2);
	cout<<max(ans1,ans2)<<endl;
	
	return 0;
}
