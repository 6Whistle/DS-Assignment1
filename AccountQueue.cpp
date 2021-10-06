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
    AccountQueueNode* prev = NULL;

    while(temp)
    {
        if(strcmp(temp->GetName(), node->GetName()) == 0 && temp->GetAge() == node->GetAge() && strcmp(temp->GetId(), node->GetId()) == 0)
        {
            delete node;
            return false;
        }
        prev = temp;
        temp = temp->GetNext();
    }
    prev->SetNext(node);
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
    
    ofstream flog;
    flog.open("log.txt", ios::app);

    flog << "========== QLOAD ==========" << endl;

    if(!(this->EMPTY()))
    {
        AccountQueueNode *temp = Front;
        while(temp)
        {
            flog << temp->GetName() << '/' << temp->GetAge() << '/' << temp->GetId() << endl;
            temp = temp->GetNext();
        }
    }

    flog << "===========================" << endl << endl;
    flog.close();

    return;
}

void AccountQueue::PRINTPUSH()
{
    ofstream flog;
    flog.open("log.txt", ios::app);

    flog << "========== ADD ==========" << endl;

    AccountQueueNode *temp = Front;
    while(temp->GetNext())
    {
        temp = temp->GetNext();
    }
    
    flog << temp->GetName() << '/' << temp->GetAge() << '/' << temp->GetId() << endl;
    temp = temp->GetNext();
    flog << "===========================" << endl << endl;
    flog.close();

    return;
}