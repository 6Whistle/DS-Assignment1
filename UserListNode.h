#pragma once
#include <cstring>
#include "AccountBSTNode.h"

class UserListNode
{
private:
	char* Name;
	int Age;
	int AccNum;
	UserListNode* pNext;
	AccountBSTNode* pHead;

public:
	UserListNode();
	~UserListNode();

	char* GetName();
	int GetAge();
	int GetAccNum() {return AccNum;}
	UserListNode* GetNext();
	
	void SetName(char* name);
	void SetAge(int age);
	void SetNext(UserListNode* node);

	AccountBSTNode* InsertAccount(AccountBSTNode* node);
	void Print_Accounts();
	void Delete_Account(char* id);
};
