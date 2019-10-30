#include<iostream>
#include<conio.h>
using namespace std;
void CRCD(int* msg,int m,int*gen,int g)
{
	for(int i=0;i<m;i++)
	{
		if(msg[i]==gen[0])
		{
			for(int j=0,k=i;j<g;j++,k++)
			{
				if(msg[k]^gen[j])
				{
					msg[k]=1;
				}
				else
				{
					msg[k]=0;
				}
			}
		}
	}
	for(int i=0;i<m+g-1;i++)
		cout<<msg[i]<<" ";
	cout<<endl;
}
int main()
{
	int m,g;
	cout<<"At Sender's end"<<endl;
	cout<<"Enter the number of message bits: ";
	cin>>m;
	cout<<"Enter number of generator bits: ";
	cin>>g;
	int temp[m+g-1]={0};
	int msg[m+g-1]={0};
	int gen[g];
	cout<<"Enter the message: ";
	for(int i=0;i<m;i++)
	{
	
		cin>>msg[i];
		temp[i]=msg[i];
	}
	cout<<"Enter the generator: ";
	for(int i=0;i<g;i++)
		cin>>gen[i];
	CRCD(temp,m,gen,g);
	cout<<"CRC: ";
	for(int i=0;i<g-1;i++)
	{
		cout<<temp[m+i]<<" ";
		msg[m+i]=temp[m+i];
	}
	cout<<endl;
	cout<<"Transmitted message: ";
	for(int i=0;i<m+g-1;i++)
	{
		cout<<msg[i]<<" ";
	}
	cout<<endl;
	cout<<"At Receiver's end: "<<endl;
	cout<<"Received message: ";
	for(int i=0;i<m+g-1;i++)
	{
		cin>>msg[i];
		temp[i]=msg[i];
	}
	CRCD(temp,m,gen,g);
	for(int i=0;i<g-1;i++)
	{
		if(temp[m+i])
		{
			cout<<"Error in received message";
			getch();
			return 0;
		}
	}
	cout<<"No error in received message"<<endl;
	cout<<"Message: ";
	for(int i=0;i<m;i++)
	{
		cout<<msg[i]<<" ";
	} 
	cout<<endl;
	getch();
}
