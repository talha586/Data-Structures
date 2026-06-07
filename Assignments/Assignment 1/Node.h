#pragma once
#include<iostream>
using namespace std;
template<typename T>
class Node
{
public:
	T data;
	Node<T>* next;

	Node();
	Node(T val);

};

template<typename T>
Node<T>::Node(): next(nullptr)
{}

template<typename T>
Node<T>::Node(T val) : next(nullptr), data(val) {}
