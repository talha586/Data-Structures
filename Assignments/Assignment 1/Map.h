#pragma once
#include "node.h"

class Map
{
private:
	Node* head;
	int rows;
	int cols;

public:

	Map(int row,int col);
	void print();
	void ConstructRoad(string PointA,string PointB,int length,string direction);
	void ConstructRoad(int row,int col, string PointA, string PointB, int length, string direction);
	void PrintPath(string PointA,string PointB);
	void removePath(string PointA, string PointB);
	~Map();
};

Map::Map(int row, int col)
{
	rows = row;
	cols = col;

	head = nullptr;

	Node*** matrix = new Node **[rows];// for matrix constructions

	if (rows==0 || cols==0)
	{
		cout << "No valid input" << endl;
		return;
	}

	for (int i=0;i<rows;i++)
	{
		matrix[i] = new Node*[cols];
		for (int j=0;j<cols;j++)
		{
			matrix[i][j] = new Node();
			matrix[i][j]->name = "";
			matrix[i][j]->isroad = false;
		}
	}

	for (int i=0;i<rows;i++)//for connecting the rows and olumns
	{
		for (int j=0;j<cols;j++)
		{
			if (j>0)
			{
				matrix[i][j]->left = matrix[i][j-1];
			}
			if (j<cols-1)
			{
				matrix[i][j]->right = matrix[i][j+1];
			}
			if (i>0)
			{
				matrix[i][j]->up = matrix[i-1][j];
			}
			if (i<rows-1)
			{
				matrix[i][j]->down = matrix[i+1][j];
			}
		}
	}
	head = matrix[0][0];

}

void Map:: ConstructRoad(string PointA, string PointB, int length, string direction)
{
	Node* temp1 = head;
	Node* temp2 = head;
	bool flag=false;

	for (int i=0;i<rows;i++)
	{
		for (int j=0;j<cols;j++)
		{
			if (temp1->name==PointA)//for naming the pointA
			{
				flag = true;
				break;
			}
			temp1 = temp1->right;
		}
		if (flag==true)
		{
			break;
		}
		temp1 = temp1->down;
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (temp2->name == PointB)//for naming the pointB
			{
				flag = true;
				break;
			}
			temp2 = temp2->right;
		}
		if (flag == true)
		{
			break;
		}
		temp2 = temp2->down;
	}

	int counter = length;

	//for moving the node in order to set values

	while (counter >= 1 && direction == "right")
	{
		temp1->isroad = true;
		temp1 = temp1->right;
		counter--;
	}

	while (counter >= 1 && direction == "left")
	{
		temp1->isroad = true;
		temp1 = temp1->left;
		counter--;
	}

	while (counter >= 1 && direction == "down")
	{
		temp1->isroad = true;
		temp1 = temp1->down;
		counter--;
	}

	while (counter >= 1 && direction == "up")
	{
		temp1->isroad = true;
		temp1 = temp1->up;
		counter--;
	}
	return;
}

void Map::ConstructRoad(int row,int col, string PointA, string PointB, int length, string direction)
{
	Node* temp = head;

	if (row>rows || col> cols || row==0 || col==0 || row<0 || col<0)
	{
		cout << "Out Of Bound" << endl;
		return;
	}

	for (int i=0;i<row-1;i++)
	{
		temp = temp->down;
	}

	for (int j=0;j<col-1;j++)
	{
		temp = temp->right;
	}

	int counter = length;

	while (counter>=1 && direction== "right")
	{
		if (counter==length)
		{
			temp->isroad = true;
			temp->name = PointA;
			temp = temp->right;

		}
		else if (counter==1)
		{
			temp->isroad = true;
			temp->name = PointB;
			temp = temp->right;
		}
		else
		{
			temp->isroad = true;
			temp = temp->right;
		}
		counter--;
	}

	while (counter >= 1 && direction == "left")
	{
		if (counter == length)
		{
			temp->isroad = true;
			temp->name = PointA;
			temp = temp->left;

		}
		else if (counter == 1)
		{
			temp->isroad = true;
			temp->name = PointB;
			temp = temp->left;
		}
		else
		{
			temp->isroad = true;
			temp = temp->left;
		}
		counter--;
	}

	while (counter >= 1 && direction == "down")
	{
		if (counter == length)
		{
			temp->isroad = true;
			temp->name = PointA;
			temp = temp->down;
		}
		else if (counter == 1)
		{
			temp->isroad = true;
			temp->name = PointB;
			temp = temp->down;
		}
		else
		{
			temp->isroad = true;
			temp = temp->down;
		}
		counter--;
	}

	while (counter >= 1 && direction == "up")
	{
		if (counter == length)
		{
			temp->isroad = true;
			temp->name = PointA;
			temp = temp->up;

		}
		else if (counter == 1)
		{
			temp->isroad = true;
			temp->name = PointB;
			temp = temp->up;
		}
		else
		{
			temp->isroad = true;
			temp = temp->up;
		}
		counter--;
	}

	return;
}

