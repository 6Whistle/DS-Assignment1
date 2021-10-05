#include "UserHeap.h"

UserHeap::UserHeap()
{
    Heap.push_back(NULL);
}

UserHeap::~UserHeap()
{
    UserHeapNode* temp;
    for(int i = 0; i < Heap.size(); i++)
    {
        temp = Heap[i];

        if(temp)
        {
            delete temp;
        }
    }
}

int UserHeap::GetSize()
{
    return Heap.size();
}

bool UserHeap::Insert(int agegroup)
{
    int i = 0;
    while(i < Heap.size() && Heap[i]->GetAgeGroup() != agegroup)
    {
        i++;
    }

    if(i == Heap.size())
    {
        UserHeapNode* temp = new UserHeapNode;
        temp->SetAgeGroup(agegroup);
        temp->SetNumUser(1);

        Heap.push_back(temp);

        while(i != 1 && Heap[i]->GetAgeGroup() > Heap[i/2]->GetAgeGroup())
        {
            int tempGroup = Heap[i]->GetAgeGroup(), tempNum = Heap[i]->GetNumUser();
            Heap[i]->SetAgeGroup(Heap[i/2]->GetAgeGroup());
            Heap[i]->SetNumUser(Heap[i/2]->GetNumUser());

            Heap[i/2]->SetAgeGroup(tempGroup);
            Heap[i/2]->SetNumUser(tempNum);
            i /= 2;
        }

        return true;
    }

    Heap[i]->SetNumUser(Heap[i]->GetNumUser() + 1);
    return true;
}

void UserHeap::Print()
{
    ofstream flog;
    flog.open("log.txt", ios::app);

    for(int i = 1; i < Heap.size(); i++)
    {
        flog << Heap[i]->GetNumUser() << "/" << Heap[i]->GetAgeGroup() << endl;
    }
    flog.close();

    return;
}