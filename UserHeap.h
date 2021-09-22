#pragma once
#include "UserHeapNode.h"
#include <fstream>
#include <vector>
using namespace std;

class UserHeap
{
private:
	UserHeapNode* Heap;
	int size;

public:
	UserHeap();
	~UserHeap();

	bool Insert(int agegroup);
	void Print();
};
