#include <string>
#include <iostream>
#include <fstream>
#ifndef HUFFMAN
#define HUFFMAN
#include <iomanip>
#include<stdlib.h>
using namespace std;
class Huffman
{
private:
/*** Node structure ***/
class BinNode
{
public:
char data;
BinNode * left,* right;
// BinNode constructor
BinNode(char item)
{
data = item;
left = right = 0;
}
};
typedef BinNode * BinNodePointer;
public:
/*** Function members ***/
Huffman();
/*---------------------------------------------------------------------------------
Constructor
Precondition: None.
Postcondition: A one-node binary tree with root node pointed to by myRoot
has been created.
---------------------------------------------------------------------------------*/
void buildDecodingTree(ifstream & codeIn);
/*---------------------------------------------------------------------------------
Build the Huffman decoding tree.
Precondition: ifstream codeIn is open and is connected to a file that contains
characters and their codes.
Postcondition: A oneHuffman decoding tree has been created with root node
pointed to by myRoot.
---------------------------------------------------------------------------------*/
void insert(char ch, string code);
/*---------------------------------------------------------------------------------
Insert a node for a character in Huffman decoding tree.
Precondition: code is the bit string that is the code for ch.
Postcondition: A node containing ch has been inserted into the Huffman tree
with root pointed to by myRoot.
---------------------------------------------------------------------------------*/
void decode(ifstream & messageIn);
/*---------------------------------------------------------------------------------
Build the Huffman decoding tree.
Precondition: ifstream messageIn is open and is connected to a file that
contains the message to be decoded.
Postcondition: The decoded message has been output to cout.
---------------------------------------------------------------------------------*/
void printTree(ostream & out, BinNodePointer root, int indent);
/*---------------------------------------------------------------------------------
Recursive function to display a binary tree with root pointed to by root.
Precondition: ostream out is open; root points to a binary tree; indent >= 0
is the amount to indent each level..
Postcondition: Graphical representation of the binary tree has been output
to out.
---------------------------------------------------------------------------------*/
void displayDecodingTree(ostream & out);
/*---------------------------------------------------------------------------------
Display the decoding tree.
Precondition: ostream out is open.
Postcondition: The decoding tree has been output to out (via printTree().)
---------------------------------------------------------------------------------*/
/*** Data members ***/
private:
BinNodePointer myRoot;
};
//--- Definition of constructor
inline Huffman::Huffman()
{
myRoot = new BinNode('*');
}
//--- Definition of displayDecodingTree()
inline void Huffman::displayDecodingTree(ostream & out)
{
printTree(out, myRoot, 0);
}
#endif
//--- Definition of buildDecodingTree()
void Huffman::buildDecodingTree(ifstream & codeIn)
{
char ch; // a character
string code; // its code
for (;;)
{
codeIn >> ch >> code;
cout<<"ch="<<ch<<"code="<<code;
if ( codeIn.eof() ) return;
insert(ch, code);
}
}
//--- Definition of insert()
void Huffman::insert(char ch, string code)
{
Huffman::BinNodePointer p = myRoot; // pointer to move down the tree
for(int i = 0; i < code.length(); i++)
{
switch (code[i])
{
case '0' : // descend left
if (p->left == 0) // create node along path
p->left = new Huffman::BinNode('*');
p = p->left;
break;
case '1' : // descend right
if (p->right == 0) // create node along path
p->right = new Huffman::BinNode('*');
p = p->right;
break;
default:
cerr << "*** Illegal character in code ***\n";
exit(1);
}
}
p->data = ch;
}
//--- Definition of decode()
void Huffman::decode(ifstream & messageIn)
{
char bit; // next message bit
Huffman::BinNodePointer p; // pointer to trace path in decoding tree
for(;;)
{
p = myRoot;
while (p->left != 0 || p->right != 0)
{
messageIn >> bit;
if ( messageIn.eof() ) return;
cout << bit;
if (bit == '0')
p = p->left;
else if (bit == '1')
p = p->right;
else
cerr << "Illegal bit: " << bit << " -- ignored\n";
}
cout << "--" << p->data << endl;
}
}
//--- Definition of printTree()
void Huffman::printTree(ostream & out, Huffman::BinNodePointer root,int indent)
{
if (root != 0)
{
printTree(out, root->right, indent + 8);
out << setw(indent) << " " << root->data << endl;
printTree(out, root->left, indent + 8);
}
}
void display()
{
    cout<<"THE RED COATS ARE COMING.\n";
}
