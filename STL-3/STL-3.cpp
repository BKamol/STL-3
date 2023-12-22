#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int task1(string filename)
{
    ifstream in(filename);

    set<int> s;
    int data;
    while (!in.eof())
    {
        in >> data;
        s.insert(data);
    }

    in.close();

    return s.size();
}

void task2(string filename)
{
    ifstream in(filename);

    set<string> s;
    string data;
    while (!in.eof())
    {
        in >> data;
        if (s.count(data))
            cout << "YES" << ' ';
        else
            cout << "NO" << ' ';
        s.insert(data);
    }
    cout << endl;
    in.close();
}

map<string, string> make_dictionary(string filename)
{
    ifstream in(filename);

    string key, value;
    map<string, string> dict;
    while (!in.eof())
    {
        in >> key >> value;
        dict[key] = value;
        dict[value] = key;
    }

    in.close();
    return dict;
}

void task4(string filename)
{
    ifstream in(filename);

    int n; in >> n;
    vector<string> names;

    string name, place;
    for (int i = 0; i < n; i++)
    {
        in >> name >> place;
        if (place == "top")
            names.insert(names.begin(), name);
        else
            names.push_back(name);
    }

    int m; in >> m;
    int index;
    for (int i = 0; i < m; i++)
    {
        in >> index;
        cout << names[index-1] << endl;
    }

    in.close();
}

int main()
{
    /*cout << task1("in1.txt") << endl;
    task2("in2.txt");*/

    map<string, string> dict = make_dictionary("in3.txt");
    cout << dict["light"] << ' ' << dict["dark"] << endl;

    task4("in4.txt");



}

