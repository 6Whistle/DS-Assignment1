#include "UserListNode.h"

UserListNode::UserListNode()
{
    this->Name = new char[32];
    Age = 0;
    AccNum = 1;
    pNext = NULL;
    pHead = NULL;
}

UserListNode::~UserListNode()
{
    delete[] Name;
}

char* UserListNode::GetName()       //get name
{
    return Name;
}

int UserListNode::GetAge()      //get age
{
    return Age;
}

UserListNode* UserListNode::GetNext()       //get pNext
{
    return pNext;
}

AccountBSTNode* UserListNode::GetHead()     //get pHead
{
    return pHead;
}

void UserListNode::SetName(char* name)      //set name
{
    strcpy(this->Name, name);

    return;
}

void UserListNode::SetAge(int age)      //set age
{
    this->Age = age;

    return;
}

void UserListNode::SetNext(UserListNode* node)      //set pNext
{
    pNext = node;
    
    return;
}

AccountBSTNode* UserListNode::InsertAccount(AccountBSTNode* node)       //insert at name list
{
    if(pHead == NULL)       //if phead is NULL, insert data
    {
        pHead = node;
        return node;
    }

    AccountBSTNode* temp = pHead;
    while(temp->GetNext())      //insert data at the last of temp
    {
        temp = temp->GetNext();
    }

    temp->SetNext(node);
    AccNum++;           //AccNum count

    return node;
}

void UserListNode::Print_Accounts()         //print is works another function
{

}

void UserListNode::Delete_Account(char* id)     //Delete account(using id)
{
    if(strcmp(pHead->GetId(), id) == 0)     //when delete pHead
    {
        pHead = pHead->GetNext();
        AccNum--;
        
        return;
    }

    AccountBSTNode* temp = pHead;
    while(temp->GetNext() && strcmp(temp->GetNext()->GetId(), id) != 0)     //move until id is same
    {
        temp = temp->GetNext();
    }

    temp->SetNext(temp->GetNext()->GetNext());      //delete and AccNum --
    AccNum--;

    return;
}
