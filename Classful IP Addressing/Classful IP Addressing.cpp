#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
char ipclass(string s)
{
	string str;
	int i=0;
	while(s[i]!='.')
	{
		str[i]=s[i];
		i++;
	}
	i--;
	int ip=0;
	int j=1;
	while(i>=0)
	{
		ip=ip+(str[i]-48)*j;
		j=j*10;
		i--;
	}
	 if (ip >=1 && ip <= 127) 
        return 'A'; 
  
    // Class B 
    else if (ip >= 128 && ip <= 191) 
        return 'B'; 
  
    // Class C 
    else if (ip >= 192 && ip <= 223) 
        return 'C'; 
  
    // Class D 
    else if (ip >= 224 && ip <= 239) 
        return 'D'; 
  
    // Class E 
    else
        return 'E'; 
}
int main()
{
	string s;
	cout<<"IP Address: ";
	getline(cin,s);
	cout<<"Given IP Address belongs to class "<<ipclass(s)<<endl;
}
