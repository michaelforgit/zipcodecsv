/** Zip Code Group Project 1.0
@author(s): Ezigbo Ugochukwu, Michael O'Gorman
@due date: February 21, 2022 */

#include <iostream> //Include the declaration of the iostream classes
#include <string> //Include to use string objects
#include <sstream>
#include <fstream>

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

    void setdata(string z, string s, string l, string a);
    void putdata();

    void pack(string s);

    void unpack();
};

void BufferClass::setdata(string z, string s, string l, string a)
{ 
    zipCode = z;
    stateID = s;
    lon = l;
    lat = a;
}

void BufferClass::putdata()
{
 cout << stateID << " " << zipCode << " " << lat << " " << lon;
}

//Example input:  1031,Gilbertville,MA,Worcester,42.3322,-72.1986
void BufferClass::pack(string s) {
    int i = 0;
    string str;
    stringstream tr(s);
    while(getline(tr, str, ',')) { 
        if (i==0) {
            setZipCode(str);
        } else if (i == 2) {
            setStateID(str);
        } else if (i == 4) {
            setLatitude(str);
        } else if (i == 5) {
            setLongitude(str);
        }
        i++;
    }
}  

void BufferClass::unpack() {
    //cout << lat << " " << stateID << "\n";
    cout << zipCode << " " << stateID << " " << lat << " " << lon;
}