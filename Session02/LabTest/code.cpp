#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream f("input.c");
    ofstream f2("output.txt");

    if(!f.is_open())
    {
        cout << "File cant not be open\n";
        return 0;

    }

    int v = 0, i = 0;
    string l;
    while(getline(f,l))
    {
        size_t t = l.find("){");

        if(t != -1)
        {
            t = l.find("int");
            if(t!= -1) i++;
            t = l.find("void");
            if(t!=-1) v++;
        }
    }

    f2 << "Return Type  Count\n";
    f2 << "Integer      "<<i<<'\n';
    f2 << "Void         "<<v<<'\n';
    f.close();
    f2.close();
    return 0;
}