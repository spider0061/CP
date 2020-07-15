#include <bits/stdc++.h>
using namespace std;
long long A[131073];
struct segtree {
	long long value;
	long long level;
} seg[4*131073];
void build(long long low,long long high,long long node) {
	if(low>high)
		return;
	if(low==high){
		seg[node].value=A[low];
		seg[node].level=0;
		return;
	}
	long long mid=(low+high)/2;
	build(low,mid,2*node+1);
	build(mid+1,high,2*node+2);
	seg[node].level=seg[2*node+1].level+1;
	if(seg[node].level%2==1) {
		seg[node].value=seg[2*node+1].value | seg[2*node+2].value;
	}
	else {
		seg[node].value=seg[2*node+1].value ^ seg[2*node+2].value;	
	}
	return;
}
void update(long long low,long long high,long long node,long long ind,long long val) {
	if(low>high)
		return;
	if(low==high){
		seg[node].value=val;
		return;
	}
	long long mid=(low+high)/2;
	if(ind<=mid)
		update(low,mid,2*node+1,ind,val);
	else
		update(mid+1,high,2*node+2,ind,val);
	if(seg[node].level%2==1) {
		seg[node].value=seg[2*node+1].value | seg[2*node+2].value;
	}
	else {
		seg[node].value=seg[2*node+1].value ^ seg[2*node+2].value;	
	}
	return;
}
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	long long po=pow(2,n);
	for(int i=0;i<po;i++)
		cin>>A[i];
	build(0,po-1,0);
	// update(0,po-1,0,0,4);
	// for(int i=0;i<7;i++)
	// 	cout<<seg[i].value<<" ";
	for(int i=0;i<m;i++){
		int p,q;
		cin>>p>>q;
		update(0,po-1,0,p-1,q);
		cout<<seg[0].value<<endl;
	}
	
	return 0;
}
