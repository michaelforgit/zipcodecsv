/** Zip Code Group Project 1.0
@author(s): Ezigbo Ugochukwu, Kohl Ott, Michael O'Gorman, Andrew Doree, Romeo Mouk
@due date: February 21, 2022 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "bufferClass.cpp"

using namespace std;

int main() {
    static BufferClass row[40934];  

    fstream file;
  
    file.open("us_postal_codes2.csv", ios::in); /*!<Works with us_postal_codes and us_postal_codes2 */
    int i=0;  /*!<Variable to count what column it is currently on  */
    int rowNum = 0;  /*!<Counts what row it is currently on */
    string str, line;

    while (getline(file, line)) {

        stringstream tr(line);

        while(getline(tr, str, ',')) { 
            if (i==0) {
                row[rowNum].setZipCode(str);
            } else if (i == 2) {
                row[rowNum].setStateID(str);
            } else if (i == 4) {
                row[rowNum].setLatitude(str);
            } else if (i == 5) {
                row[rowNum].setLongitude(str);
                rowNum = rowNum + 1;
            }
            i++;
        }
        i=0;
    }
    ordering(row); //Runs the "ordering" function from bufferClass
}