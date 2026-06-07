#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class Node
{
public:
	Node* left;
	Node* right;
	Node* up;
	Node* down;
	string name;
	bool isroad;

	Node();
	Node(string nam, bool is);

};

Node::Node(){}
Node::Node(string nam, bool is) : left(nullptr), right(nullptr), up(nullptr), down(nullptr), name(nam), isroad(is) {}

