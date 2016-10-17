#include<iostream>
#include<conio.h>
#include<string>
#include<cstdlib>
#define NO_OF_CHARS 256
using namespace std;
class node
{
    public:
    string c;
    int freq;
    node *left;
    node *right;
    node()
    {
        freq=0;
        left=NULL;
        right=NULL;
    }
    node(node &A)
    {
        c=A.c;
        freq=A.freq;
    }
}*root,A[NO_OF_CHARS],B[NO_OF_CHARS];
int k=0;
void initiate(node A[])
{
    for(int i=0; i<NO_OF_CHARS; i++)
            A[i].c=(char)i;
}
void arraycount(char *str)
{
    for(int i=0;*(str+i);i++)
            ++A[*(str+i)].freq;
}
void display(node X[])
{
    cout<<"Character\tFreq\n";
    int i;
    for(i=0;i<NO_OF_CHARS;i++)
    {
        if(X[i].freq!=0)
            cout<<"I"<<i<<" "<<X[i].c<<"\t\t"<<X[i].freq<<"\n";
    }
}
int part(node A[],int beg,int end)
{
    int p=beg;
    node pivot=A[beg];
    for(int loc=beg+1;loc<end;loc++)
    {
        if(pivot.freq>A[loc].freq)
        {
            A[p]=A[loc];
            A[loc]=A[p+1];
            A[p+1]=pivot;
            p++;
        }
    }
    return p;
}
void quicksort(node A[],int beg,int end)
{
        if(beg<end)
        {
            int p=part(A,beg,end);
            quicksort(A,beg,p-1);
            quicksort(A,p+1,end);
        }
}
node operator+(node X,node Y)
{
    node temp;
    temp.c=X.c+Y.c;
    temp.freq=X.freq+Y.freq;
    return temp;
}
void copyA()
{
    for(int i=0;i<NO_OF_CHARS;i++)
    {
        if(A[i].freq>0)
        {
            B[k]=A[i];
            k++;
            cout<<"i="<<i<<"k="<<k<<"B[k]"<<B[k].c<<" "<<B[k].freq<<endl;
            //cout<<B[k].c<<" "<<B[k].freq;
        }
    }
}
void pairB()
{
    int b;
    for(int a=0;B[a+1].freq!=0;a+=2)
    {
        b=a+1;
        B[k+a]=B[a]+B[b];
    }
}
main()
{
    system("cls");
    char str[]="A quick brown fox jumps over the lazy dog.";
    initiate(A);
    arraycount(str);
    display(A);
    copyA();
    quicksort(B,0,NO_OF_CHARS);
    cout<<"After Quicksort"<<endl;
    pairB();
    cout<<"After pair"<<endl;
    getch();
}
