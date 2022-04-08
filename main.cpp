#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip> 
#include <cstring>


using namespace std;
char ch;

//length indicator +3 to include itself and the comma.
int findNextZipCode(int *lengthInd, int *current, string contents, char* char_array, string s) {
    *current = *current + *lengthInd;
    *lengthInd = (contents[*current]-'0')*10 + contents[*current+1] - '0' + 3; //Adds 3 to skip itself and comma
    for (int i = 0; i < 5; i++) {
        if (contents[*current+3+i] == char_array[i]) {
            if ((i==s.length()-1) && (contents[*current+3+i+1]==',')) {
                return true;
            }
        } 
        else { 
            return false;
        }
    }
    return false;
}

int main() {
    ifstream infile;
    infile.open("us_postal_codes.csv");
    string contents;
    
    contents.assign(istreambuf_iterator<char>(infile), istreambuf_iterator<char>());
    int current = 0;
    int lengthInd = (contents[0]-'0')*10 + contents[1]-'0' + 3; //Next indicator add 3 to skip itself and comma
    
    string s;
    cout << "Enter ZipCode: ";
    cin >> s;
    s = s.substr(2, s.length());
    
    
    int n = s.length();
    char char_array[n + 1];
    strcpy(char_array, s.c_str()); 
    bool flag = false;
    while(flag == false) {
        flag = findNextZipCode(&lengthInd, &current, contents, char_array, s);
        if (flag==true) {
            cout << "TRUE";
        }
    }
    if (flag==false) {
        cout << "FALSE";
    }
}