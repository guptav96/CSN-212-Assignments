#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int a[n];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int dppos[n+1],dpneg[n+1];
	for(int i=0;i<=n;i++)
	{
		dppos[i]=0;
		dpneg[i]=0;
	}
	dppos[0]=1;
	dpneg[0]=1;
	int ans=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j])
			dppos[i]=max(dppos[i],dpneg[j]+1);
			if(a[i]<a[j])
			dpneg[i]=max(dpneg[i],dppos[j]+1);
		}
		ans=max(ans,max(dppos[i],dpneg[i]));
	}
	cout<<ans<<endl;
	return 0;
}
