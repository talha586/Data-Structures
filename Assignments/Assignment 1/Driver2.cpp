#include "node.h"
#include "Map.h"

int main()
{
	Map m1(4,4);
	m1.ConstructRoad(1,1,"A","Z",1,"right");
	//m1.ConstructRoad(1, 2, "A", "Z", 1, "right");
	//m1.ConstructRoad(1, 3, "A", "Z", 1, "right");
	//m1.ConstructRoad(2, 1, "A", "Z", 1, "right");
	//m1.ConstructRoad(2, 2, "A", "Z", 1, "right");
	//m1.ConstructRoad(2, 3, "A", "Z", 1, "right");
	//m1.ConstructRoad(3, 1, "A", "Z", 1, "right");
	//m1.ConstructRoad(3, 2, "A", "Z", 1, "right");
	//m1.ConstructRoad(3, 3, "A", "Z", 1, "right");
	//m1.ConstructRoad(4, 1, "A", "Z", 1, "right");
	//m1.ConstructRoad(4, 2, "A", "Z", 1, "right");
	//m1.ConstructRoad(4, 3, "A", "Z", 1, "right");
	m1.ConstructRoad(1, 4, "D", "E", 1, "right");
	m1.ConstructRoad(3,1, "B", "C", 2, "right");
	m1.ConstructRoad("A","E",3,"right");
	m1.print();
	cout << endl << endl;
	m1.PrintPath("A","D");
	cout << endl << endl;
	m1.PrintPath("C","Z");
	cout << endl << endl;
	m1.removePath("A", "D");
	m1.PrintPath("A","D");
	cout << endl << endl;
	m1.print();
	cout << endl << endl;
	m1.PrintPath("D", "A");
}