#include<iostream>
#include<string>
using namespace std;
int main()	
{
	int i,n,w,s,left,idx,count=0;
	string name[80];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>name[i];
	scanf("%d,%d",&w,&s);

	left=n;
	i=w-1;
while(left)
{

	if(name[i]!="0")
	{
		count++;
		if(count==s)
		{
			cout<<name[i]<<endl;
			name[i]="0";
			count=0;
			left--;
		}
	}
		i++;
		if(i>n-1) i-=n;
}

		
	system("pause");
	return 0;
}