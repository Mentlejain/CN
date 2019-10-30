#include<iostream>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
struct frame
{
	string data;
};
class SNW
{
	private:
		frame* F;
		int n;
		int s;
		int f;
		int ack;
	public:
		SNW();
		void input();
		void sender(int);
		void receiver();
};
SNW::SNW()
{
	f=1;
	s=0;
	n=1;
}
void SNW::input()
{
	cout<<"Enter number of frames: ";
	cin>>n;
	F=new frame[n];
	cout<<"Enter Frame data"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>F[i].data;
	}
	sender(0);
}
void SNW::sender(int timer)
{
	if(f<=n)
	{
		cout<<endl<<"SENDER"<<endl;
		if(timer==-1)
		{
			cout<<"Timer stopped: Acknowledgement not received"<<endl;
		}
		cout<<"Frame "<<f<<" sent\tFrame data: "<<F[f-1].data<<"\tSequence Numbeer: "<<s<<endl;
		getch();
		if(f>n)
		{
		}
		else
			receiver();
	}
}
void SNW::receiver()//int f,int &s)
{
	int r=(rand()%3)+1;
	cout<<endl<<"RECEIVER"<<endl;
	switch(r)
	{
		case 1:
		{
			cout<<"Frame "<<f<<" received \t Data: "<<F[f-1].data<<"\t Sequence Numbeer: "<<s<<endl;
			cout<<"Acknowledgement sent"<<endl;
			f++;
			s=(s+1)%2;
			sender(0);
			break;
		}
		case 2:
		{
			cout<<"Frame "<<f<<" received \t Data: "<<F[f-1].data<<"\t Sequence Numbeer: "<<s<<endl;
			cout<<"Acknowledgement sent"<<endl;
			sender(-1);
			break;
		}
		case 3:
		{
			cout<<"Frame lost"<<"\t Sequence Numbeer: "<<s<<endl;
			cout<<"Negative Acknowlegement sent"<<endl;
			sender(0);
			break;
		}
	}
}
int main()
{
	SNW snw;
	snw.input();
	getch();
}
