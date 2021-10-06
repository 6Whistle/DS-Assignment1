#include "Manager.h"
#define INPUT_SIZE 32

Manager::Manager()
{
    ds_queue = new AccountQueue;
    ds_bst = new AccountBST;
    ds_heap = new UserHeap;
    ds_list = new UserList;

}

Manager::~Manager()
{
    delete ds_queue;
    delete ds_bst;
    delete ds_heap;
    delete ds_list;
}

void Manager::run(const char* command)
{
    fin.open(command);
    flog.open("log.txt", ios::app);
    if (!fin)
    {
        flog << "File Open Error" << endl;
        return;
    }

    char cmd[32];

    while (!fin.eof())
    {
        fin.getline(cmd, 32);
        char * tmp = strtok(cmd, " ");
        if(strcmp(tmp, "QLOAD") == 0)
        {
            if(QLOAD())
            {
                ds_queue->PRINT();
            }
            else
            {
                PrintErrorCode(100);
            }
        }
        else if(strcmp(tmp, "ADD") == 0)
        {
            tmp = strtok(NULL, " ");
            if(ADD(tmp))
            {
                ds_queue->PRINTPUSH();
            }
            else
            {
                PrintErrorCode(200);
            }
        }
        else if(strcmp(tmp, "QPOP") == 0)
        {
            tmp = strtok(NULL, " ");
            if(QPOP(tmp))
            {
                PrintSuccess("QPOP");
            }
            else
            {
                PrintErrorCode(300);
            }
        } 
        else if(strcmp(tmp, "SEARCH") == 0)
        {
            tmp = strtok(NULL, " ");
            if(!SEARCH(tmp))
            {
                PrintErrorCode(400);
            }
        }
        else if(strcmp(tmp, "PRINT") == 0)
        {
            tmp = strtok(NULL, " ");
            if(!(PRINT(tmp)))
            {
                PrintErrorCode(500);
            }
        }
        else if(strcmp(tmp, "DELETE") == 0)
        {
            tmp = strtok(NULL, " ");
            if(DELETE(tmp))
            {
                PrintSuccess("DELETE");
            }
            else
            {
                PrintErrorCode(600);
            }
        }
        else if(strcmp(tmp, "HLOAD") == 0)
        {
            if(HLOAD())
            {
                PrintSuccess("HLOAD");
            }
            else
            {
                PrintErrorCode(700);
            }
        }
        else if(strcmp(tmp, "EXIT") == 0)
        {
            EXIT();
            PrintSuccess("EXIT");
            break;
        }
        else if(tmp == NULL)
        {
            continue;
        }
        else
        {
            flog << "========== ERROR ==========" << endl;
            flog << "Command Error" << endl;
            flog << "===========================" << endl << endl;
        }
    }
    fin.close();
    flog.close();
}

bool Manager::QLOAD()
{
    ifstream fdata;
    fdata.open("data.txt");
    if (!fdata)
    {
        return false;
    }

    char input[INPUT_SIZE];

    while(!fdata.eof())
    {
        fdata.getline(input, INPUT_SIZE);
    
        char* temp = strtok(input, " ");
        char* name = temp;
        temp = strtok(NULL, " ");
        char* charAge = temp;
        temp = strtok(NULL, " ");
        char* id = temp;

        if(name == NULL || charAge == NULL || id == NULL)
        {
            fdata.close();
            return false;
        }

        for(int i = 0; name[i] != '\0'; i++)
        {
            if(isalpha(name[i]) == false)
            {
                fdata.close();
                return false;
            }
        }

        for(int i = 0; charAge[i] != '\0'; i++)
        {
            if(isdigit(charAge[i]) == false)
            {
                return false;
            }
        }

        int age = atoi(charAge);
        if(age < 10 || age > 69)
        {
            return false;
        }

        for(int i = 0; id[i] != '\0'; i++)
        {
            if(isalnum(id[i]) == false)
            {
                return false;
            }
        }

        AccountQueueNode* data = new AccountQueueNode;
        data->SetName(name);
        data->SetAge(age);
        data->SetId(id);

        if(ds_queue->PUSH(data) == false)
        {
            fdata.close();
            return false;
        }
    }

    fdata.close();
    return true;
}

