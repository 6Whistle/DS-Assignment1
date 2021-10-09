#include "AccountBSTNode.h"

AccountBSTNode::AccountBSTNode()
{
    this->Name = new char[32];          //assign Name and Id
    this->Id = new char[32];

    this->pLeft = NULL;
    this->pRight = NULL;
    this->pNext = NULL;
}

AccountBSTNode::~AccountBSTNode()
{
    if(this->Name)                  //if Name and Id exist, delete them
    {
        delete[] this->Name;
    }

    if(this->Id)
    {
        delete[] this->Id;
    }
}

char* AccountBSTNode::GetName()     //get Name
{
    return this->Name;
}

char* AccountBSTNode::GetId()       //get Id
{
    return this->Id;
}

AccountBSTNode* AccountBSTNode::GetLeft()       //get pLeft
{
    return this->pLeft;
}

AccountBSTNode* AccountBSTNode::GetRight()      //get pRight
{
    return this->pRight;
}

AccountBSTNode* AccountBSTNode::GetNext()       //get pNext
{
    return this->pNext;
}

void AccountBSTNode::SetName(char* name)        //set Name
{
    strcpy(this->Name, name);
    return;
}

void AccountBSTNode::SetId(char* disease)       //SET Id
{
    strcpy(this->Id, disease);
    return;
}

void AccountBSTNode::SetLeft(AccountBSTNode* node)      //set pLeft
{
    this->pLeft = node;
    return;
}

void AccountBSTNode::SetRight(AccountBSTNode* node)     //set pRight
{
    this->pRight = node;
    return;
}
void AccountBSTNode::SetNext(AccountBSTNode* node)      //set pNext
{
    this->pNext = node;
    return;
}