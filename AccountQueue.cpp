#include "AccountQueue.h"

AccountQueue::AccountQueue()
{
    queue_size = 0;
    Front = NULL;
}

AccountQueue::~AccountQueue()       //delete all data
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

AccountQueueNode* AccountQueue::POP()       //remove front data
{
    if(this->EMPTY())       //if queue is empty, return false
    {
        return NULL;
    }
    else                    //move front to front->next and return it
    {
        AccountQueueNode *temp = Front;
        Front = Front->GetNext();
        queue_size--;
        return temp;
    }
}

bool AccountQueue::PUSH(AccountQueueNode* node)     //input data at queue
{
    if(this->EMPTY())       //if queue is empty, Front = node
    {
        Front = node;
        queue_size++;
        return true;
    }

    AccountQueueNode* temp = Front;
    AccountQueueNode* prev = NULL;

    while(temp)
    {
        if(strcmp(temp->GetName(), node->GetName()) == 0 && temp->GetAge() == node->GetAge() && strcmp(temp->GetId(), node->GetId()) == 0)      //if name, id, age is same, return false
        {
            delete node;
            return false;
        }
        prev = temp;
        temp = temp->GetNext();             //move end of queue
    }
    prev->SetNext(node);                //input queue
    queue_size++;
    return true;
}

bool AccountQueue::EMPTY()      //return if queue is empty
{
    return queue_size == 0 ? true : false;
}

int AccountQueue::SIZE()        //return size
{
    return queue_size;
}

void AccountQueue::PRINT()      //Print Queue
{
    ofstream flog;
    flog.open("log.txt", ios::app);

    flog << "========== QLOAD ==========" << endl;

    if(!(this->EMPTY()))        //while queue is not empty, print data
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

void AccountQueue::PRINTPUSH()      //print pushed data
{
    ofstream flog;
    flog.open("log.txt", ios::app);

    flog << "========== ADD ==========" << endl;

    AccountQueueNode *temp = Front;
    while(temp->GetNext())          //goto end
    {
        temp = temp->GetNext();
    }
    flog << temp->GetName() << '/' << temp->GetAge() << '/' << temp->GetId() << endl;       //print last pushed data
    temp = temp->GetNext();
    flog << "===========================" << endl << endl;
    flog.close();

    return;
}