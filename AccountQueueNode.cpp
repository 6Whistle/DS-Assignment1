#include "AccountQueueNode.h"

AccountQueueNode::AccountQueueNode()
{
    this->User_Name = new char[32];
    User_age = -1;
    this->User_Id = new char[32];
    pNext = NULL;
}

AccountQueueNode::~AccountQueueNode()
{
    delete[] User_Name;
    delete[] User_Id;
}

char* AccountQueueNode::GetName()
{
    return User_Name;
}

int AccountQueueNode::GetAge()
{
    return User_age;
}

char* AccountQueueNode::GetId()
{
    return User_Id;
}
AccountQueueNode* AccountQueueNode::GetNext()
{
    return pNext;
}
void AccountQueueNode::SetName(char* name)
{
    strcpy(User_Name, name);

    return;
}

void AccountQueueNode::SetAge(int age)
{
    User_age = age;

    return;
}

void AccountQueueNode::SetId(char* id)
{
    strcpy(User_Id, id);

    return;
}

void AccountQueueNode::SetNext(AccountQueueNode* node)
{
    pNext = node;

    return;
}