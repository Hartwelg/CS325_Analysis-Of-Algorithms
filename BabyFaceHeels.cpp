#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void printArrays(vector<string>& babyFaces, vector<string>& heels)
{
    cout << "BabyFaces: ";
    for (vector<string>::iterator it = babyFaces.begin(); it != babyFaces.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Heels: ";
    for (vector<string>::iterator it = heels.begin(); it != heels.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char** argv)
{
    ifstream infile(argv[1]);

    int numWrestlers = 0, numMatches = 0;
    vector<string> wrestlers;
    vector<string> babyFaces;
    vector<string> heels;
    
    infile >> numWrestlers;

    int temp = 0;
    string name1 = "", name2 = "";
    while (infile >> name1)
    {
        wrestlers.push_back(name1);
        temp++;
        if (temp == numWrestlers)
        {
            break;
        }
    }

    infile >> numMatches;

    temp = 1;
    while (infile >> name1 >> name2)
    {
        //add the first two names to the beginning of babyfaces and heels
        if (temp == 1)
        {
            babyFaces.push_back(name1);
            heels.push_back(name2);
            temp++;
            continue;
        }

        //if both names in babyFaces
        if (find(babyFaces.begin(), babyFaces.end(), name1) != babyFaces.end() && find(babyFaces.begin(), babyFaces.end(), name2) != babyFaces.end())
        {
            cout << "impossible" << endl;
            return -1;
        }
        //if both names in heels
        if (find(heels.begin(), heels.end(), name1) != heels.end() && find(heels.begin(), heels.end(), name2) != heels.end())
        {
            cout << "impossible" << endl;
            return -1;
        }
        //if both names in neither group
        if (!(find(babyFaces.begin(), babyFaces.end(), name1) != babyFaces.end()) && !(find(heels.begin(), heels.end(), name1) != heels.end()) && !(find(babyFaces.begin(), babyFaces.end(), name2) != babyFaces.end()) && !(find(heels.begin(), heels.end(), name2) != heels.end()))
        {
            babyFaces.push_back(name1);
            heels.push_back(name2);
        }
        //if name1 is not in either group
        else if (!(find(babyFaces.begin(), babyFaces.end(), name1) != babyFaces.end()) && !(find(heels.begin(), heels.end(), name1) != heels.end()))
        {
            //if name2 is in babyFaces and not in heels, name1 goes to heels
            if (find(babyFaces.begin(), babyFaces.end(), name2) != babyFaces.end())
            {
                heels.push_back(name1);
            }
            //else if name2 is in heels and not in babyFaces, name1 goes to babyFaces
            else
            {
                babyFaces.push_back(name1);
            }
        }
        //if name2 is not in either group
        else if (!(find(babyFaces.begin(), babyFaces.end(), name2) != babyFaces.end()) && !(find(heels.begin(), heels.end(), name2) != heels.end()))
        {
            //if name1 is in babyFaces and not in heels, name2 goes to heels
            if(find(babyFaces.begin(), babyFaces.end(), name1) != babyFaces.end())
            {
                heels.push_back(name2);
            }
            //else if name1 is in heels and not in babyFaces, name2 goes to babyFaces
            else
            {
                babyFaces.push_back(name2);
            }
        }
        
        temp++;
        if (temp == numMatches + 1)
        {
            break;
        }
    }
    cout << "Yes possible" << endl;
    printArrays(babyFaces, heels);
    return 0;
}