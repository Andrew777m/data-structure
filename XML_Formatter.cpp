// XML_Formatter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
string formate(string input) {
    string space = "";
    const string tab = "    ";
    string output;
    string names[1000];
    int index = 0,numofTabs=0;
    bool flag;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '<' && input[i + 1] == '/') {
            flag = false;
            output = output + "\n";
            string name;
            i+=2;
            for (int j = i; input[j] != '>'; j++) {
                name += input[j];
                i = j+1;
            }
            for (int j = 0; j < index; j++) {
                if (names[j] == name) {
                    space = "";
                    for (int k = 0; k < numofTabs - 1; k++) {
                        space += tab;
                    }
                    numofTabs--;
                    output += space + "</" + names[j] + ">";
                    names[j] = "";
                    break;
                }
            }
        }
        else if (input[i] == '<') {
            flag = false;
            output = output + "\n";
            ++i;
            for (int j = i; input[j] != '>'; j++) {
                names[index] = names[index] + input[j];
                i = j;
                
            }
            output += space+'<' + names[index] + ">";
            space = space + tab;
            numofTabs++;
            index++;
            i++;
        }
        else {
            if (!flag) {
                output = output + "\n" + space;
                flag = true;
            }
            output += input[i];
        }
    }
    return output;
}
int main()
{
    string input;
    getline(cin, input);
    input = formate(input);
    cout << input;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
