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
	bool ADD(char* input);
	bool QPOP(char* input);
	bool SEARCH(char* input);
	bool PRINT(char* input);
	bool DELETE(char* input);
	bool HLOAD();
	bool EXIT();

	void PrintErrorCode(int num);
	void PrintSuccess(char* act);
};
