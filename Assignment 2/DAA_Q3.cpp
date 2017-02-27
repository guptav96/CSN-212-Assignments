#include<bits/stdc++.h>
using namespace std;
int search(int dp[], int l,int r,int key)
{
    while(r>l+1)
    {
        int m=l+(r-l)/2;
        if(dp[m]>=key){
        	r=m;
		}
        else{
        	l=m;
		}
    }
    return r;
}
 
int solve(int a[], int  l)
{
    int len=1;
    int dp[10001];
    for(int i=0;i<10001;i++)
    	dp[i]=0;
    dp[0]=a[0];
    for(int i=1;i<l;i++)
    {
        if(a[i]<dp[0])
        	dp[0]=a[i];
 
        else if(a[i]>dp[len-1])
        	dp[len++]=a[i];
        else
        	dp[search(dp,-1,len-1,a[i])]=a[i];
    }
    return len;
}
int main()
{
	int t;
    cin>>t;
    while(t--)
    {
        int n;
    	cin>>n;
    	int a[2*n];
        for(int i=0;i<n;i++){
        	cin>>a[i];
        	a[i+n]=a[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
        	ans=max(ans,solve(a+i,n));
        }
        cout<<ans<<endl;
    }
    return 0;
}
 
