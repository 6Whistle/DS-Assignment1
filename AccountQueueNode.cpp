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

char* AccountQueueNode::GetName()       //get User_Name
{
    return User_Name;
}

int AccountQueueNode::GetAge()          //get User_age
{
    return User_age;
}

char* AccountQueueNode::GetId()         //get User_Id
{
    return User_Id;
}
AccountQueueNode* AccountQueueNode::GetNext()       //get pNext
{
    return pNext;
}
void AccountQueueNode::SetName(char* name)          //set User_Name
{
    strcpy(User_Name, name);

    return;
}

void AccountQueueNode::SetAge(int age)          //set User_age
{
    User_age = age;

    return;
}

void AccountQueueNode::SetId(char* id)          //set User_Id
{
    strcpy(User_Id, id);

    return;
}

void AccountQueueNode::SetNext(AccountQueueNode* node)
{
    pNext = node;

    return;
}