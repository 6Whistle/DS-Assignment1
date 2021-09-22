#include "AccountQueue.h"

AccountQueue::AccountQueue()
{
    queue_size = 0;
    Front = NULL;
}

AccountQueue::~AccountQueue()
{
    if(Front)
    {
        AccountQueueNode *temp;
        while(Front)
        {
            temp = Front->GetNext();
            delete Front;
            Front = temp;
        }
    }
}

AccountQueueNode* AccountQueue::POP()
{
    if(this->EMPTY())
    {
        return NULL;
    }
    else
    {
        AccountQueueNode *temp = Front;
        Front = Front->GetNext();
        queue_size--;
        return temp;
    }
}
bool AccountQueue::PUSH(AccountQueueNode* node)
{
    if(this->EMPTY())
    {
        Front = node;
        queue_size++;
        return true;
    }

    AccountQueueNode* temp = Front;

    while(temp->GetNext())
    {
        temp = temp->GetNext();
    }
    temp->SetNext(node);
    queue_size++;
    return true;
}

bool AccountQueue::EMPTY()
{
    return queue_size == 0 ? true : false;
}

int AccountQueue::SIZE()
{
    return queue_size;
}

void AccountQueue::PRINT()
{
    if(this->EMPTY())
        return;
    
    AccountQueueNode *temp = Front;
    while(temp)
    {
        cout << temp->GetName() << '/' << temp->GetAge() << '/' << temp->GetId() << endl;
        temp = temp->GetNext();
    }
}