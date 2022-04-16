#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iomanip> 
#include <cstring>
#include <utility>
#include <unordered_map>
#include "bufferClass.cpp"

using namespace std;
char ch;


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



//length indicator +3 to include itself and the comma.

//us_postal_codes.csv
//us_postal_codes.txt
//us_postal_codes_ROWS_RANDOMIZED.csv
//row_random.txt

    ifstream infile;
    infile.open("us_postal_codes.txt");
    string contents;
    
    contents.assign(istreambuf_iterator<char>(infile), istreambuf_iterator<char>());
    int current = 0;
    int lengthInd = 0;
    string s;

    int n = s.length();
    bool flag = false;

    string codes;
    cout << "Zipcodes: ";
    getline(cin,codes);

    istringstream iss(codes);
    string oneZip;

    vector<string> arrZips;
    vector<pair<int, string>> validZips;
    
    int line = 0;
    
    while(iss >> oneZip){
        if (oneZip.substr(0,2).compare("-Z") == 0) {
            arrZips.push_back(oneZip.substr(2));
        } else {
            cout << "Not a valid input. Try capitalizing the -Z";
            return 0;
        }
    }

//finding valid zips and making a vector
    for (int i = 0; i < arrZips.size(); i++) {
        char char_array[arrZips[i].length() + 1];
        strcpy(char_array, arrZips[i].c_str()); 
        while (flag == false) {
            flag = findNextZipCode(&lengthInd, &current, contents, char_array, arrZips[i]);
            line = line + 1;

        }
        if (flag==false) {
            cout << "FALSE";
        }
        if (flag==true) {
            validZips.push_back(make_pair(line, arrZips[i]));
            flag=false;
        }
        line = 0;
        lengthInd = 0;
        current = 0;
    }
    
//making primary key index file
    ofstream pkindex("primary_key_index.txt");
    for (auto const& x : validZips){
        pkindex << x.first << "," << x.second;
        pkindex << "\n";
    }

vector<BufferClass> zipObjects;
//packing
    for (int i = 0; i < validZips.size(); i++) {
        char char_array[validZips[i].second.length() + 1];
        strcpy(char_array, validZips[i].second.c_str()); 
        for (int j = 0; j < validZips[i].first; j++) {
            findNextZipCode(&lengthInd, &current, contents, char_array, validZips[i].second);
        }
        string record;
        record = contents.substr(current+3, lengthInd-3);
        BufferClass zipObject;
        zipObject.pack(record);
        zipObjects.push_back(zipObject);
        lengthInd = 0;
        current = 0;
    }

    for (int i = 0; i < zipObjects.size(); i++) {
        zipObjects[i].unpack();
    }
}



