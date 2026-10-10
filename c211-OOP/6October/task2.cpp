#include <iostream>
using namespace std;
class Rectangle {
    private:
        int hours;
        int minutes;
        int seconds;
    public:
        /*==========================================================
                  SETTER FUNCTIONS
        ==========================================================*/
        void setHour(int h){
            if (h >=0 && h <=23)
                hours = h;
            else
                hours = 0;

        }   
        void setMinute(int m){
            if (m >=0 && m <=59)
                minutes = m;

            else
            minutes = 0;
        }
        void setSecond(int s){
            if (s >=0 && s <=59)
                seconds = s;
            else
                seconds = 0;
        }
        void setTime(int h, int m, int s){
            if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
            hours = h;
            minutes = m;
            seconds = s;
        } else {
            cout << "Invalid time values!" << endl;
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
        }
        /*==========================================================
                  GETTER FUNCTIONS
        ==========================================================*/
        int getHour(){
            return hours;
        }
        int getMinute(){
            return minutes;
        }
        int getSecond(){
            return seconds;
        }  
        // Increment in seconds.....
        void incSec(int s = 1){
            seconds +=s;

            // Handle roll-over if seconds exceed 59
            if (seconds >= 60) {
                int extraMinutes = seconds / 60;
                seconds = seconds % 60;
            
                // Increment minutes and handle cascade roll-overs if needed
                minutes += extraMinutes;
            if (minutes >= 60) {
                int extraHours = minutes / 60;
                minutes = minutes % 60;
                
                hours = (hours + extraHours) % 24; // 24-hour format wrap-around
            }
        }
    }
    void printTwelveHourFormat(){
        int twelveHourFormat = hours %12;
        if (twelveHourFormat == 0) {
            twelveHourFormat = 12; // Handle midnight and noon and convert 0 to 12 for 12-hour format
        }
        char period = (hours >= 12) ? 'P' : 'A'; 
        cout<<twelveHourFormat<<"h:"<<minutes<<"m:"<<seconds<<"s "<<period<<"M"<<endl;
    }
    void twentyFourHourFormat(){
        cout<<hours<<"h:"<<minutes<<"m:"<<seconds<<"s"<<endl;
    }
    void incMin(int m = 1){
        minutes += m;

        // Handle roll-over if minutes exceed 59
        if (minutes >= 60) {
            int extraHours = minutes / 60;
            minutes = minutes % 60;
            
            hours = (hours + extraHours) % 24; // 24-hour format wrap-around
        }
    }
    void incHour(int h = 1){
        hours = (hours + h) % 24;
    }

    
};
int main(){
    Rectangle time;
    time.setTime(23,59,59);
    time.incSec(-1); // this doesnt increment the seconds but also it can negate the seconds which is good but not suitable for function name...
    time.printTwelveHourFormat();
    time.twentyFourHourFormat();
    return 0;
}