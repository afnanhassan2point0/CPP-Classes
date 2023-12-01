#include <iostream>
#include <string>
using namespace std;
class Clock
{
private:
    int minutes, seconds, hours;
    int addition;
    string dayNight;

public:
    Clock()
    {
        minutes = 0;
        seconds = 0;
        hours = 0;
    }
    void set()
    {
        cout << "\n Enter hours (1~24) : ";
        cin >> hours;
        cout << " Enter minutes (1~60) : ";
        cin >> minutes;
        cout << " Enter seconds (1~60) : ";
        cin >> seconds;
        cout << " Enter AM or PM : ";
        cin >> dayNight;
        cout << "\n Time Updated!\n";
    }
    void show()
    {
        if (hours >= 12)
            dayNight = "PM";
        else
            dayNight = "AM";
        cout << "\n " << hours << " : " << minutes << " :: " << seconds << " " << dayNight << endl;
    }
    void operator++(int)
    {
        if (minutes < 60)
            minutes++;
        else
        {
            minutes = 0;
            if (hours < 24)
                hours++;
            else
                hours = 1;
        }
        cout << "\n Time added! \n";
    }
    void operator--(int)
    {
        if (minutes > 0)
            minutes--;
        else
        {
            minutes = 60;
            if (hours > 0)
                hours--;
            else
            {
                hours = 23;
                dayNight = "PM";
            }
        }
    }
};
int main()
{
    char enter;
    Clock time;
    time.show();
repeat:
    cout << "\n 1. Show Time \n 2. Increase 1 minute \n 3. Decrease 1 minute \n 4. Set Time \n 0. Exit \n Enter choice : ";
    cin >> enter;
    if (enter == '0')
    {
        cout << "\n Program exited successfully!!\n\n";
        exit(0);
    }
    else if (enter == '1')
    {
        time.show();
        goto repeat;
    }
    else if (enter == '2')
    {
        time++;
        goto repeat;
    }
    else if (enter == '3')
    {
        time--;
        goto repeat;
    }
    else if (enter == '4')
    {
        time.set();
        time.show();
        goto repeat;
    }
    else
    {
        cout << "\n Invalid Input!!\n";
        goto repeat;
    }
    return 0;
}