#pragma once
#include "AccountQueueNode.h"
#include <iostream>
#include <fstream>
using namespace std;

class AccountQueue
{
private:
	int queue_size;
	AccountQueueNode* Front;

public:
	AccountQueue();
	~AccountQueue();

	bool PUSH(AccountQueueNode* node);
	AccountQueueNode* POP();
	bool EMPTY();
	int SIZE();
	void PRINT();
};
