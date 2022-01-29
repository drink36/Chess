#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Position
{
	int x = 0;
	int y = 0;
	bool operator==(Position pos) { return true ? (x == pos.x && y == pos.y) : false; }
	friend istream& operator>>(istream& istr, Position& pos)
	{
		string temp;
		istr >> temp;

		pos.x = temp[0] - 'a';
		pos.y = temp[1] - '1';
		return istr;
	}

}; 
