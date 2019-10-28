#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
int* bin;
int r=0;
int m;
void d2b(int n)
{
	int l=m+r;
	//bin=new int[l];
	for(int i=0;i<m+r;i++)
	{
		bin[i]=0;
	}
	int i=0;
	for(int i=0;n>0;i++)
	{
		bin[i]=n%2;
		n=n/2;
	}
}
int main()
{
	cout<<"Enter number of message bits: ";
	cin>>m;
	int M[m];
	cout<<"Enter the message: ";
	for(int i=0;i<m;i++)
	{
		cin>>M[i];
	}
	for(r=0;pow(2,r)<m+r+1;r++);
	cout<<"Number of redundant bits: "<<r<<endl;
	bin=new int[m+r];
	int HC[m+r];
	int c=0;
	cout<<"Total bits: "<<m+r<<endl;
	cout<<"Hamming Code: ";
	int count;
	for(int i=0,j=r-1,k=0;i<m+r;i++)
	{
		if((m+r-i)%((int)pow(2,j))==0)
		{
			j--;
			HC[i]=00;
		}
		else
		{
			HC[i]=M[k];
			if(M[k]==1)
			{
				c++;
			}
			k++;
		}
	}
	for(int i=m+r-1,j=0;i>=0;i--)
	{
		if(m+r-i==pow(2,j))
		{
			count=0;
			for(int k=0;k<m+r;k++)
			{
				d2b(k+1);
				if(bin[j]==1)
				{
					if(HC[m+r-1-k]==0)
						count++;
				}
			}
			if(count%2==1)
			{
				HC[i]=1;
			}
			else
			{
				HC[i]=0;
			}
			j++;
		}
	}
	for(int i=0;i<m+r;i++)
	{
		cout<<HC[i]<<" ";
	}
	cout<<endl<<endl;
	int R[m+r];
	cout<<"Received bits: ";
	for(int i=0;i<m+r;i++)
	{
		cin>>R[i];
	}
	int P[r]={0};
	for(int i=m+r-1,j=0;i>=0;i--)
	{
		if(m+r-i==pow(2,j))
		{
			count=0;
			for(int k=0;k<m+r;k++)
			{
				d2b(k+1);
				if(bin[j]==1)
				{
					if(R[m+r-1-k]==0)
						count++;
				}
			}
			if(count%2==1)
			{
				P[j]=1;
			}
			else
			{
				P[j]=0;
			}
			j++;
		}
	}
	int e=0;
	for(int j=0;j<r;j++)
	{
		e=e+(P[j]*pow(2,r-1-j));
	}
	cout<<endl;
	if(e==0)
	{
		cout<<"Successful transmission"<<endl;
	}
	else
	{
		cout<<"Error at bit: "<<e<<endl;
	}
}

