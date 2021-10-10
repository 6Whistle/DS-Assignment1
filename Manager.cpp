#include "Manager.h"
#define INPUT_SIZE 32

Manager::Manager()          //assign ds_queue, ds_bst, ds_heap, ds_list for saving data
{
    ds_queue = new AccountQueue;
    ds_bst = new AccountBST;
    ds_heap = new UserHeap;
    ds_list = new UserList;

}

Manager::~Manager()
{

}

void Manager::run(const char* command)
{
    fin.open(command);                          //open "command.txt"
    flog.open("log.txt", ios::app);             //open "log.txt" and it will write subsequenty
    
    if (!fin)                                   //if "command.txt" does not exist, end function
    { 
        flog << "File Open Error" << endl;
        EXIT();                                 //delete ds_queue, ds_bst, ds_heap, ds_list
        return;
    }

    char cmd[32];

    while (!fin.eof())                          //while "command.txt"'s data is exist
    {
        
        fin.getline(cmd, 32);                   //get a line of data and seperate by " " if cmd is not ""
        if(strcmp(cmd, "") == 0)
        {
            continue;
        }
        char * tmp = strtok(cmd, " ");

        if(strcmp(tmp, "QLOAD") == 0)           //QLOAD
        {
            if(QLOAD())                         //push data from "data.txt" to ds_queue
            {
                ds_queue->PRINT();              //print ds_queue
            }
            else
            {
                PrintErrorCode(100);            // if it fails, print error
            }
        }
        else if(strcmp(tmp, "ADD") == 0)        //ADD
        {
            tmp = strtok(NULL, " ");            //tmp get next data which is seperated by " " 
            if(ADD(tmp))                        //input 1 data at ds_queue.
            {
                ds_queue->PRINTPUSH();          //if it works, print information of input data
            }
            else
            {
                PrintErrorCode(200);             //if it fails, print error
            }
        }
        else if(strcmp(tmp, "QPOP") == 0)       //QPOP
        {
            tmp = strtok(NULL, " ");            //tmp get next data which is seperated by " " 
            if(QPOP(tmp))                       //pop tmp(number) of data from ds_queue. input data at ds_list and ds_bst
            {
                PrintSuccess("QPOP");
            }
            else
            {
                PrintErrorCode(300);            // if it falis, print error
            }
        } 
        else if(strcmp(tmp, "SEARCH") == 0)     //SEARCH
        {
            tmp = strtok(NULL, " ");            //tmp get next data which is seperated by " " 
            if(!SEARCH(tmp))                    //search tmp and print it
            {
                PrintErrorCode(400);            //if it doesn't works, print error
            }
        }
        else if(strcmp(tmp, "PRINT") == 0)      //PRINT
        {
            tmp = strtok(NULL, " ");            //tmp get next data which is seperated by " " 
            if(!(PRINT(tmp)))                   //print data by tmp
            {
                PrintErrorCode(500);            //if it doesn't works, print error
            }
        }
        else if(strcmp(tmp, "DELETE") == 0)     //DELETE
        {
            tmp = strtok(NULL, " ");            //tmp get next data which is seperated by " " 
            if(DELETE(tmp))                     //delete data(id:tmp) at ds_list and ds_bst
            {
                PrintSuccess("DELETE");
            }
            else
            {
                PrintErrorCode(600);            //if it fails, print error
            }
        }
        else if(strcmp(tmp, "HLOAD") == 0)      //HLOAD
        {
            if(HLOAD())                         //delete existed ds_heap and create new heap. input data from ds_list 
            {
                PrintSuccess("HLOAD");
            }
            else
            {
                PrintErrorCode(700);            //if it fails, print error
            }
        }
        else if(strcmp(tmp, "EXIT") == 0)       //EXIT
        {
            PrintSuccess("EXIT");               //break loop
            break;
        }
        else                                    //if command is wrong, print error
        {
            flog << "========== ERROR ==========" << endl;
            flog << "Command Error" << endl;
            flog << "===========================" << endl << endl;
        }
    }

    EXIT();                                     //DELETE ds_queue, ds_list, ds_bst, ds_heap
    fin.close();                                //fin, flog close
    flog.close();

    return;
}

