    /** Zip Code Group Project 1.0
@author(s): Ezigbo Ugochukwu
@due date: February 21, 2022 */

#include <iostream> //Include the declaration of the iostream classes
#include <string> //Include to use string objects

using namespace std;

class BufferClass
{
    string stateID;
    string zipCode;
    string lon;
    string lat;

    public:
    
    void setStateID(string ID)
    {
        stateID = ID;
    }

    void setZipCode(string ZC)
    {
        zipCode = ZC;
    }

    void setLongitude(string longi)
    {
        lon = longi;
    }

    void setLatitude(string lati)
    {
        lat = lati;
    }

    string getStateID() const{
        return stateID;
    }

    string getZipCode() const{
        return zipCode;
    }

    string getLongitude() const{
        return lon;
    }

    string getLatitude() const{
        return lat;
    }

    void setdata(string z, string s, string l, string a);
    void putdata();
};

ostream& operator<<(std::ostream& out, const BufferClass& bufferclass)
{
    out << bufferclass.getStateID() << " " << bufferclass.getZipCode() << 
    " " << bufferclass.getLongitude() << " " << bufferclass.getLatitude();
    return out;
}

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