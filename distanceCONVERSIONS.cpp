#include <iostream>
#include <string>
using namespace std;
class DB;
class DM
{
private:
    float m, cm;

public:
    DM()
    {
        m = cm = 0.0;
    }
    void input()
    {
        cout << "\nEnter distance : meters : ";
        cin >> m;
        cout << "Enter distance : centimeters : ";
        cin >> cm;
    }
    friend void add(DM, DB);
};
class DB
{
private:
    float f, i;

public:
    DB()
    {
        f = i = 0.0;
    }
    void input()
    {
        cout << "\nEnter distance : feets : ";
        cin >> f;
        cout << "Enter distance : inches : ";
        cin >> i;
    }
    friend void add(DM, DB);
};
void add(DM dm, DB db)
{
    float cm_i, m_f, centimeters, meters, feet, inches;
    cm_i = dm.cm + (db.i * 2.5);
    m_f = dm.m + (db.f * 3.281);
    centimeters = m_f * 100 + cm_i;
    meters = cm_i / 100 + m_f;
    feet = meters / 3.281;
    inches = centimeters / 2.5;
    cout << "\ncm : " << centimeters << "\nm : " << meters << endl;
    cout << "\nft : " << feet << "\nin : " << inches << endl;
}
int main()
{
    DM m;
    DB b;
    m.input();
    b.input();
    add(m, b);
    return 0;
}