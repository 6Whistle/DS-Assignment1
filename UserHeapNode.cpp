#include "UserHeapNode.h"
UserHeapNode::UserHeapNode()
{
    NumUser = 0;
    AgeGroup = 0;
}

UserHeapNode::~UserHeapNode()
{

}

int UserHeapNode::GetNumUser()
{
    return NumUser;
}

int UserHeapNode::GetAgeGroup()
{
    return AgeGroup;
}

void UserHeapNode::SetNumUser(int number)
{
    NumUser = number;
    return;
}

void UserHeapNode::SetAgeGroup(int agegroup)
{
    AgeGroup = agegroup;
    return;
}
