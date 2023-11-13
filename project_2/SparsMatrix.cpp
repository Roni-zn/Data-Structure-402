#include <iostream>
using namespace std;


int main()
{
	int user_input,c=0,n,m;
	int Spars[50][3];
	cout<<"Enter nomber of rows and column:"<<endl;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>user_input;
			if(user_input!=0)
			{
				c++;
				Spars[c][0]=i;
				Spars[c][1]=j;
				Spars[c][2]=user_input;
			}
			
		}
		cout<<endl;
	}
	Spars[0][0]=n;
	Spars[0][1]=m;
	Spars[0][2]=c;
	for(int i=0;i<=c;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<Spars[i][j]<<"  ";
		}
		cout<<endl;
	}
	return 0;
}