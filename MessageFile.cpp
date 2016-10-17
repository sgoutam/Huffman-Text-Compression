#include<iostream>
using namespace std;
#include<conio.h>
#include<string>
#include<fstream>

int main()
{
	string bit[3];
	string filename="MessageFile.txt";
	ofstream file1(filename,ios::out);
	for(int i=0;i<3;i++)
	{
		cout<<"enter the char:";
		cin>>bit[i];
		file1.write((char*)&bit[i],sizeof(bit[i]));
	}
	file1.close();
	getch();
}

