#include<iostream>
using namespace std;
int chess[17];
int k;
int judge()
{
	int i;
	for(i=2;i<=16;i++)
		if(chess[i]!=chess[i-1]) return 0;
		return 1;
}
void convert(int i)
{
	chess[i]^=1;
	if(i%4!=1) chess[i-1]^=1;
	if(i%4!=0) chess[i+1]^=1;
	if(i>4) chess[i-4]^=1;
	if(i<13) chess[i+4]^=1;
}
void dfs(int j,int now,int total)//现在到第j个棋子了，翻转了now次，总共翻转了total次。
{
	int i;
	if(now==total)
	{
		k=judge();
		return;
	}
	for(i=j+1;i<=16;i++)
	{
		convert(i);
		dfs(i,now+1,total);
		if(k) return;
		convert(i);//还原。
	}
}
int main()
{
	int i;
	char ch;
	for(i=1;i<=16;i++)//输入，用0代替w，用1代替b。
	{
		cin>>ch;
		if(ch=='w') chess[i]=0;
		else chess[i]=1;
	}
	k=judge();
	if(k) cout<<0<<endl;
	else
	{
		for(i=1;i<=16;i++)//最多翻转16次，枚举。
		{
			k=0;
			dfs(0,0,i);
			if(k) break;
		}
		if(k) cout<<i<<endl;
		else cout<<"Impossible\n";
	}
	return 0;
}