void Map::print()
{
	Node* row = head;
	for (int i=0;i<rows;i++)
	{
		Node* col = row;

		for (int j=0;j<cols;j++)
		{
			if (col->isroad == true)
			{
				cout << "*"<<" ";
			}
			else
			{
				cout << " " << " ";
			}
			col = col->right;
		}
		cout << endl;
		row = row->down;
	}
	return;
}

void Map::PrintPath(string PointA, string PointB)
{
	Node* temp = head;
	Node* random = head;
	bool flag = false;
	int x1=0, y1=0;

	for (int i=0;i<rows;i++)
	{
		temp = random;
		for (int j=0;j<cols;j++)
		{
			if (temp->name==PointA)
			{
				x1 = i;
				y1 = j;
				flag = true;
				break;
			}
			temp = temp->right;
		}
		if (flag==true)
		{
			break;
		}
		random = random->down;
	}

	flag = false;
	Node* temp2 = head;
	Node* random2 = head;
	int x2 = 0, y2 = 0;

	for (int i = 0; i < rows; i++)
	{
		temp2 = random2;
		for (int j = 0; j < cols; j++)
		{
			if (temp2->name == PointB)
			{
				x2 = i;
				y2 = j;
				flag = true;
				break;
			}
			temp2 = temp2->right;
		}
		if (flag == true)
		{
			break;
		}
		random2 = random2->down;
	}

	if (x1==x2 || y1==y2)
	{
		cout << "The Path can Be Printed" << endl;
	}
	else
	{
		cout << "Path can not be printed" << endl;
		return;
	}

	int start = 0;
	int end = 0;

	if (x1==x2)
	{
		start = min(y1,y2);
		end = max(y1,y2);
		if (y1<y2)
		{
			for (int i = start; i <= end; i++)
			{
				if (temp->isroad == true)
				{
					cout << "*" << " ";
				}
				temp = temp->right;
			}
			return;
		}
		else
		{
			for (int i = end; i >= start; i--)
			{
				if (temp->isroad == true)
				{
					cout << "*" << " ";
				}
				temp = temp->left;
			}
			return;
		}
	}

	else if (y1==y2)
	{
		start = min(x1, x2);
		end = max(x1, x2);
		if (x1 < x2)
		{
			for (int i = start; i <= end; i++)
			{
				if (temp->isroad == true)
				{
					cout << "*" << " ";
				}
				temp = temp->down;
			}
			return;
		}
		else
		{
			for (int i = end; i >= start; i--)
			{
				if (temp->isroad == true)
				{
					cout << "*" << " ";
				}
				temp = temp->up;
			}
			return;
		}
	}
}

void Map::removePath(string PointA,string PointB)
{
	Node* temp = head;
	Node* random = head;
	bool flag = false;
	int x1 = 0, y1 = 0;

	for (int i = 0; i < rows; i++)
	{
		temp = random;
		for (int j = 0; j < cols; j++)
		{
			if (temp->name == PointA)
			{
				x1 = i;
				y1 = j;
				flag = true;
				break;
			}
			temp = temp->right;
		}
		if (flag == true)
		{
			break;
		}
		random = random->down;
	}

	flag = false;
	Node* temp2 = head;
	Node* random2 = head;
	int x2 = 0, y2 = 0;

	for (int i = 0; i < rows; i++)
	{
		temp2 = random2;
		for (int j = 0; j < cols; j++)
		{
			if (temp2->name == PointB)
			{
				x2 = i;
				y2 = j;
				flag = true;
				break;
			}
			temp2 = temp2->right;
		}
		if (flag == true)
		{
			break;
		}
		random2 = random2->down;
	}

	if (x1 == x2 || y1 == y2)
	{
		cout << "The Path can Be Removed" << endl;
	}
	else
	{
		cout << "Path can not be Removed" << endl;
		return;
	}

	int start = 0;
	int end = 0;

	if (x1 == x2)
	{
		start = min(y1, y2);
		end = max(y1, y2);
		if (y1 < y2)
		{
			for (int i = start; i <= end; i++)
			{
				if (temp->isroad == true)
				{
					temp->isroad = false;
				}
				temp = temp->right;
			}
			return;
		}
		else
		{
			for (int i = end; i >= start; i--)
			{
				if (temp->isroad == true)
				{
					temp->isroad = false;
				}
				temp = temp->left;
			}
			return;
		}
	}

	else if (y1 == y2)
	{
		start = min(x1, x2);
		end = max(x1, x2);
		if (x1 < x2)
		{
			for (int i = start; i <= end; i++)
			{
				if (temp->isroad == true)
				{
					temp->isroad = false;
				}
				temp = temp->down;
			}
			return;
		}
		else
		{
			for (int i = end; i >= start; i--)
			{
				if (temp->isroad == true)
				{
					temp->isroad = false;
				}
				temp = temp->up;
			}
			return;
		}
	}
}

Map::~Map()
{
	Node* row = head;
	for (int i = 0; i <rows; i++) 
	{
		Node* col = row;
		for (int j = 0; j <cols; j++) 
		{
			Node* next = col->right;
			delete col;
			col = next;
		}
		row = row->down;
	}
}