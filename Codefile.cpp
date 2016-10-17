#include<iostream>
using namespace std;
#include<conio.h>
#include<string>
#include<fstream>
int main()
{
    char c;
	string code;
	string filename="CodeFile.txt";
	ofstream file1(filename,ios::out);
	for(int i=0;i<26;i++)
	{
		cout<<"enter the char  :";
		cin>>c;
		cout<<"enter the code  :";
		cin>>code;
		file1.write((char*)&c,sizeof (c));
		file1.write((char*)&code,sizeof (code));
	}
	file1.close();
	getch();
}

