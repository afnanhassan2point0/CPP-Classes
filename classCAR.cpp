#include <iostream>
#include <string>
using namespace std;
class Car
{
private:
    string name;
    float position;
    char direction;

public:
    Car()
    {
        name = "CiviC";
        position = 0.0;
        direction = 'E';
    }
    void input()
    {
        cout << "\n\t\t\tEnter the name of car : ";
        cin.ignore();
        getline(cin, name);
    repeat_direction:
        cout << "\t\t\tEnter its direction : E/W/N/S : ";
        cin >> direction;
        if (direction == 'E' || direction == 'W' || direction == 'N' || direction == 'S')
        {
        }
        else
        {
            cout << "\n\t\t\t Error : invalid direction !!\n";
            goto repeat_direction;
        }
        cout << "\t\t\tEnter the distance(km) it travelled from Homepoint : Position : ";
        cin >> position;
        cout << "\n\t\t\tAdded information successfully!!\n\n";
    }
    void turn()
    {
        if (direction == 'E')
            direction = 'S';
        else if (direction == 'S')
            direction = 'W';
        else if (direction == 'W')
            direction = 'N';
        else
            direction = 'E';
        cout << "\n\t\t\tTurned successfully!!\n";
        cout << endl;
    }
    void turn(char d)
    {
        direction = d;
        cout << "\n\t\t\tTurned successfully!!\n";
        cout << endl;
    }
    void display()
    {
        cout << "\n\t\t\tCar " << name << endl
             << "\t\t\tDirection " << direction << endl
             << "\t\t\tTravelled " << position << " KM from the Homepoint\n\n";
    }
    void move()
    {
        float tem;
        cout << "Enter the Position i.e the distance travelled : ";
        cin >> tem;
        position += tem;
        cout << endl;
    }
};
int main()
{
    char ch;
    Car motor;
repeat:
    cout << "1. Enter car details\n2. Move a distance\n3. Turn the car right side \n4. Change the direction of Car";
    cout << "\n5. Display Car\n0. Exit \nEnter an option to proceed with : ";
    cin >> ch;
    switch (ch)
    {
    case '0':
        cout << "\nProgram exited successfully!\n\n";
        exit(0);
        break;
    case '1':
        motor.input();
        goto repeat;
        break;
    case '2':
        motor.move();
        goto repeat;
        break;
    case '3':
        motor.turn();
        goto repeat;
        break;
    case '4':
    {
    again_direction:
        cout << "\n\t\t\tEnter its direction : E/W/N/S : ";
        cin >> ch;
        if (ch == 'E' || ch == 'W' || ch == 'N' || ch == 'S')
        {
            motor.turn(ch);
            goto repeat;
        }
        else
        {
            cout << "\n\t\t\t Error : invalid direction !!\n";
            goto again_direction;
        }
    }
    break;
    case '5':
        motor.display();
        goto repeat;
        break;

    default:
        cout << "\n\t\t\tError : invalid input !! \n";
        goto repeat;
        break;
    }
    return 0;
}