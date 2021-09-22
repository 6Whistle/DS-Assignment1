#pragma once
#include <cstring>
class AccountBSTNode
{
private:
	char* Name;
	char* Id;

	AccountBSTNode* pLeft;
	AccountBSTNode* pRight;
	AccountBSTNode* pNext;
	
public:
	AccountBSTNode();
	~AccountBSTNode();

	char* GetName();
	char* GetId();
	AccountBSTNode* GetLeft();
	AccountBSTNode* GetRight();
	AccountBSTNode* GetNext();


	void SetName(char* name);
	void SetId(char* id);
	void SetNext(AccountBSTNode* node);
	void SetLeft(AccountBSTNode* node);
	void SetRight(AccountBSTNode* node);
};