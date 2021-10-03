#include "AccountBSTNode.h"

AccountBSTNode::AccountBSTNode()
{
    this->Name = NULL;
    this->Id = NULL;

    this->pLeft = NULL;
    this->pRight = NULL;
    this->pNext = NULL;
}

AccountBSTNode::~AccountBSTNode()
{
    if(this->Name)
    {
        delete[] this->Name;
    }

    if(this->Id)
    {
        delete[] this->Name;
    }
}

char* AccountBSTNode::GetName()
{
    return this->Name;
}

char* AccountBSTNode::GetId()
{
    return this->Id;
}

AccountBSTNode* AccountBSTNode::GetLeft()
{
    return this->pLeft;
}

AccountBSTNode* AccountBSTNode::GetRight()
{
    return this->pRight;
}

AccountBSTNode* AccountBSTNode::GetNext()
{
    return this->pNext;
}

void AccountBSTNode::SetName(char* name)
{
    int size = strlen(name);

    if(this->Name)
    {
        delete[] this->Name;
    }

    this->Name = new char[size];
    strcpy(this->Name, name);
    return;
}

void AccountBSTNode::SetId(char* disease)
{
    int size = strlen(disease);

    if(this->Id)
    {
        delete[] this->Id;
    }

    this->Id = new char[size];
    strcpy(this->Id, disease);
    return;
}

void AccountBSTNode::SetLeft(AccountBSTNode* node)
{
    this->pLeft = node;
    return;
}

void AccountBSTNode::SetRight(AccountBSTNode* node)
{
    this->pRight = node;
    return;
}
void AccountBSTNode::SetNext(AccountBSTNode* node)
{
    this->pNext = node;
    return;
}