#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
map <string,int> sourceHadPrizes;
int main(){
    srand(time(NULL));
    //create IDList;
    cout << "Installing data..." << "\n";
    ifstream file;
    file.open("databaseTicket.csv");
    string name;
    string number;
    vector <string> IDQuery;
    while (getline(file, number, ',')){
        getline(file, name, '\n');
        IDQuery.push_back(name);
    }
    file.close();
    //create map of member for checking
    ifstream file1;
    file1.open("data.csv");
    while(getline(file, name, ',')){
        getline(file,number);
        sourceHadPrizes[name] = 0;
    }
    cout << "Finish installing data!" << "\n";
   //Random giai
    cout << "                              __          __  __                 ______   ___   ___" << endl;
    cout << "                             / /   ____  / /_/ /____  _______  _<  /__ \\ /   | <  /" << endl;
    cout << "                            / /   / __ \\/ __/ __/ _ \\/ ___/ / / / /__/ // /| | / /"  << endl;
    cout << "                           / /___/ /_/ / /_/ /_/  __/ /  / /_/ / // __// ___ |/ /"   << endl;
    cout << "                          /_____/\\____/\\__/\\__/\\___/_/   \\__, /_//____/_/  |_/_/"    << endl;
    cout << "                                                        /____/                  "    << endl;
    #ifdef _WIN32
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    #endif
    // print in red and restore colors default
    cout << endl;
    std::cout << "\033[32m" << "+ -- --  += Author: Tuan Anh Nguyen | github: www.github.com/h114mx001                            =+  -- -- +" << "\033[0m" << std::endl;
    std::cout << "\033[32m" << "+ -- --  += Clone this repository: git clone https://github.com/h114mx001/lotteryRandomizer       =+  -- -- +" << "\033[0m" << std::endl;

    int size = IDQuery.size();
    bool isTicketHadAPrize[size]; 
    cout << "How many type of prizes you want to roll?: ";
    int numberOfPrizes;
    cin >> numberOfPrizes;
    for (int i = 1; i <= numberOfPrizes; i++){
        
        map <string,int> subHadPrize = sourceHadPrizes;
        string nameOfPrizes;
        cout << "Name of Prize: ";
        cin >> nameOfPrizes;
        cout << "How many prizes do you want?: ";
        int numOfPrizes = 0;
        cin >> numOfPrizes;
        cout << "======================================================================\n";
        cout << "CONGRATULATION! THESE LUCKY GUYS WIN THE " << nameOfPrizes << " PRIZE! \n";
        int count = 0;
        while (count < numOfPrizes){
            sleep(4);
            int index = (rand() % size);
            while (subHadPrize[IDQuery[index]] == 1 || isTicketHadAPrize[index] == true){
                index = (rand() % size);
            }
            isTicketHadAPrize[index] = true;
            subHadPrize[IDQuery[index]]=1;
            count++;
            string stringID = to_string(index+1);
            while (stringID.length() < 3) stringID = '0' + stringID; 
            cout << stringID << " " << IDQuery[index] << "\n";  
        }
        cout << "======================================================================\n";
    }
}