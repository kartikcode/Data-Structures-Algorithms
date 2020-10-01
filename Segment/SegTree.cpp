struct segtree
{
	int size;
	vector<int> sum;
	
	void init(int n)
	{
		size=1;
		while(size<n)
		size*=2;
		sum.assign(2*size,0LL);
	}
	//Uncomment the following part of code if you want to directly build it from a vector.
    	//This is also a bit faster because set function requires n calls while this builds in 1 call.
	/*void build(vector<int> &a, int x, int lx, int rx)
	{
		if(rx-lx==1)
		{
            if(lx<(int)a.size())
			{
				sum[x]=a[lx];
				return;
			}
		}
		int m=(lx+rx)/2;
		build(a,2*x+1,lx,m);
		build(a,2*x+2,m,rx);
		sum[x]=sum[2*x+1]+sum[2*x+2];
	}
	
	void build(vector<int> &a)
	{
		build(&a,0,0,size);
	}*/
	
	void set(int i, int v, int x, int lx, int rx)
	{
		if(rx-lx==1)
		{
			sum[x]=v;
			return;
		}
		int m=(lx+rx)/2;
		if(i<m)
		set(i,v,2*x+1,lx,m);
		else
		set(i,v,2*x+2,m,rx);
		sum[x]=sum[2*x+1]+sum[2*x+2];
	}
	
	void set(int i, int v)
	{
		set(i,v,0,0,size);
	}
	
	int findsum(int l,int r,int x,int lx,int rx)
	{
		if(lx>=r||rx<=l) return 0;
		if(lx>=l&&rx<=r) return sum[x];
		int m=(lx+rx)/2;
		int s1=findsum(l,r,2*x+1,lx,m);
		int s2=findsum(l,r,2*x+2,m,rx);
		return s1+s2;
	}
	
	int findsum(int l,int r)
	{
		return findsum(l,r,0,0,size);
	}
};