bool Manager::QLOAD()                           //push data from "data.txt" to ds_queue
{
    ifstream fdata;
    fdata.open("data.txt");                     //read data from "data.txt"

    if (!fdata)                                 //if "data.txt" doesn't exist, return false
    {
        return false;
    }

    char input[INPUT_SIZE];

    while(!fdata.eof())
    {
        fdata.getline(input, INPUT_SIZE);       //read one line of data from "data.txt"

        if(strcmp(input, "") == 0)              //if input is "", continue
        {
            continue;
        }
    
        char* temp = strtok(input, " ");        //seperate data to name, charAge, id
        char* name = temp;
        temp = strtok(NULL, " ");
        char* charAge = temp;
        temp = strtok(NULL, " ");
        char* id = temp;

        if(name == NULL || charAge == NULL || id == NULL)       //if name or charAge or id is not exist, close file and return false
        {
            fdata.close();
            return false;
        }

        for(int i = 0; name[i] != '\0'; i++)            //if name is not alphabet, return false
        {
            if(isalpha(name[i]) == false)
            {
                fdata.close();
                return false;
            }
        }

        for(int i = 0; charAge[i] != '\0'; i++)         //if charAge is not digit, return false
        {
            if(isdigit(charAge[i]) == false)
            {
                fdata.close();
                return false;
            }
        }

        int age = atoi(charAge);                        //change age from char to int
        if(age < 10 || age > 69)                        //if age is not 10 ~ 69, return false
        {
            fdata.close();
            return false;
        }

        for(int i = 0; id[i] != '\0'; i++)              //if id is not alphabet and digit, return false
        {
            if(isalnum(id[i]) == false)
            {
                fdata.close();
                return false;
            }
        }

        AccountQueueNode* data = new AccountQueueNode;      //data to input at ds_queue
        data->SetName(name);
        data->SetAge(age);
        data->SetId(id);

        if(ds_queue->PUSH(data) == false)               //if data is not pushed, return false
        {
            fdata.close();
            return false;
        }
    }

    fdata.close();                                      //if all of data is stored, return true
    return true;
}

bool Manager::ADD(char* input)                  //store 1 data at ds_queue.
{

    char* name = input;                         //seperate input to name, charAge, id
    input = strtok(NULL, " ");
    char* charAge = input;
    input = strtok(NULL, " ");
    char* id = input;
    
    if(name == NULL || charAge == NULL || id == NULL)           //if name or charAge or id is NULL, return false
    {
        return false;
    }

    for(int i = 0; name[i] != '\0'; i++)            //if name is not alphabet, return false
    {
        if(isalpha(name[i]) == false)
        {
            return false;
        }
    }

    for(int i = 0; charAge[i] != '\0'; i++)         //if charAge is not digit, return false
    {
        if(isdigit(charAge[i]) == false)
        {
            return false;
        }
    }

    int age = atoi(charAge);                        //change age from char to int
    if(age < 10 || age > 69)                        //if age is not 10 ~ 69, return false
    {
        return false;
    }

    for(int i = 0; id[i] != '\0'; i++)              //if id is not alphabet and digit, return false
    {
        if(isalnum(id[i]) == false)
        {
            return false;
        }
    }

    AccountQueueNode* data = new AccountQueueNode;      //input data
    data->SetName(name);
    data->SetAge(age);
    data->SetId(id);

    return ds_queue->PUSH(data);            //if PUSH(input data at ds_queue) is successed, return true. else return false
}

bool Manager::QPOP(char* input)             //pop tmp(number) of data from ds_queue. input data at ds_list and ds_bst
{
    for(int i = 0; input[i] != '\0'; i++)   //if input is not digit, return false
    {
        if(isdigit(input[i]) == false)
        {
            return false;
        }
    }

    int intInput = atoi(input);             //change input from char to int

    if(intInput > ds_queue->SIZE())         //if intInput < num of ds_queue's data
    {
        return false;
    }

    for(int i = 0; i < intInput; i++)       //pop intInput of data and store at ds_list and ds_bst
    {
        AccountQueueNode* temp = ds_queue->POP();       //remove first data at ds_queue
        if(ds_bst->Insert(ds_list->Insert(temp)) == false)      //if Insert ds_bst and ds_list is fails, return false
        {
            return false;
        }
        delete temp;            //delete temp
    }

    return true;                //if intInput of data is pop, return true
}

bool Manager::SEARCH(char* input)           //search data and print it
{
    char* mode = input;                 //user or id
    input = strtok(NULL, " ");
    char* find = input;             //find of data

    if(mode == NULL || find == NULL)        //if mode or find is NULL, return.
    {
        return false;
    }

    if(strcmp(mode, "user") == 0)           //if mode is "user", find username at ds_list and print it. if it doesn't exit, return false
    {
        return ds_list->Search(find);
    }
    else if(strcmp(mode, "id") == 0)           //if mode is "id", find userid at ds_bst and print it. if it doesn't exit, return false
    {
        return ds_bst->Search_Id(find);
    }
    else                //if mode is wrong, return false
    {
        return false;
    }
}

