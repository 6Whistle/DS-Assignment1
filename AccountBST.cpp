#include "AccountBST.h"


AccountBST::AccountBST()
{
    this->Root = NULL;
}

AccountBST::~AccountBST()
{
    queue <AccountBSTNode*> deleteQueue;        //delete bst by level order

    deleteQueue.push(Root);         //push Root

    while(!(deleteQueue.empty()))           //while deleteQueue has data, push front->left and right, and delete front; 
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

AccountBSTNode* AccountBST::GetRoot()       //get Root
{
    return this->Root;
}

bool AccountBST::Insert(AccountBSTNode* node)       //inset node at bst
{
    if(node == NULL)        //if node is NULL, return false
    {
        return false;
    }

    if(Root == NULL)        //if data is not exist at bst
    {
        this->Root = node;
        return true;
    }

    AccountBSTNode* temp = this->Root;

    while(true)         //if data is exist at bst
    {
       if(CompareName(node->GetId(), temp->GetId()) == 0)       //if same data is exist, return false
        {
            return false;
        }
        else if(CompareName(node->GetId(), temp->GetId()) < 0)      //if node's id is placed at leftside of temp
        {

            if(temp->GetLeft() == NULL)     //if leftside of temp is not exist, store at there
            {
                temp->SetLeft(node);
                return true;
            }
            else                            //if leftside of temp is exist, program will compare again with leftside of temp
            {
                temp = temp->GetLeft();
            }
        }
        else                                                        //if node's id is placed at rightside of temp
        {
            if(temp->GetRight() == NULL)                            //if rightside of temp is not exist, store at there
            {
                temp->SetRight(node);
                return true;
            }
            else                            //if rightside of temp is exist, program will compare again with rightside of temp
            {
                temp = temp->GetRight();
            }
        }

    }


}

bool AccountBST::Search_Id(char* id)        //search id and return true when it exist
{
    if(Root == NULL)            //if bst has no data, return false
    {
        return false;
    }

    AccountBSTNode* temp = this->Root;
    while(true)
    {
        if(CompareName(id,temp->GetId()) == 0)      //if find id, print at "log.txt"
        {
            ofstream flog;
            flog.open("log.txt", ios::app);
            flog << "========== SEARCH ==========" << endl;
            flog << "ID" << endl;
            flog << temp->GetId() << "/" << temp->GetName() << endl;
            flog << "===========================" << endl << endl; 
            flog.close();
            return true;
        }

        if(CompareName(id,temp->GetId()) < 0)       //if id is placed at leftside of temp
        {
            if(temp->GetLeft() == NULL)     //if leftside is empty, return false
            {
                return false;
            }

            temp = temp->GetLeft();         //temp = leftside of temp
        }
        else                                        //if id is placed at rightside of temp
        {
            if(temp->GetRight() == NULL)    //if rightside is empty, return false
            {
                return false;
            }

            temp = temp->GetRight();        //temp = rightside of temp
        }
    }
}

bool AccountBST::Delete(char* id)
{
    if(Root == NULL)        //if bst is empty, return false
    {
        return false;
    }

    AccountBSTNode* temp = this->Root;
    AccountBSTNode* parent = NULL;          //temp's parents


    while(temp && CompareName(id, temp->GetId()) != 0)      //repeat while temp is not NULL and id is not same
    {
        parent = temp;

        if(CompareName(id,temp->GetId()) < 0)       //if id is placed at leftside of temp, temp = leftside of temp
        {
            temp = temp->GetLeft();
        }
        else                                        //if id is placed at rightside of temp, temp = rightside of temp
        {
            temp = temp->GetRight();
        }

        if(temp == NULL)            //if not find until end, return false
        {
            return false;
        }
    }

   
    //found temp that have to delete
    if(temp->GetLeft() == NULL && temp->GetRight() == NULL)     //if temp is leaf
    {
        if(parent == NULL)      //if temp is Root, delete Root
        {
            Root = NULL;
        }
        else if(parent->GetLeft() == temp)      //if temp has parent, set parent's pLeft or pRight => NULL
        {
            parent->SetLeft(NULL);
        }
        else
        {
            parent->SetRight(NULL);
        }
        delete temp;                //delete temp
    }
    else if(temp->GetLeft() == NULL)                            //if temp has only right child
    {
        if(parent == NULL)      //if temp is Root, Root is temp's right child
        {
            Root = temp->GetRight();
        }
        else if(parent->GetLeft() == temp)      //if temp has parent, set parent's pLeft or pRight => temp's Right child
        {
            parent->SetLeft(temp->GetRight());
        }
        else
        {
            parent->SetRight(temp->GetRight());
        }
        delete temp;                //delete temp
    }
    else if(temp->GetRight() == NULL)                           //if temp has only left child
    {
        if(parent == NULL)      //if temp is Root, Root is temp's left child
        {
            Root = temp->GetLeft();
        }
        else if(parent->GetLeft() == temp)      //if temp has parent, set parent's pLeft or pRight => temp's left child
        {
            parent->SetLeft(temp->GetLeft());
        }
        else
        {
            parent->SetRight(temp->GetLeft());
        }
        delete temp;                //delete temp
    }
    else                //if temp has left and right child
    {
        AccountBSTNode *prevprev = temp, *prev = temp->GetRight(), *cur = prev->GetLeft();          //to find change node
        AccountBSTNode *Ltemp = temp->GetLeft(), *Rtemp = temp->GetRight();     //store temp's left and right child

        while(cur)      //find smallest node(prev) which is bigger then temp
        {
            prevprev = prev;
            prev = cur;
            cur = cur->GetLeft();
        }

        AccountBSTNode *Rprev = prev->GetRight();       //to store change node's right child


        
        if (parent == NULL)                 //if temp is root
        {
            Root = prev;                //root is change node

            if (prevprev == temp)           //if temp's child is change node, change node's left is left side of temp
            {
                prev->SetLeft(Ltemp);
            }            
            else                            //if temp's child is not change node, change node's left and right side is temp's child, and prevprev's left child is change node's original rightside
            {
                prev->SetLeft(Ltemp);
                prev->SetRight(Rtemp);
                prevprev->SetLeft(Rprev);
            }

        }
        else                                //if temp is not root
        {
            prev->SetLeft(Ltemp);           //change node's left and right side is temp's child
            prev->SetRight(Rtemp);

            if (parent->GetLeft() == temp)    //set parent's left or right side to prev
            {
                parent->SetLeft(prev);
            }
            else
            {
                parent->SetRight(prev);
            }

            if (prevprev == temp)           //if temp's child is change node, change node's left is left side of temp
            {
                prev->SetRight(Rprev);
            }
            else
            {
                prevprev->SetLeft(Rprev);       //if temp's child is not change node, prevprev's left child is change node's original rightside
            }
        }
        

        delete temp;        //delete data
    }

    return true;
}

void AccountBST::Print_PRE(AccountBSTNode* node)            //print by Pre-order
{
    if(node)        //only node is not NULL, it will execute
    {
        ofstream flog;                                      //print data at "log.txt"
        flog.open("log.txt", ios::app);
        flog << node->GetId() << "/" << node->GetName() << endl;
        flog.close();

        Print_PRE(node->GetLeft());                     //recursive leftside
        Print_PRE(node->GetRight());                    //recursive rightside
    }

    return;
}

void AccountBST::Print_IN(AccountBSTNode* node)             //print by In-order
{
    if(node)        //only node is not NULL, it will execute
    {

        Print_IN(node->GetLeft());                     //recursive leftside

        ofstream flog;                                      //print data at "log.txt"
        flog.open("log.txt", ios::app);
        flog << node->GetId() << "/" << node->GetName() << endl;
        flog.close();

        Print_IN(node->GetRight());                    //recursive rightside
    }

    return;
}

void AccountBST::Print_POST(AccountBSTNode* node)           //print by Post-order
{
    if(node)        //only node is not NULL, it will execute
    {
        Print_POST(node->GetLeft());                     //recursive leftside
        Print_POST(node->GetRight());                    //recursive rightside

        ofstream flog;                                      //print data at "log.txt"
        flog.open("log.txt", ios::app);
        flog << node->GetId() << "/" << node->GetName() << endl;
        flog.close();
    }

    return;
}

void AccountBST::Print_LEVEL()                  //print by Level-order
{
    queue <AccountBSTNode*> levelQueue;         //make queue for print by level-order
    ofstream flog;
    flog.open("log.txt", ios::app);         //open "log.txt"

    levelQueue.push(Root);              //push Root at levelQueue 

    while(!(levelQueue.empty()))        //while levelQueue has data, it execute
    {
        AccountBSTNode *temp = levelQueue.front();      //pop front data and print
        levelQueue.pop();
        flog << temp->GetId() << "/" << temp->GetName() << endl;
        
        if(temp->GetLeft())                 //if popped data has left or right side, push them
            levelQueue.push(temp->GetLeft());
        if(temp->GetRight())
            levelQueue.push(temp->GetRight());
        
    }

    flog.close();
    return;
}

int AccountBST::CompareName(char* cm1, char* cm2)           //compare two string
{
    char ch1, ch2;
    int i;

    for (i = 0; i < 32 && cm1[i] != '\0' && cm2[i] != '\0'; i++)        //compare i's char. if it is not same, return -1 or 1
    {
        if (isupper(cm1[i]))            //to compare lower case
        {
            ch1 = tolower(cm1[i]);
        }
        else
        {
            ch1 = cm1[i];
        }

        if (isupper(cm2[i]))            //to compare lower case
        {
            ch2 = tolower(cm2[i]);
        }
        else
        {
            ch2 = cm2[i];
        }

        if (ch1 < ch2)
        {
            return -1;
        }
        else if (ch1 > ch2)
        {
            return 1;
        }
    }

    if (cm1[i] == '\0' && cm2[i] != '\0')       //if cm1 is long, return -1
    {
        return -1;
    }

    if (cm1[i] != '\0' && cm2[i] == '\0')       //if cm2 is long, return 1
    {
        return 1;
    }

    return 0;           //if cm1 and cm2 is same, return 0
}

char* AccountBST::FindNameFromId(char* id)          //find id and return name that use id
{
    if(Root == NULL)        //if bst has no data, return false
    {
        return NULL;
    }

    AccountBSTNode* temp = this->Root;
    while(true)
    {
        if(CompareName(id,temp->GetId()) == 0)      //if id is found, return name
        {
            return temp->GetName();
        }

        if(CompareName(id,temp->GetId()) < 0)       //if id is place at temp's left side
        {
            if(temp->GetLeft() == NULL)     //if temp's leftside is empty, return NULL
            {
                return NULL;
            }

            temp = temp->GetLeft();         //if temp's leftside is not empty, temp = temp's leftside
        }
        else                                        //if id is place at temp's right side
        {
            if(temp->GetRight() == NULL)     //if temp's rightside is empty, return NULL
            {
                return NULL;
            }

            temp = temp->GetRight();         //if temp's leftside is not empty, temp = temp's rightside
        }
    }
}