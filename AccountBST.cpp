#include "AccountBST.h"


AccountBST::AccountBST()
{
    this->Root = NULL;
}

AccountBST::~AccountBST()
{
    queue <AccountBSTNode*> deleteQueue;

    deleteQueue.push(Root);

    while(!(deleteQueue.empty()))
    {
        AccountBSTNode *temp = deleteQueue.front();
        deleteQueue.pop();

        if(temp->GetLeft())
        deleteQueue.push(temp->GetLeft());
        if(temp->GetRight())
        deleteQueue.push(temp->GetRight());

        delete temp;
    }
}

AccountBSTNode* AccountBST::GetRoot()
{
    return this->Root;
}

bool AccountBST::Insert(AccountBSTNode* node)
{
    if(Root == NULL)
    {
        this->Root = node;
        return true;
    }

    AccountBSTNode* temp = this->Root;

    while(true)
    {
       if(strcmp(node->GetId(), temp->GetId()) == 0)
        {
            return false;
        }
        else if(strcmp(node->GetId(), temp->GetId()) > 0)
        {

            if(temp->GetLeft() == NULL)
            {
                temp->SetLeft(node);
                return true;
            }
            else
            {
                temp = temp->GetLeft();
            }
        }
        else
        {
            if(temp->GetRight() == NULL)
            {
                temp->SetRight(node);
                return true;
            }
            else
            {
                temp = temp->GetRight();
            }
        }

    }


}

bool AccountBST::Search_Id(char* id)
{
    if(Root == NULL)
    {
        return false;
    }

    AccountBSTNode* temp = this->Root;
    while(true)
    {
        if(strcmp(id,temp->GetId()) == 0)
        {
            //출력 구현 필요
            return true;
        }

        if(strcmp(id,temp->GetId()) > 0)
        {
            if(temp->GetLeft() == NULL)
            {
                return false;
            }

            temp = temp->GetLeft();
        }
        else
        {
            if(temp->GetRight() == NULL)
            {
                return false;
            }

            temp = temp->GetRight();
        }
    }
}

bool AccountBST::Delete(char* id)
{
    if(Root == NULL)
    {
        return false;
    }

    AccountBSTNode* temp = this->Root;
    AccountBSTNode* parent = NULL;


    while(temp && strcmp(id, temp->GetId()) != 0)
    {
        parent = temp;

        if(strcmp(id,temp->GetId()) > 0)
        {
            temp = temp->GetLeft();
        }
        else
        {
            temp = temp->GetRight();
        }

        if(temp == NULL)
        {
            return false;
        }
    }

    if(temp->GetLeft() == NULL && temp->GetRight() == NULL)
    {
        if(parent == NULL)
        {
            Root = NULL;
        }
        else if(parent->GetLeft() == temp)
        {
            parent->SetLeft(NULL);
        }
        else
        {
            parent->SetRight(NULL);
        }
        delete temp;
    }
    else if(temp->GetLeft() == NULL)
    {
        if(parent == NULL)
        {
            Root = temp->GetRight();
        }
        else if(parent->GetLeft() == temp)
        {
            parent->SetLeft(temp->GetRight());
        }
        else
        {
            parent->SetRight(temp->GetRight());
        }
        delete temp;
    }
    else if(temp->GetRight() == NULL)
    {
        if(parent == NULL)
        {
            Root = temp->GetLeft();
        }
        else if(parent->GetLeft() == temp)
        {
            parent->SetLeft(temp->GetLeft());
        }
        else
        {
            parent->SetRight(temp->GetLeft());
        }
        delete temp;
    }
    else
    {
        AccountBSTNode *prevprev = temp, *prev = temp->GetLeft(), *cur = prev->GetRight();
        AccountBSTNode *Ltemp = temp->GetLeft(), *Rtemp = temp->GetRight();

        while(cur)
        {
            prevprev = prev;
            prev = cur;
            cur = cur->GetLeft();
        }

        AccountBSTNode *Rprev = prev->GetRight();

        prev->SetLeft(Ltemp);
        prev->SetRight(Rtemp);
        
        if(parent->GetLeft() == temp)
        {
            parent->SetLeft(prev);
        }
        else
        {
            parent->SetRight(prev);
        }
        
        if(prevprev == temp)
        {
            prevprev->SetRight(Rprev);
        }
        else
        {
            prevprev->SetLeft(Rprev);
        }

        delete temp;
    }

    

}

void AccountBST::Print_PRE(AccountBSTNode* node)
{
    if(node)
    {
        //출력
        Print_PRE(node->GetLeft());
        Print_PRE(node->GetRight());
    }

    return;
}

void AccountBST::Print_IN(AccountBSTNode* node)
{
    if(node)
    {

         Print_PRE(node->GetLeft());
         //출력
        Print_PRE(node->GetRight());
    }
}

void AccountBST::Print_POST(AccountBSTNode* node)
{
    if(node)
    {
        Print_PRE(node->GetLeft());
        Print_PRE(node->GetRight());
        //출력
    }
}

void AccountBST::Print_LEVEL()
{
    queue <AccountBSTNode*> levelQueue;

    levelQueue.push(Root);

    while(!(levelQueue.empty()))
    {
        AccountBSTNode *temp = levelQueue.front();
        levelQueue.pop();

        //print
        if(temp->GetLeft())
        levelQueue.push(temp->GetLeft());
        if(temp->GetRight())
        levelQueue.push(temp->GetRight());
        
    }
}