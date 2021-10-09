#include "UserHeapNode.h"
UserHeapNode::UserHeapNode()
{
    NumUser = 0;
    AgeGroup = 0;
}

UserHeapNode::~UserHeapNode()
{

}

int UserHeapNode::GetNumUser()      //get NumUser
{
    return NumUser;
}

int UserHeapNode::GetAgeGroup()     //get AgeGroup
{
    return AgeGroup;
}

void UserHeapNode::SetNumUser(int number)       //set NumUser
{
    NumUser = number;
    return;
}

void UserHeapNode::SetAgeGroup(int agegroup)        //set AgeGroup
{
    AgeGroup = agegroup;
    return;
}
