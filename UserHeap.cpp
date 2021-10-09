#include "UserHeap.h"

UserHeap::UserHeap()
{
    Heap.push_back(NULL);          //Heap[0] = NULL
}

UserHeap::~UserHeap()           //delete all of data
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

int UserHeap::GetSize()         //get size
{
    return Heap.size();
}

bool UserHeap::Insert(int agegroup)     //insert agegroup at heap
{
    int i = 1;
    while(i < Heap.size() && Heap[i]->GetAgeGroup() != agegroup)        //move while meet agegroup is same or last heap
    {
        i++;
    }

    if(i == Heap.size())        //if i point last heap
    {
        UserHeapNode* temp = new UserHeapNode;      //make data
        temp->SetAgeGroup(agegroup);
        temp->SetNumUser(1);

        Heap.push_back(temp);       //push data

        while(i != 1 && Heap[i]->GetAgeGroup() > Heap[i/2]->GetAgeGroup())      //compare with parent node. if child is bigger then parent, it changes
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

    Heap[i]->SetNumUser(Heap[i]->GetNumUser() + 1);             //if same agegroup is exeist, count num
    return true;
}

void UserHeap::Print()          //print heap
{
    ofstream flog;
    flog.open("log.txt", ios::app);     //open "log.txt"

    for(int i = 1; i < Heap.size(); i++)        //print all of data of heap
    {
        flog << Heap[i]->GetNumUser() << "/" << Heap[i]->GetAgeGroup() << endl;
    }
    flog.close();

    return;
}