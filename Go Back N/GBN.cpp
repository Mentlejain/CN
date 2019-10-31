#include<iostream>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
class GBN
{
	public:
	int flag,n,t,sq,ws,ctr;
	GBN();
	void input();
	void sender();
	int receiver();
};
GBN::GBN()
{
	flag=0;
	t=1;
	ctr=1;
}
void GBN::input()
{
	cout<<"Enter the number of bits in sequence number: ";
	cin>>sq;
	ws=pow(2,sq)-1;
	cout<<"Window size: "<<ws<<endl;
	cout<<"Enter total number of frames: ";
	cin>>n;
}
void GBN::sender()
{
	if(flag==0)
	{
		for(int i=0;i<ws and i<n;i++)
		{
			cout<<"Frame: "<<i+1<<" Sent;"<<endl;
			t++;
		}
	}
	while(ctr<=n)
	{
		int bk=receiver();
		if(bk==1)
		{
			cout<<"Acknowledgement received"<<endl;
			cout<<"Frame: "<<ctr<<" Sent Successfully";
			flag=1;
			ctr++;
		}
		if(flag==1 and t<=n)
		{
			cout<<"Window Shift"<<endl;
			cout<<"Frame: "<<t<<" Sent";
			t++;
			flag=0;
		}
		else
		{
			cout<<"Acknowledgement not received"<<endl;
			for(int i=ctr;i<t;i++)
			{
				cout<<"Frame: "<<i<<" must be resent"<<endl;
			}
		}
	}
}
int GBN::receiver()
{
	int num=rand()%2;
	getch();
	return num;
}
int main()
{
	GBN gbn;
	gbn.input();
	gbn.sender();
}
