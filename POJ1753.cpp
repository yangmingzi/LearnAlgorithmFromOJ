//这种算法141MS,196K
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

/*
//这种算法47ms,1088K
#include <iostream>
#include <cstring>
 
#define count 16
#define rwcount 4
#define bitwidth 16
#define maxlength 65536
#define copyarr(source,dest) dest = source;
 
typedef unsigned short round_status;
typedef unsigned int uint;
 
using namespace std;
 
bool used[65536];
 
void output(int steps)
{
       cout << steps;
}
 
void init(round_status &pstatus)
{
	memset(used, 0, sizeof(used));
	pstatus = 0;
	char c;
	for (uint i = 0; i < count; ++i)
	{
		do
                {
                	cin >> c;
                }
                while (!(c == 'w' || c == 'b'));
		if (c == 'b')
			pstatus = pstatus | (1 << (15 - i));
 
       }
}
 
void flip(round_status &pstatus, int x, int y)
{
	pstatus = pstatus ^ (1 << (bitwidth - (x * rwcount + y) - 1));
	if (x > 0)
	{
		pstatus = pstatus ^ (1 << (bitwidth - ((x - 1) * rwcount + y) - 1));
	}
	if (y > 0)
	{
		pstatus = pstatus ^ (1 << (bitwidth - (x * rwcount + y - 1) - 1));
	}
	if (x < rwcount - 1)
	{
		pstatus = pstatus ^ (1 << (bitwidth - ((x + 1) * rwcount + y) - 1));
	}
	if (y < rwcount - 1)
	{
		pstatus = pstatus ^ (1 << (bitwidth - (x * rwcount + y + 1) - 1));
	}
}
 
bool check(round_status pstatus)
{
	return (pstatus == 0 || (~pstatus) == 0 || pstatus == 65535);
}
 
bool hassame(round_status status)
{
	return used[status];
}
 
// Find the result. 
void search(round_status &pstatus)
{
	round_status status[maxlength];
	int step[maxlength];
	int pf = 0, pc = 1;
	step[0] = 0;
	status[0] = pstatus;
	used[pstatus] = true;
	do
	{
		for (uint i = 0; i < rwcount; ++i)
		{
			for (uint j = 0; j < rwcount; ++j)
			{
                       		status[pc] = status[pf];
				flip(status[pc], i, j);
				if (hassame(status[pc]))
				{
					continue;
				}
				step[pc] = step[pf] + 1;
				used[status[pc]] = true;
				if (check(status[pc]))
				{
					output(step[pf] + 1);
					return;
				}
				++pc;
				if (pc > maxlength - 1)
				{
					cout << "Impossible";
					return;
				}
			}
		}
		++pf;
 
	}
	while ((pf < pc));
	cout << "Impossible";
	return;
}
 
int main(void)
{
	round_status start_status; // start status of the field.
	init(start_status);
	if (check(start_status))
	{
		output(0);
		return 0;
	}
	search(start_status);
	return 0;
}
*/