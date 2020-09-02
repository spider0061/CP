#include <bits/stdc++.h>
using namespace std;
void an(int A[],int n,int f[]) {
    if(n<2);
    else {
        int ans=0;
        int i=0,j=1,tmp=0;;
        while(j<n) {
            if(A[j]<A[i]) {
                tmp+=abs(A[j]-A[i]);
                j++;
            }
            else {
                ans+=tmp;
                
                i=j;
                f[i]=ans;
                j++;
                tmp=0;
            }
        }
    }
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int A[n];
	    for(int i=0;i<n;i++)
	        cin>>A[i];
	    int ans1=0,ans2=0;
	    int f[n]={0},b[n]={0};
	    an(A,n,f);
	    reverse(A,A+n);
	    an(A,n,b);
	    for(int i=1;i<n;i++) {
	        if(f[i]==0 and f[i-1]!=0) {
	            f[i]=f[i-1];
	        }
	        if(b[i]==0 and b[i-1]!=0) {
	            b[i]=b[i-1];
	        }
	    }
	    reverse(b,b+n);
	    for(int i=0;i<n;i++) {
	        //cout<<f[i]<<' '<<b[i]<<endl;
	        ans1=max(ans1,b[i]+f[i]);
	    }
	    cout<<ans1<<endl;
	}
	return 0;
}
