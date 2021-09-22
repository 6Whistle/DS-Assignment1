#pragma once
#include <cstring>
#include <queue>
using namespace std;

class UserHeapNode
{
private:
	int NumUser;
	int AgeGroup;

public:
	UserHeapNode();
	~UserHeapNode();

	int GetNumUser();
	char* GetAgeGroup();

	void SetNumUser(int number);
	void SetAgeGroup(int agegroup);
};
