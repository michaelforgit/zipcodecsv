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
//us_postal_codes.csv
//us_postal_codes.txt
//us_postal_codes_ROWS_RANDOMIZED.csv
//row_random.txt
int main() {
    ifstream infile;
    infile.open("us_postal_codes.txt");
    string contents;
    
    contents.assign(istreambuf_iterator<char>(infile), istreambuf_iterator<char>());
    int current = 0;
    int lengthInd = (contents[0]-'0')*10 + contents[1]-'0' + 3; //Next indicator add 3 to skip itself and comma
    string s;
    cout << "Enter ZipCode: ";
    cin >> s;
    //s = s.substr(2, s.length());
    

    int n = s.length();
    char char_array[n + 1];
    strcpy(char_array, s.c_str()); 
    bool flag = false;
    //int test = (contents[0]-'0')*10+ contents[current+1] - '0' + 3;
    //findNextZipCode(&lengthInd, &current, contents, char_array, s);
    while(flag == false) {
        flag = findNextZipCode(&lengthInd, &current, contents, char_array, s);
    }
    if (flag==true) {
        int field = 0;
        cout << "ZIPCODE: ";
        for (int i = current+3; i < current+lengthInd; i++) {
            //remove +3 to include lenghtInd and write everything here to lenghtIndFile
            if (contents[i] == ',') {
                field++;
                switch (field)
                {
                case 1:
                    cout << " PLACENAME: ";
                    break;
                case 2:
                    cout << " STATE: ";
                    break;
                case 3:
                    cout << " COUNTY: ";
                    break;
                case 4:
                    cout << " LAT: ";
                    break;
                case 5:
                    cout <<" LONG: ";
                    break;
                default:
                    break;
                }
                continue;
            }
            cout << contents[i];
        }
    }
    if (flag==false) {
        cout << "FALSE";
    }
}