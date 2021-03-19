#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
int n,a[maxn];long long k;
int main()
{
	scanf("%d %lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=(n>>1);i++)
	{
		long long s=(0ll+a[i+1]-a[i]+a[n-i+1]-a[n-i])*i;
		if(k>=s) k-=s;
		else return printf("%lld\n",a[n-i+1]-a[i]-k/i),0;
	}
	return puts("0"),0;
}