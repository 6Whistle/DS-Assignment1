#pragma once
#include "AccountBSTNode.h"
#include "AccountQueueNode.h"
#include <fstream>
#include <queue>
using namespace std;

class AccountBST
{
private:
	AccountBSTNode* Root;

public:
	AccountBST();
	~AccountBST();

	AccountBSTNode* GetRoot();
	bool Insert(AccountBSTNode* node);
	bool Search_Id(char* id);
	bool Delete(char* id);
	void Print_PRE(AccountBSTNode* node);
	void Print_IN(AccountBSTNode* node);
	void Print_POST(AccountBSTNode* node);
	void Print_LEVEL();

	bool CompareName(char* cm1, char* cm2);
	void FindNameFromId(char* id, char* name);
};
