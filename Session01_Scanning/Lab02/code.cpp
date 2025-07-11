#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream f("input.c");
    ofstream f2("output.txt");

    if(!f.is_open()){
        cout << "File can not be opened\n";
        return 0;
    }
    string line;
    int i = 1;
    while(getline(f,line))
    {
        f2 << i << ":" << line << '\n';
        i++;
    }
    f.close();
    f2.close();
    return 0;
}