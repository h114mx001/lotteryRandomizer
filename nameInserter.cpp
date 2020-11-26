#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    freopen("databaseTicket.csv","w",stdout);
    ifstream file;
    file.open("data.csv");
    string name;
    string times;
    int inttimes;
    vector <string> database;
    while (getline(file, name, ',')){
        getline(file, times);
        inttimes = stoi(times);
        for (int i = 1; i <= inttimes; i++){
            database.push_back(name);
        }
    }
    for (int i = 0; i < database.size(); i++){
        int r = i + rand() % (database.size() - i);
        swap(database[i], database[r]);
    }
    for (int i = 0; i < database.size(); i++){
        string stringID = to_string(i+1);
        while (stringID.length() < 3) stringID = '0' + stringID;
        cout << stringID << "," << database[i] << "\n";
    }
}
