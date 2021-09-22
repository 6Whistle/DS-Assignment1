#include "AccountQueueNode.h"

AccountQueueNode::AccountQueueNode()
{
    User_Name = NULL;
    User_age = -1;
    User_Id = NULL;
    pNext = NULL;
}

AccountQueueNode::~AccountQueueNode()
{
    delete User_Name;
    delete User_Id;
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
    int size = strlen(name);
    User_Name = new char[size];
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
    int size = strlen(id);
    User_Id = new char[size];
    strcpy(User_Id, id);

    return;
}

void AccountQueueNode::SetNext(AccountQueueNode* node)
{
    pNext = node;

    return;
}