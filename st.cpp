#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL); 
// #define int long long int
struct node
{
	int val;	
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
		values.resize(2*size);
	}
	node single(int x)
	{
		node temp={x};
		return temp;
	}
	node merge(node a, node b)
	{
		node res={a.val+b.val};
		return res;
	}
	void set(int i, int v, int start, int lx, int rx)
	{
		if (rx-lx==1) 
		{
			values[start]=single(v);
			return;
		}
		int mid=lx+(rx-lx)/2;
		if (i<mid)
		{
			set(i,v,2*start+1,lx,mid);
		}
		else
		{
			set(i,v,2*start+2,mid,rx);
		}
		values[start]=merge(values[2*start+1],values[2*start+2]);
	}
	void set(int i, int v)
	{
		set(i,v,0,0,size);
	}
	node calculate(int l, int r, int start, int lx, int rx)
	{
		if (lx>=r or rx<=l) return NEUTRAL;
		if (lx>=l and rx<=r) return values[start];
		int mid=lx+(rx-lx)/2;
		auto x=calculate(l,r,2*start+1,lx,mid);
		auto y=calculate(l,r,2*start+2,mid,rx);
		return merge(x,y);
	}
	node calculate(int l,int r)
	{
		return calculate(l,r, 0, 0, size);
	}
};
int32_t main() 
{
	IOS;
    int n,m;
	cin>>n>>m;
	segtree st;
	st.init(n);
	for (int i=0;i<n;i++)
	{
		int v;
		cin>>v;
		st.set(i,v);
	}
	cout<<st.calculate(0,n).val<<"\n";
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		// st.set(l,r);
		cout<<st.calculate(l,r).val<<"\n";
	}
	return 0;
}
