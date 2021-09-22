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
                PrintSuccess("QLOAD");
            }
            else
            {
                PrintErrorCode(100);
            }
        }
        else if(strcmp(tmp, "ADD") == 0)
        {
            if(ADD())
            {
                PrintSuccess("ADD");
            }
            else
            {
                PrintErrorCode(200);
            }
        }
        else if(strcmp(tmp, "QPOP") == 0)
        {
            if(QPOP())
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
            if(SEARCH())
            {
                PrintSuccess("SEARCH");
            }
            else
            {
                PrintErrorCode(400);
            }
        }
        else if(strcmp(tmp, "PRINT") == 0)
        {
            if(PRINT())
            {
                PrintSuccess("PRINT");
            }
            else
            {
                PrintErrorCode(500);
            }
        }
        else if(strcmp(tmp, "DELETE") == 0)
        {
            if(DELETE())
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
    fin.open("data.txt");
    if (!fin)
    {
        return false;
    }

    char input[INPUT_SIZE];
    cin.getline(input, INPUT_SIZE);
    
    char* inputName = strtok(input, " ");
    char* inputAge = strtok(input, " ");
    //해야하는 부분

}

bool Manager::ADD()
{

}

bool Manager::QPOP()
{

}

bool Manager::SEARCH()
{

}

bool Manager::PRINT()
{

}

bool Manager::DELETE()
{

}

bool Manager::HLOAD()
{

}

bool Manager::EXIT()
{

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