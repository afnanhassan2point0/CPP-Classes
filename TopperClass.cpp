#include <iostream>
#include <string>
using namespace std;
class Exam
{
private:
    int rno;
    static int rol;
    float mrk;
    char name[40];

public:
    Exam()
    {
        rol++;
        rno = rol;
        mrk = 0.0;
    }
    void input()
    {
        cout << "Enter name : ";
        cin.ignore();
        gets(name);
        cout << "Enter marks : ";
        cin >> mrk;
    }
    void show()
    {
        cout << "The Topper is : \n";
        cout << name << endl
             << rno << endl
             << mrk << endl;
    }
    float marks()
    {
        return mrk;
    }
};
int Exam::rol = 0;
int main()
{
    int i, x, max;
    cout << "Enter no. of students : ";
    cin >> x;
    Exam s[x];
    for (i = 0; i < x; i++)
    {
        cout << "Enter data for student : " << i + 1 << endl;
        s[i].input();
    }
    max = 0;
    for (i = 1; i < x; i++)
    {
        if (s[i].marks() > s[max].marks())
            max = i;
    }
    s[max].show();
    return 0;
}