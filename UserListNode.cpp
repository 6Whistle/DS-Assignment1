#include "UserListNode.h"

UserListNode::UserListNode()
{
    Name = NULL;
    Age = 0;
    AccNum = 0;
    pNext = NULL;
    pHead = NULL;
}

UserListNode::~UserListNode()
{
    delete[] Name;
}

char* UserListNode::GetName()
{
    return Name;
}

int UserListNode::GetAge()
{
    return Age;
}

UserListNode* UserListNode::GetNext()
{
    return pNext;
}

AccountBSTNode* UserListNode::GetHead()
{
    return pHead;
}

void UserListNode::SetName(char* name)
{
    if(this->Name)
    {
        delete[] this->Name;
    }

    int size = strlen(name);
    this->Name = new char[size];
    strcpy(this->Name, name);

    return;
}

void UserListNode::SetAge(int age)
{
    this->Age = age;

    return;
}

void UserListNode::SetNext(UserListNode* node)
{
    pNext = node;
    
    return;
}

AccountBSTNode* UserListNode::InsertAccount(AccountBSTNode* node)
{
    if(pHead == NULL)
    {
        pHead = node;
        return node;
    }

    AccountBSTNode* temp = pHead;
    while(temp->GetNext())
    {
        temp = temp->GetNext();
    }

    temp->SetNext(node);
    AccNum++;

    return node;
}

void UserListNode::Print_Accounts()
{

}

void UserListNode::Delete_Account(char* id)
{
    if(strcmp(pHead->GetId(), id) == 0)
    {
        pHead = pHead->GetNext();
        AccNum--;
        
        return;
    }

    AccountBSTNode* temp = pHead;
    while(temp->GetNext() && strcmp(temp->GetNext()->GetId(), id) != 0)
    {
        temp = temp->GetNext();
    }

    temp->SetNext(temp->GetNext()->GetNext());
    AccNum--;

    return;
}
