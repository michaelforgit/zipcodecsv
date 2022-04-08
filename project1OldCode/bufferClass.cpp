/** 
* @brief Zip Code Group Project 1.0
* @authors: Ezigbo Ugochukwu, Kohl Ott, Michael O'Gorman, Andrew Doree, Romeo Mouk
* @due: February 21, 2022 
*/

#include <iostream> //Include the declaration of the iostream classes
#include <string> //Include to use string objects
#include <iomanip> //For setFill and setw

using namespace std;

class BufferClass
{
    string stateID;
    string zipCode;
    string lon;
    string lat;

    public:
    /** 
     * @brief setStateID
     * Sets the State ID.
     * @pre ID needs to be string.
     * @post Sets the state ID equal to the argument.
     */
    void setStateID(string ID)
    {
        stateID = ID;
    }

    /** 
     * @brief setZipCode
     * Sets the Zip Code. 
     * @pre ZC needs to be string
     * @post Sets the zipCode equal to the argument.
     */
    void setZipCode(string ZC)
    {
        zipCode = ZC;
    }

    /**
     * @brief setLongitude
     * Sets the Longitude.
     * @pre longi needs to be string.
     * @post Sets the lonitude equal to the argument. 
     */
    void setLongitude(string longi)
    {
        lon = longi;
    }

    /**
     * @brief setLatitude
     * Sets the Latitude.
     * @pre lati needs to be string.
     * @post Sets the latitude equal to the argument. 
     */
    void setLatitude(string lati)
    {
        lat = lati;
    }

    /** 
    * @brief getStateID
    * Gets the State ID.
    * @pre   None
    * @post  Returns the state ID.
    */
    string getStateID() const{
        return stateID;
    }

    /**
     * @brief getZipCode
     * Gets the Zip Code.
     * @pre none
     * @post Returns the Zip Code.
     */
    string getZipCode() const{
        return zipCode;
    }

    /**
     * @brief getLongitude
     * Gets the Longitude.
     * @pre none
     * @post Returns the Longitude. 
     */
    string getLongitude() const{
        return lon;
    }

    /**
     * @brief getLatitude
     * Gets the Latitude.
     * @pre none
     * @post Returns the Latitude. 
     */
    string getLatitude() const{
        return lat;
    }
};


/**
 * @brief ordering
 * Outputs in a table the most Eastern, Western, Northern, and Southern zip codes.
 * @pre none
 * @post Returns nothing, outputs into console the table.
 */
void ordering(BufferClass row[]) {
    string STATENAMES[51] = {"AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "DC", "FL", "GA", "HI", "ID", "IL", "IN", "IA", "KS",
    "KY", "LA", "ME", "MD", "MA", "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "OH",
    "OK", "OR", "PA", "RI", "SC", "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY"};

    float zip;
    float min, max;
    int rowNum, lonlat = 0;
    float lon[40934];
    float lat[40934];
    float zipCodes[40934];

    cout << setfill(' ');
    cout << "State" << setw(20) << "Easternmost" << setw(20) << 
        "Westernmost" << setw(20) << "Northernmost" << setw(20) << "Southernmost" << endl;

    cout << setfill('-') << setw(90) << "-" << endl;

    for(int stateNum=0; stateNum<51; stateNum++){
            //printing state names
            lonlat = 0;
            cout << STATENAMES[stateNum] << " ";
        for(rowNum=1; rowNum < 40934; rowNum++){
            if(row[rowNum].getStateID() == STATENAMES[stateNum]) {
                //recording all longitudes to one array
                lon[lonlat] = stof(row[rowNum].getLongitude());

                //recording all latitudes to one array
                lat[lonlat] = stof(row[rowNum].getLatitude());

                //recording all zipcodes to one array
                zipCodes[lonlat] = stof(row[rowNum].getZipCode());

                lonlat++;
            }
        }

        max = lon[0];
        zip = zipCodes[0];
        for(int i = 0; i < lonlat; i++){  /*!<Finds Easternmost zip code*/
            if(lon[i] > max){
                max = lon[i];
                zip = zipCodes[i];
            }
        }
        cout << setfill(' ');
        cout << setw(19) << zip;

        min = lon[0];
        zip = zipCodes[0];
        for(int i = 0; i < lonlat; i++){  /*!<Finds Westernmost zip code*/
            if(lon[i] < min){
                min = lon[i];
                zip = zipCodes[i];
            }
        }
        cout << setw(20) << zip;
        
        max = lat[0];
        zip = zipCodes[0];
        for(int i = 0; i < lonlat; i++){  /*!<Finds Northernmost zip code*/
            if(lat[i] > max){
                max = lat[i];
                zip = zipCodes[i];
            }
        }
        cout << setw(19) << zip;

        min = lat[0];
        zip = zipCodes[0];
        for(int i = 0; i < lonlat; i++){  /*!<Finds southernmost zip code*/
            if(lat[i] < min){
                min = lat[i];
                zip = zipCodes[i];
            }
        }
        cout << setw(21) << zip << endl;      
    }
}
