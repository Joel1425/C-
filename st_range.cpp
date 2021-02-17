#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL); 
// #define int long long int
struct node
{
	long long val;	
};
struct segtree
{
	int size;
	vector<node> values;
	node NEUTRAL={0};
	void init(int n)
	{
		size=1;
		while(size<n)
		{
			size*=2;
		}
		values.assign(2*size,{0LL});
		
	}
	// node single(int x)
	// {
	// 	node temp={x};
	// 	return temp;
	// }
	// node merge(node a, node b)
	// {
	// 	node res={a.val+b.val};
	// 	return res;
	// }
	node get(int i, int start, int lx, int rx)
	{
		if (rx-lx==1)
		{
			return values[start];
		}
		int mid=lx+(rx-lx)/2;
		node res;
		if (i<mid)
		{
			res=get(i,2*start+1,lx,mid);
		}
		else
		{
			res=get(i,2*start+2,mid,rx);
		}
		res.val+=values[start].val;
		return res;
	}
	node get(int i)
	{
		return get(i,0,0,size);
	}
	// void set(int i, int v, int start, int lx, int rx)
	// {
	// 	if (rx-lx==1) 
	// 	{
	// 		values[start]=single(v);
	// 		return;
	// 	}
	// 	int mid=lx+(rx-lx)/2;
	// 	if (i<mid)
	// 	{
	// 		set(i,v,2*start+1,lx,mid);
	// 	}
	// 	else
	// 	{
	// 		set(i,v,2*start+2,mid,rx);
	// 	}
	// 	values[start]=merge(values[2*start+1],values[2*start+2]);
	// }
	// void set(int i, int v)
	// {
	// 	set(i,v,0,0,size);
	// }
	void add(int l, int r, int v, int start, int lx, int rx)
	{
		if (lx>=r or rx<=l) return;
		if (lx>=l and rx<=r) 
		{
			values[start].val+=v;
			return;
		}
		int mid=lx+(rx-lx)/2;
		add(l,r,v,2*start+1,lx,mid);
		add(l,r,v,2*start+2,mid,rx);
	}
	void add(int l, int r, int v)
	{
		add(l,r,v,0,0,size);
	}
};
int32_t main() 
{
	IOS;
    int n,m;
	cin>>n>>m;
	segtree st;
	st.init(n);
	while(m--)
	{
		int i;
		cin>>i;
		if (i==1)
		{
			int l,r,v;
			cin>>l>>r>>v;
			st.add(l,r,v);
		}
		else
		{
			int k;
			cin>>k;
			cout<<st.get(k).val<<"\n";
		}
	}
	return 0;
}
