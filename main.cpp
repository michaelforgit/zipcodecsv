//each object in the array will be a single row in the csv
/** Zip Code Group Project 1.0
@author(s): Ezigbo Ugochukwu
@due date: February 21, 2022 */

#include <iostream> //Include the declaration of the iostream classes
#include <string> //Include to use string objects
#include <fstream>
#include <vector>
#include <sstream> // std::stringstream
#include "bufferClass.cpp"

using namespace std;
void ordering(BufferClass row[]);

int main() {
    int i=0;
    static BufferClass row[40934];  

    /* File pointer */
    fstream file;
  
    /* Open file */
    file.open("us_postal_codesWorking.csv", ios::in);
  
    int rowNum = 0;
    string str, line;

    /* while there are lines to get in the file */
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

        //sort alphabetically
        //sort in order of least lon, most lon, greatest lat, least lat
        //print into table
    }

    ordering(row);
}

void ordering(BufferClass row[]) {
    string STATENAMES[51] = {"AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "DC", "FL", "GA", "HI", "ID", "IL", "IN", "IA", "KS",
"KY", "LA", "ME", "MD", "MA", "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "OH",
"OK", "OR", "PA", "RI", "SC", "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY"};

    float min, max;
    int rowNum, lonlat;
    float lon[40000];
    float lat[40000];

    for(int stateNum=0; stateNum<51; stateNum++){
            //printing state names
            cout << STATENAMES[stateNum];
            lonlat = 0;
        for(rowNum=1; rowNum < 40934; rowNum++){
            if(row[rowNum].getStateID() == STATENAMES[stateNum]) {
                //recording all longitudes to one array (stops here?)
                lon[lonlat] = stof(row[rowNum].getLongitude());

                //recording all latitudes to one array
                lat[lonlat] = stof(row[rowNum].getLatitude());

                lonlat++;
            }
        }
        //finding Easternmost
        min = lon[0];
        for(int i = 0; i < lonlat; i++){
            if(lon[i] < min){
            min = lon[i];
            }
        }
        cout << min << " ";

        //finding Westernmost
        max = lon[0];
        for(int i = 0; i < lonlat; i++){
            if(lon[i] > max){
            max = lon[i];
            }
        }
        cout << max << " ";
        
        //finding Nothernmost
        max = lat[0];
        for(int i = 0; i < lonlat; i++){
            if(lat[i] > max){
            max = lat[i];
            }
        }
        cout << max << " ";

        //finding Southernmost
        min = lat[0];
        for(int i = 0; i < lonlat; i++){
            if(lat[i] < min){
            min = lat[i];
            }
        }
        cout << min << endl;
    }
}