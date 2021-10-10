#include "UserList.h"

UserList::UserList()
{
    Root = NULL;
}

UserList::~UserList()       //delete list
{
    while(Root)
    {
        UserListNode* temp = Root->GetNext();
        delete Root;
        Root = temp;
    }
}

UserListNode* UserList::GetRoot()       //get root
{
    return Root;
}

AccountBSTNode* UserList::Insert(AccountQueueNode* node)        //get data from node and convert it. and store at list
{
    AccountBSTNode* insertNode = new AccountBSTNode;        //data to input
    insertNode->SetId(node->GetId());
    insertNode->SetName(node->GetName());
    
    if(Root == NULL)            //if root is NULL, insert List
    {
        UserListNode* insertList = new UserListNode;
        insertList->SetName(node->GetName());
        insertList->SetAge(node->GetAge());
        insertList->InsertAccount(insertNode);
        Root = insertList;

        return insertNode;
    }

    UserListNode* temp = Root;

    while(temp && strcmp(temp->GetName(), insertNode->GetName()) != 0)      //while same name is not exist and temp is NULL, 
    {
        if(temp->GetNext() == NULL)         //if current point is last point, insert new list
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

    if(temp->GetAccNum() < 3)       //if same name is found and AccNum is not more than 3, insert it
    {
        temp->InsertAccount(insertNode);
        return insertNode;
    }
    else            //if AccNum >= 3, don't store
    {
        delete insertNode;
        return NULL;
    }
}

bool UserList::Search(char* name)           //Search data by name
{
    if(Root == NULL)            //if data is not exist, return false
    {
        return false;
    }

    UserListNode* temp = Root;

    while(temp)
    {
        if(strcmp(temp->GetName(), name) == 0)      //if same name is found
        {
            ofstream flog;
            flog.open("log.txt", ios::app);
            flog << "========== SEARCH ==========" << endl;
            flog << "User" << endl;
            flog << temp->GetName() << "/" << temp->GetAge() << endl;
            
            AccountBSTNode* idTemp = temp->GetHead();
            while(idTemp)                       //print all of id data
            {
                flog << idTemp->GetId() << endl;
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

bool UserList::Delete_Account(char* name, char* id)     //delete by name and id
{
    if(Root == NULL)        //if data is not exist, return false
    {
       return false;
    }

    UserListNode *cur = Root, *prev = NULL;

    while(cur && strcmp(cur->GetName(), name) != 0)         //move while current pointer's name is not same
    {
       prev = cur;
       cur = cur->GetNext();
    }

   if(cur == NULL)          //data does not exist, return false
    {
       return false;
    }

    AccountBSTNode* tempBST = cur->GetHead();
    bool state = false;

    while(tempBST)          //Search in bst
    {
        if(strcmp(tempBST->GetId(), id) == 0)       //if same id is found, state = true
        {
            state = true;
        }
        tempBST = tempBST->GetNext();
    }

    if(state == false)      //if same id does not exist, return false
    {
        return false;
    }
    
    cur->Delete_Account(id);        //delete id

    if(cur->GetAccNum() == 0)       //if AccNum is 0, delete list
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

void UserList::Print_L(UserListNode* node)      //print list
{
    if(node == NULL)        //if data doesn't exist, return
    {
        return;
    }
    ofstream flog;
    flog.open("log.txt", ios::app);
    flog << node->GetName() << "/" << node->GetAge() << "/" << node->GetAccNum() << endl;       //print data
    flog.close();
    Print_L(node->GetNext());       //print next node

    return;
}