#ifndef ParkingPass_h
#define ParkingPass_h

#include <sstream>
#include <ctime>
#include <iostream>
using namespace std;

class ParkingPass
{
    
private:
    char parkingPassType;
    int parkingSpot= -1;
    string duration;
    string dateCreated; // format: MM/DD/YYYY
public:
    
    
    ParkingPass()
    {

    }
    
    char getParkingPassType()
    {
        return parkingPassType;
    }
    
    void setParkingPassType(char pass)
    {
        parkingPassType = pass;
    }
    
    int getParkingSpot()
    {
        return parkingSpot;
    }
    
    void setParkingSpot(int spotNumber)
    {
        parkingSpot = spotNumber;
    }
    
    string getDuration()
    {
        return duration;
    }
    void setDuration(string dur)
    {
        duration = dur;
    }    
    string getDateCreated()
    {
        return dateCreated;
    }    
	void setDateCreated(string date)
    {
        dateCreated = date;
    }
    
     
    //functions to do stuff manually (like passing parking pass data for testing purposes ;))
    void setParkingPassData(char parkingType)
    {
        setParkingPassType(parkingType);
    }
    
    void setParkingPassData(char parkingType, int parkingSpot)
    {
        setParkingPassType(parkingType);
        setParkingSpot(parkingSpot);
    }
    
    //"Advanced" functions (related to customer issues; valid passes//setting parking spot info;; typically
    //essentially ties into some higher level function in a "parent" class

    
    bool isItExpired()
    {
		time_t curentDate = time(0);
	
	    string sYear = dateCreated.substr(6, 4);
	    string sDay = dateCreated.substr(3, 2);
	    string sMonth = dateCreated.substr(0, 2);
	    
	    stringstream myYear(sYear);
	    int year;
	    myYear >> year;
	    
	    stringstream myDay(sDay);
	    int day;
	    myDay >> day;
	    
	    stringstream myMonth(sMonth);
	    int month;
	    myMonth >> month;
	    
	    tm mydate = {0,0,0,day,month-1,year-1900};
	    time_t myDate = mktime(&mydate);
	
		int difference = difftime(curentDate, myDate) / (60 * 60 * 24);
	    
	    if(parkingPassType == 'p' or parkingPassType == 'b')
	    {
	    	if(month == 1 or month == 3 or month == 5 or
			   month == 7 or month == 8 or month == 10 or
			   month == 12)
			{
			   	if(difference >= 31)
			   		return true;
			   	else
			   		return false;
			}
			if(month == 2)
			{
				if(year%4 == 0)
					if(difference >= 29)
			   			return true;
				   	else
				   		return false; 
				else
					if(difference >= 28)
			   			return true;
				   	else
				   		return false;
			}
		}
	    else if (parkingPassType == 'd' )
	    {
	    	if(difference >= 1)
		   		return true;
		   	else
		   		return false;
		}
		else
			cout<<" IsExpiredFunction: Invalid pass type"<<endl;
    }   
    void renewParkingPass()
    {
        //Reset deh clock
        //start = std::chrono::system_clock::now();
        
    }
};


#endif /* ParkingPass_h */
