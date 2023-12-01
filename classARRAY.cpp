#include <iostream>
using namespace std;
class Array
{
private:
    int arr[10];

public:
    Array()
    {
        arr[0] = arr[1] = arr[2] = arr[3] = arr[4] = arr[5] = arr[6] = arr[7] = arr[8] = arr[9] = -1;
    }
    void show()
    {
        int i;
        for (i = 0; i < 10; i++)
        {
            cout << arr[i] << "  ";
        }
    }
    void input()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "Enter value : ";
            cin >> arr[i];
        }
        cout << endl;
    }
    bool operator==(Array sec)
    {
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] != sec.arr[i])
                return 0;
        }
        return 1;
    }
};
int main()
{
    Array a, b;
    a.show();
    cout << endl;
    b.show();
    cout << endl;
    a.input();
    cout << endl;
    b.input();
    if (a == b)
        cout << "\n Equals ! \n";
    else
        cout << "\n Not Equal ! \n";
    return 0;
}