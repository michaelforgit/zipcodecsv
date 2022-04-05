

STATENAMES = 
["AL", "AK", "AZ", "AR", "CA", "CO", "CT", "DE", "DC", "FL", "GA", "HI", "ID", "IL", "IN", "IA", "KS",
"KY", "LA", "ME", "MD", "MA", "MI", "MN", "MS", "MO", "MT", "NE", "NV", "NH", "NJ", "NM", "NY", "NC", "ND", "OH",
"OK", "OR", "PA", "RI", "SC", "SD", "TN", "TX", "UT", "VT", "VA", "WA", "WV", "WI", "WY"]

int findEast() {
    for loop through STATENAMES {
        int zip = 0;
        int easternMost = math.min;
        int s = 0;  //Iteration of statenames
        for arryOfObjects {
            int i = 0;
            if (arrayOfObjects[i].StateID == STATENAMES[s]) {
                if (arrayOfObjects[i].Lat < easternMost) {
                    easternMost = arrayOfObjects[i].Lat;
                    zip = arrayOfObjects[i].ZipCode;  //Stores the easternmost zip code.
                }
            }
            i = i + 1;
        }
        s = s + 1;
        EAST[s] = zip;  //Sets the easternmost zip code.
    }
}



int EAST[51];
int WEST[51];
int SOUTH[51];
int NORTH[51];
EAST = [421321, 4321]
WEST = [32132, 32132]
SOUTH = [321321, 32132]
NORTH = [1231, 321321]

STATENAMES[0], EAST[0], WEST[0], SOUTH[0], NORTH[0]

