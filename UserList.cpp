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
    
    if(Root == NULL)
    {
        UserListNode* insertList = new UserListNode;
        insertList->SetName(node->GetName());
        insertList->SetAge(node->GetAge());
        insertList->InsertAccount(insertNode);
        Root = insertList;

        return insertNode;
    }

    UserListNode* temp = Root;

    while(temp && strcmp(temp->GetName(), insertNode->GetName()) != 0)
    {
        if(temp->GetNext() == NULL)
        {
        UserListNode* insertList = new UserListNode;
        insertList->SetName(node->GetName());
        insertList->SetAge(node->GetAge());
        insertList->InsertAccount(insertNode);
        temp->SetNext(insertList);

        return insertNode;
        }

        temp = temp->GetNext();
    }

    temp->InsertAccount(insertNode);
    return insertNode;
}

bool UserList::Search(char* name)
{
    if(Root == NULL)
    {
        return false;
    }

    UserListNode* temp = Root;

    while(temp)
    {
        if(strcmp(temp->GetName(), name) == 0)
        {
            ofstream flog;
            flog.open("log.txt", ios::app);
            flog << "========== SEARCH ==========" << endl;
            flog << "User" << endl;
            flog << temp->GetName() << "/" << temp->GetAge() << endl;
            
            AccountBSTNode* idTemp = temp->GetHead();
            while(idTemp)
            {
                flog << idTemp->GetId();
                idTemp = idTemp->GetNext();
            }

            flog << "===========================" << endl << endl; 
            flog.close();
            return true;
        }
        temp = temp->GetNext();
    }

    return false;
}

bool UserList::Delete_Account(char* name, char* id)
{
    if(Root == NULL)
    {
       return false;
    }

    UserListNode *cur = Root, *prev = NULL;

    while(cur && strcmp(cur->GetName(), name) != 0)
    {
       prev = cur;
       cur = cur->GetNext();
    }

   if(cur == NULL)
    {
       return false;
    }

    AccountBSTNode* tempBST = cur->GetHead();
    bool state = false;

    while(tempBST)
    {
        if(strcmp(tempBST->GetId(), id) == 0)
        {
            state = true;
        }
        tempBST = tempBST->GetNext();
    }

    if(state == false)
    {
        return false;
    }
    
    cur->Delete_Account(id);

    if(cur->GetAccNum() == 0)
    {
        if(cur == Root)
        {
            Root = Root->GetNext();
        }
        else
        {
            prev->SetNext(cur->GetNext());
        }
        delete cur;
    }

    return true;
}

void UserList::Print_L(UserListNode* node)
{
    if(node == NULL)
    {
        return;
    }
    ofstream flog;
    flog.open("log.txt", ios::app);
    flog << node->GetName() << "/" << node->GetAge() << "/" << node->GetAccNum() << endl;
    flog.close();
    Print_L(node->GetNext());

    return;
}