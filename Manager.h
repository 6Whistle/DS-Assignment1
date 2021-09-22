#pragma once
#include "AccountBST.h"
#include "AccountQueue.h"
#include "UserHeap.h"
#include "UserList.h"


class Manager
{
private:
	AccountQueue* ds_queue;
	AccountBST* ds_bst;
	UserHeap* ds_heap;
	UserList* ds_list;
	ifstream fin;
	ofstream flog;

public:
	Manager();
	~Manager();

	void run(const char* command);
	bool QLOAD();
	bool ADD();
	bool QPOP();
	bool SEARCH();
	bool PRINT();
	bool DELETE();
	bool HLOAD();
	bool EXIT();

	void PrintErrorCode(int num);
	void PrintSuccess(char* act);
};
