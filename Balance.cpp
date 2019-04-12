//Brandon Ruiz CWID:890130156
// Section 02
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

struct PERSON {
char Name[20];
float Balance;

};

double findN(fstream &inData);
PERSON *readData(int N);
void Display(PERSON P[],int N, fstream &inData);  
void FindRichest(PERSON P[], int N);  
void GetDeposit(PERSON P[], int N);
void Deposit(PERSON P[], int N, string custName, float depositamount);  
void NewCopy(fstream &inData, string myFile, PERSON P[], int N); 

void printmenu() {                          //provided.
cout << "Please enter a choice:" << endl;
cout << "1. Display records"<< endl;
cout << "2. Deposit funds"<< endl;
cout << "3. Find Highest Balance" << endl;
cout << "4. Update records" << endl;
cout << "5. Exit the program" << endl;

}

int main() {
int N = 0;

fstream inData;
N = findN(inData);

PERSON *P;
P = readData(N);

int choice; //provided.
    do {
        printmenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                // Act on display
                Display(P, N, inData);
                break;

            case 2:
                // Act on deposit
                GetDeposit(P, N);
                break;

            case 3:
                // Act highest balance
                FindRichest(P, N);
                break;

            case 4:
                // Act on update records
                NewCopy(inData, "data.txt", P, N);
                break;

            case 5:
                // Must call update records here before exiting the program
                NewCopy(inData, "data.txt", P, N);
                break;

            default:
                cout << "Invalid entry." << endl;
                break;
        }


   } 
while(choice != 5);
return 0;

}

double findN(fstream &inData) {
string line;
double N = 0;

inData.open("data.txt", ios::in);
if(!inData) {
cout << "The file does not exist." << endl;
return 0;

}

else {
cout << "The file opened successfully." << endl;
while(getline(inData, line)) {
N++;

}

cout << "The number of items in the file has been recorded." << endl;
}

inData.close();
return N;

}

PERSON *readData(int N) {
fstream inData;
inData.open("data.txt", ios::in);

PERSON *P;
P = new PERSON[N];
string FirstName;
string LastName;

for(int i = 0; i < N; i++) {
inData >> FirstName >> LastName;

if(FirstName.length() > 9 || LastName.length() > 10) {
FirstName.resize(9);
LastName.resize(10);

}

inData >> P[i].Balance;
strcpy(P[i].Name, (FirstName + " " + LastName).c_str());
}

inData.close();
return P;

}

void Display(PERSON P[], int N, fstream &inData) {
cout << "Name" << " Balance" << endl;

cout << "-------------------------------------" << endl;

for(int i = 0; i < N; i++) {
cout << P[i].Name << " " << P[i].Balance << endl;

}

}

void FindRichest(PERSON P[], int N) {
int max = 0; 

for(int i = 0; i < N; i++) {
if(P[max].Balance < P[i].Balance) 

max = i; 

}

cout << "The customer with the maximum balance is: "<< P[max].Name << endl;

}

void GetDeposit(PERSON P[], int N) {
cout << "Enter your name: ";
string custName;
//cin.ignore();
getline(cin, custName);

for(int i = 0; i < N; i++) {
if(strcmp(P[i].Name, custName.c_str()) == 0) {
cout << "Amount: " ;
float depositamount = 0;
cin >> depositamount;
//cin.ignore();
Deposit(P, N, custName, depositamount);
}

else if (strcmp(P[i].Name, custName.c_str()) == 1) {
cout << "Record is not found.";

}

}

}

void Deposit(PERSON P[], int N, string custName, float depositamount) { 

for(int i = 0; i < N; i++) {
if(strcmp(P[i].Name, custName.c_str()) == 0) {  
P[i].Balance += depositamount;
cout << "New Balance: " << endl;

}

}

}

void NewCopy(fstream &inData, string myFile, PERSON P[], int N) {
inData.open("data.txt", ios::out);

for(int i = 0; i < N; i++) {
inData << P[i].Name << " "<< P[i].Balance << endl;

}

cout << "Updated File!" << endl;
inData.close();

}
