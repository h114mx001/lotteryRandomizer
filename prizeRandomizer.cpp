#include <bits/stdc++.h>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
map <string,int> sourceHadPrizes;
char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
char red[] = { 0x1b, '[', '0', ';', '9', '1', 'm', 0 };
int main(){
    srand(time(NULL));
    //create IDList;
    cout << "Installing data..." << "\n";
    ifstream file;
    file.open("databaseTicket.csv");
    string name;
    string number;
    vector <string> IDQuery;
    //Reading the information of lottery tickets from databaseTicket.csv
    while (getline(file, number, ',')){
        getline(file, name, '\n');
        IDQuery.push_back(name);
    }
    file.close();
    //create map of member for checking.
    ifstream file1;
    file1.open("data.csv");
    while(getline(file, name, ',')){
        getline(file,number);
        sourceHadPrizes[name] = 0;
    }
    cout << "Finish installing data!" << "\n";
    cout << red << "\n";
   //Random giai
    cout << "                                       __          __  __                 ______   ___   ___" << endl;
    cout << "                                      / /   ____  / /_/ /____  _______  _<  /__ \\ /   | <  /" << endl;
    cout << "                                     / /   / __ \\/ __/ __/ _ \\/ ___/ / / / /__/ // /| | / /"  << endl;
    cout << "                                    / /___/ /_/ / /_/ /_/  __/ /  / /_/ / // __// ___ |/ /"   << endl;
    cout << "                                   /_____/\\____/\\__/\\__/\\___/_/   \\__, /_//____/_/  |_/_/"    << endl;
    cout << "                                                                 /____/                  "    << endl;
    #ifdef _WIN32
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    #endif
    // Introduction
    cout << "\n";
    std::cout << "\033[32m" << "                  + -- --  += Author: Tuan Anh Nguyen | github: www.github.com/h114mx001                            =+  -- -- +" << "\033[0m" << std::endl;
    std::cout << "\033[32m" << "                  + -- --  += Clone this repository: git clone https://github.com/h114mx001/lotteryRandomizer       =+  -- -- +" << "\033[0m" << std::endl;
    cout << red << "                  Rule!: " << "\n";
    cout << "                  [1]:   These prizes are randomly generated <though it's pseudo.;)> \n";
    cout << "                  [2]:   You can win ONLY ONE prize in each category. Eg: You can only win one Second Prize. No two. \n";
    cout << "                  [3]:   However, you can win one or more DIFFERENT categories. Eg: You can win one Third, one Second and one Top-Prize. \n";
    cout << "                  [4]:   All you guys must list your lottery tickets before the lucky draw begins \n";
    cout << "                  [5]:   We will have: \n";
    cout << "                       +  1 Top-prize      - 60.000 VND\n";
    cout << "                       +  1 First prize    - 50.000 VND\n";
    cout << "                       +  2 Second prizes  - 20.000 VND\n";
    cout << "                       +  3 Third prizes   - 15.000 VND\n";
    cout << "                       + 10 Fourth prizes  - 10.000 VND\n";
    cout << normal << "                  ======================================================================\n";
    cout << red << "                  Before starting the lucky draw, let's congratulate three top server players!!! \n";
    cout << "                  1st:   Le Ngoc Anh, Nguyen Le Huong Tra:    22 tickets each  - 20.000 VND \n";
    cout << "                  2nd:   Bui Thi Ngoc Phuong:                 20 tickets       - 15.000 VND\n";
    char ready;
    cout << "                  Shall we start? (Y/N): ";
    cin >> ready;               //Make color =)))
    int size = IDQuery.size();  // Get the number of tickets

    // The draw starts from here
    bool isTicketHadAPrize[size]; 
    cout << normal << "                  How many type of prizes you want to roll?: ";
    int numberOfPrizes;
    cin >> numberOfPrizes;
    for (int i = 1; i <= numberOfPrizes; i++){
        map <string,int> subHadPrize = sourceHadPrizes;
        string nameOfPrizes;
        cout << normal << "                  Name of Prize: ";
        cin >> nameOfPrizes;
        cout << "                  How many prizes do you want?: ";
        int numOfPrizes = 0;
        cin >> numOfPrizes;
        cout << blue << "                  ==================================================================================\n";
        cout << "                  CONGRATULATION! THESE LUCKY GUYS WIN THE " << nameOfPrizes << " PRIZE! \n";
        int count = 0;
        while (count < numOfPrizes){
            // sleep(4);
            int index = (rand() % size);
            while (subHadPrize[IDQuery[index]] == 1 || isTicketHadAPrize[index] == true){   // loop till we have a ticket from a player who hasnt win any prize in the category, and the ticket didnt record any win.
                index = (rand() % size);
            }
            isTicketHadAPrize[index] = true;
            subHadPrize[IDQuery[index]]=1;
            count++;
            string stringID = to_string(index+1);
            while (stringID.length() < 3) stringID = '0' + stringID; 
            cout << "                  |" << setw(2) << count << "|" << setw(4) << "|" <<  stringID  << "|" << setw(4) << "|" << setw(25) << IDQuery[index]  << "|" "\n";  
        }
        cout << "                 ==================================================================================\n";
    }
}