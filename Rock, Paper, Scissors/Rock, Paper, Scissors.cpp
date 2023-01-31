#include <iostream>
#include <ctime>
#include <cstring>
#include <algorithm>
using namespace std;

string toLowerChar(string wrong) {
    transform(wrong.begin(), wrong.end(), wrong.begin(), ::tolower);
    return wrong;
}

int main() {
    string s1;
    string randomstring;
    int userPoints = 0;
    int cpuPoints = 0;
    bool shouldContinue = true;



    while (shouldContinue) {
        userPoints = 0;
        cpuPoints = 0;

        while (cpuPoints < 3 && userPoints < 3) {
            srand(time(NULL));
            int randomnumber = rand() % 3 + 1;
            //Ascription string to value is possible by map too
            if (randomnumber == 1) {
                randomstring = "paper";
            }
            else if (randomnumber == 2) {
                randomstring = "rock";
            }
            else if (randomnumber == 3) {
                randomstring = "scissors";
            }

            cout << "Entry your move:" << endl;
            cin >> s1;
            string userChoice = toLowerChar(s1);

            cout << "User's move: " << userChoice << " vs CPU's move: " << randomstring << endl;
            if (userChoice != "paper" && userChoice != "rock" && userChoice != "scissors") {
                cout << "Entry the correct move" << endl;
                continue;
            }
            else if (userChoice == randomstring) {
                cout << "draw" << endl;
            }
            else if ((userChoice == "paper" && randomstring == "rock") || (userChoice == "rock" && randomstring == "scissors") || (userChoice == "scissors" && randomstring == "paper")) {
               userPoints++;
                                         }
            else {
                cpuPoints++;
                        }
            cout << "Current result User:  " << userPoints << " CPU: " << cpuPoints << endl;
        }
        while (true) {
            string SC;
            cout << "Do you want to continue? (Y/N)" << endl;
            cin >> SC;

            if (SC == "Y") {
                shouldContinue = true;
            }
            else if (SC == "N") {
                
                shouldContinue = false;
                break;
            }
            else {
                cout << "Entry correct answer" << endl;
                continue;


            }
        }

    }
    cout << "Result is: User:  " << userPoints << " CPU: " << cpuPoints << endl;
}