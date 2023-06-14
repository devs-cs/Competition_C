#include <iostream>
#include <vector>
using  namespace std;

vector<int> topRow;
vector<int> bottomRow;
int count = 0;
int n;
bool  printOut = false;

void recur(vector<int> top, vector<int> bottom, int layer);
bool check(vector<int> topDirec, vector<int> bottomDirec);

int main()
{
    cout << "Your grid should be: _ by 2:" << endl;
    cin >> n;
    cout << "Print out full data on checked combinations (y/n)" << endl;
    char input;
    cin >> input;
    if(input == 'y'){
        printOut = true;
    cout << "I will  print out n x 2  grids that contain the movement patterns. 0  means left, 1 means right, 2 means up/down (depends on row). Invalid movements  may occur  (i.e. left most animal moving left), but those should never be followed by the word TRUE, which means it was a valid combination. Use code i to skip instructions next time instead of y"  << endl;    
    }

    if(input == 'i'){
        printOut =  true;
    }

    //ok so this is incredibly inefficient but who cares;
    //for each cell I will have the inhabitant pick a direction and then
    //we will see if that constitutes a valid combination of moves (no
    //two people overlap cells and no one leaves the boundaries)
    vector<int> direcTop (n, -1);
    vector<int> direcBottom (n, -1);

    recur(direcTop, direcBottom, 0);
    cout << "ANSWER IS " << count << endl;
}

void recur(vector<int> top, vector<int> bottom, int k)
{
    if (k == n)
    {
        if(check(top, bottom))
            count++;
        return;
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(k == 0 && (i == 0 || j == 0) || k == n-1 && (i == 1 || j == 1))
                continue;
            top[k] = i;
            bottom[k] = j;
            recur(top, bottom, k+1);
        }
    }
}
bool check(vector<int> topDirec, vector<int> bottomDirec)
{
    if(printOut){
        for(int i = 0; i < n; i++)
        {
            cout << topDirec[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++)
            cout << bottomDirec[i] << " ";
        cout << endl;
    }

    vector<bool> hitTop (n, false);
    vector<bool> hitBottom (n, false);
    for(int i = 0; i < n; i++) //0 left, 1 right, 2 up/down
    {
        if(topDirec[i] == 0 && i > 0)
            hitTop[i-1] = true;
        else if (topDirec[i] == 1 && i < n-1)
            hitTop[i+1] = true;
        else if (topDirec[i] == 2)
            hitBottom[i] = true;

        if(bottomDirec[i] == 0 && i > 0)
            hitBottom[i-1] = true;
        else if (bottomDirec[i] == 1 && i < n-1)
            hitBottom[i+1] = true;
        else if (bottomDirec[i] == 2)
            hitTop[i] = true;
    }

    for(int i = 0; i < n; i++)
    {
        if(hitTop[i] == false || hitBottom[i] == false)
        {
            if (printOut) cout << endl;
            return false;
        }
    }
    if(printOut)
    {
    cout  <<  "WORKS" << endl;
    cout << endl;
    }
    return true;

}