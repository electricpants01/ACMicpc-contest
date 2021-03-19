#include<bits/stdc++.h>
using namespace std;
int main()
{
long long	int n,m,i,k,j=0,l,t=0;
	cin>>l;
	
	n=2*l;
long long	int a[n];
	if(l%2==0)
	{
	t=1;
	cout<<"NO";
	
	}
	else
	{
		cout<<"YES"<<endl;
		for(i=0;i<n;)
		{
			a[i]=j+1;
			if(j==n-1)
			break;
			j++;
			if(j%2==0)
		{
			i++;
			a[i]=j+1;
			j++;
			i=i+l;
		}
			
			else
			i=i+l;
			if(i>n)
			i=abs(n-i);
		
			
		}
		
	}
	if(t!=1)
{
		for(i=0;i<n;i++)
	cout<<a[i]<<endl;
}
}