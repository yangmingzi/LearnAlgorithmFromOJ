//all parameters must init
#include<stdio.h>
#include<iostream>
using namespace std;
#define max(a,b) a>b?a:b//define this short and high-frequency function
#define N 100005

int q[N]={-1};//stack depend on array
int w[N];     //record how many recs taller than this rec ,be ready for operate stack
int main()
{
	int n,h;
	
	while(scanf("%d",&n),n)
	{
		int top=0;
		long long ans=0;
		for(int i=1;i<=n+1;i++)
		{
			if(i!=n+1)
				scanf("%d",&h);
			else
				h=0;//deal the last rec 
			if(h>q[top])
				
			{
				q[++top]=h;
				w[top]=1;
			}
			else
			{
				long long cnt=0;
				//unit all left extend Rec and pop redundant item
				while(h<=q[top])
				{
					ans = max(ans,q[top]*(cnt+w[top]));
					cnt = cnt + w[top];
					top--;
				}
				//push now item
				q[++top]=h;
				w[top]=cnt+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}