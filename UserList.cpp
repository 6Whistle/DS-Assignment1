#include "UserList.h"

UserList::UserList()
{
    Root = NULL;
}

UserList::~UserList()
{
    while(Root)
    {
        UserListNode* temp = Root->GetNext();
        delete Root;
        Root = temp;
    }
}

UserListNode* UserList::GetRoot()
{
    return Root;
}

AccountBSTNode* UserList::Insert(AccountQueueNode* node)
{
    AccountBSTNode* insertNode = new AccountBSTNode;
    insertNode->SetId(node->GetId());
    insertNode->SetName(node->GetName());

    UserListNode* temp = Root;
    //to do here
    while(temp->GetNext() && strcmp(temp->GetNext()->GetName(), insertNode->GetName()) != 0)

}

bool UserList::Search(char* name)
{

}

bool UserList::Delete_Account(char* name, char* id)
{
   
}

void UserList::Print_L(UserListNode* node)
{
    
}