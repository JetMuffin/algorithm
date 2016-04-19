#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int height[10000];
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
		int number;
		int index = 0;
		while(n--)
		{
			scanf("%d",&number);
			int tmp_index = -1;
			for (int i = 0; i < index; ++i)
			{
				if(number>=height[i] && (tmp_index == -1 || height[tmp_index] < height[i]))
				{
					tmp_index = i;
				}
			}
			if(tmp_index != -1)
			{
				height[tmp_index] = number;
			}
			else height[index++] = number; 
		}
		cout<<index<<endl;
	}
}