#include <iostream>
#include <string>
using namespace std;
class Run
{
private:
    string name;
    float dist;
    static float distance;

public:
    void get()
    {
        cout << "Enter Player name : ";
        getline(cin, name);
        cout << "Enter distance travelled : ";
        cin >> dist;
        if (dist > distance)
            distance = dist;
    }
    void show()
    {
        cout << name << endl
             << dist << endl;
    }
    float Ldist()
    {
        return dist;
    }
    static float Mdistance()
    {
        return distance;
    }
};
float Run::distance = 0.0;
int main()
{
    Run player[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "\nEnter details for Player : " << i + 1 << " : \n";
        player[i].get();
        cin.ignore();
    }
    for (int i = 0; i < 3; i++)
    {
        if (player[i].Ldist() == Run::Mdistance())
            player[i].show();
    }
    return 0;
}