bool Manager::ADD(char* input)
{

    char* name = input;
    input = strtok(NULL, " ");
    char* charAge = input;
    input = strtok(NULL, " ");
    char* id = input;
    
    if(name == NULL || charAge == NULL || id == NULL)
    {
        return false;
    }

    for(int i = 0; name[i] != '\0'; i++)
    {
        if(isalpha(name[i]) == false)
        {
            return false;
        }
    }

    for(int i = 0; charAge[i] != '\0'; i++)
    {
        if(isdigit(charAge[i]) == false)
        {
            return false;
        }
    }

    int age = atoi(charAge);
    if(age < 10 || age > 69)
    {
        return false;
    }

    for(int i = 0; id[i] != '\0'; i++)
    {
        if(isalnum(id[i]) == false)
        {
            return false;
        }
    }

    AccountQueueNode* data = new AccountQueueNode;
    data->SetName(name);
    data->SetAge(age);
    data->SetId(id);

    return ds_queue->PUSH(data);
}

bool Manager::QPOP(char* input)
{
    for(int i = 0; input[i] != '\0'; i++)
    {
        if(isdigit(input[i]) == false)
        {
            return false;
        }
    }

    int intInput = atoi(input);

    if(intInput > ds_queue->SIZE())
    {
        return false;
    }

    for(int i = 0; i < intInput; i++)
    {
        AccountQueueNode* temp = ds_queue->POP();
        if(ds_bst->Insert(ds_list->Insert(temp)) == false)
        {
            return false;
        }
        delete temp;   
    }

    return true;
}

bool Manager::SEARCH(char* input)
{
    char* mode = input;
    input = strtok(NULL, " ");
    char* find = input;

    if(mode == NULL && find == NULL)
    {
        return false;
    }

    if(strcmp(mode, "user") == 0)
    {
        return ds_list->Search(find);
    }
    else if(strcmp(mode, "id") == 0)
    {
        return ds_bst->Search_Id(find);
    }
    else
    {
        return false;
    }
}

bool Manager::PRINT(char* input)
{
    char* mode = input;
    if(strcmp(mode, "L") == 0 && ds_list->GetRoot() != NULL)
    {
        flog << "========== PRINT ==========" << endl;
        flog << "LIST" << endl;
        ds_list->Print_L(ds_list->GetRoot());

        flog << "===========================" << endl << endl;
        
        return true;
    }
    else if(strcmp(mode, "B") == 0 && ds_bst->GetRoot() != NULL)
    {
        input = strtok(NULL, " ");
        char* mode2 = input;

        if(strcmp(mode2, "PRE") == 0)
        {
            flog << "========== PRINT ==========" << endl;
            flog << "BST PRE" << endl;
            ds_bst->Print_PRE(ds_bst->GetRoot());

            flog << "===========================" << endl << endl;

            return true; 
        }
        if(strcmp(mode2, "IN") == 0)
        {
            flog << "========== PRINT ==========" << endl;
            flog << "BST IN" << endl;
            ds_bst->Print_IN(ds_bst->GetRoot());

            flog << "===========================" << endl << endl;
        
            return true;
        }
        if(strcmp(mode2, "POST") == 0)
        {
            flog << "========== PRINT ==========" << endl;
            flog << "BST POST" << endl;
            ds_bst->Print_POST(ds_bst->GetRoot());

            flog << "===========================" << endl << endl;

            return true;
        }
        if(strcmp(mode2, "LEVEL") == 0)
        {
            flog << "========== PRINT ==========" << endl;
            flog << "BST LEVEL" << endl;
            ds_bst->Print_LEVEL();

            flog << "===========================" << endl << endl;

            return true;
        }
        else
        {
            return false;
        }
    }
    else if(strcmp(mode, "H") == 0 && ds_heap->GetSize() != 1)
    {
        flog << "========== PRINT ==========" << endl;
        flog << "Heap" << endl;
        ds_heap->Print();

        flog << "===========================" << endl << endl;

        return true;
    }
    else
    {
        return false;
    }
}

bool Manager::DELETE(char* input)
{
    char* findname = NULL;
    ds_bst->FindNameFromId(input, findname);

    if(findname)
    {
        return ds_list->Delete_Account(findname, input);
    }
    
    return false;
}

bool Manager::HLOAD()
{
    UserListNode* temp = ds_list->GetRoot();

    while(temp)
    {
        int agegroup = (temp->GetAge() / 10) * 10;
        if(ds_heap->Insert(agegroup) == false)
        {
            return false;
        }
        temp = temp->GetNext();
    }
}

bool Manager::EXIT()
{
    delete ds_queue;
    delete ds_list;
    delete ds_bst;
    delete ds_heap;

    return true;
}

void Manager::PrintErrorCode(int num)
{
    flog << "========== ERROR ==========" << endl;
    flog << num << endl;
    flog << "===========================" << endl << endl;
}

void Manager::PrintSuccess(char* act)
{
    flog << "========== " << act << " ==========" << endl;
    flog << "Success" << endl;
    flog << "============================" << endl << endl;
}