bool Manager::PRINT(char* input)            //print data by input
{
    char* mode = input;

    if(strcmp(mode, "L") == 0 && ds_list->GetRoot() != NULL)    //if mode is "L" and ds_list has data, print list
    {
        flog << "========== PRINT ==========" << endl;
        flog << "LIST" << endl;
        ds_list->Print_L(ds_list->GetRoot());

        flog << "===========================" << endl << endl;
        
        return true;
    }
    else if(strcmp(mode, "B") == 0 && ds_bst->GetRoot() != NULL)        //if mode is "B" and ds_bst has data
    {
        input = strtok(NULL, " ");
        char* mode2 = input;

        if(strcmp(mode2, "PRE") == 0)           //if mode2 is "PRE", print bst by pre-order
        {
            flog << "========== PRINT ==========" << endl;
            flog << "BST PRE" << endl;
            ds_bst->Print_PRE(ds_bst->GetRoot());

            flog << "===========================" << endl << endl;

            return true; 
        }
        if(strcmp(mode2, "IN") == 0)           //if mode2 is "IN", print bst by in-order
        {
            flog << "========== PRINT ==========" << endl;
            flog << "BST IN" << endl;
            ds_bst->Print_IN(ds_bst->GetRoot());

            flog << "===========================" << endl << endl;
        
            return true;
        }
        if(strcmp(mode2, "POST") == 0)           //if mode2 is "POST", print bst by post-order
        {
            flog << "========== PRINT ==========" << endl;
            flog << "BST POST" << endl;
            ds_bst->Print_POST(ds_bst->GetRoot());

            flog << "===========================" << endl << endl;

            return true;
        }
        if(strcmp(mode2, "LEVEL") == 0)           //if mode2 is "LEVEL", print bst by level-order
        {
            flog << "========== PRINT ==========" << endl;
            flog << "BST LEVEL" << endl;
            ds_bst->Print_LEVEL();

            flog << "===========================" << endl << endl;

            return true;
        }
        else                    //if mode2 is wrong, return false
        {
            return false;
        }
    }
    else if(strcmp(mode, "H") == 0 && ds_heap->GetSize() != 1)      //if mode is "H" and ds_heap has data, print heap
    {
        flog << "========== PRINT ==========" << endl;
        flog << "Heap" << endl;
        ds_heap->Print();

        flog << "===========================" << endl << endl;

        return true;
    }
    else            //if mode is wrong, return false
    {
        return false;
    }
}

bool Manager::DELETE(char* input)               //delete data(id:input) at ds_list and ds_bst
{
    char* findname = ds_bst->FindNameFromId(input);         //find name by using FindNameFromId()

    if(findname)            //if name is found, delete at list
    {
        bool state = ds_list->Delete_Account(findname, input);
        if(state == true)               //if delete list is execute, delete at bst
        {
            return ds_bst->Delete(input);
        }

        return state;
    }
    
    return false;
}

bool Manager::HLOAD()       //delete existed ds_heap and create new heap. input data from ds_list 
{
    if (ds_heap->GetSize() != 1)        //if ds_heap has data, remove it
    {
        delete ds_heap;
        ds_heap = new UserHeap;
    }

    UserListNode* temp = ds_list->GetRoot();

    if(temp == NULL)        //if list isn't exist, return false
    {
        return false;
    }

    while(temp)         //input all of data(list) at ds_heap
    {
        int agegroup = (temp->GetAge() / 10) * 10;      //throws units digit of age
        if(ds_heap->Insert(agegroup) == false)      //if inserting agegroup at heap is not works, return false
        {
            return false;
        }
        temp = temp->GetNext();     //next data(list)
    }

    return true;
}

bool Manager::EXIT()                //DELETE ds_queue, ds_list, ds_bst, ds_heap
{
    if(ds_queue)            //if ds_queue is exist, delete ds_queue
    {
        delete ds_queue;
    }
    if(ds_list)             //if ds_list is exist, delete ds_list
    {
        delete ds_list;
    }
    if(ds_bst)              //if ds_bst is exist, delete ds_bst
    {
        delete ds_bst;
    }
    if(ds_heap)             //if ds_heap is exist, delete ds_heap
    {
        delete ds_heap;
    }
    

    return true;
}

void Manager::PrintErrorCode(int num)           //print error code at "log.txt"
{
    flog << "========== ERROR ==========" << endl;
    flog << num << endl;
    flog << "===========================" << endl << endl;
}

void Manager::PrintSuccess(char* act)           //print seccess code at "log.txt"
{
    flog << "========== " << act << " ==========" << endl;
    flog << "Success" << endl;
    flog << "============================" << endl << endl;
}