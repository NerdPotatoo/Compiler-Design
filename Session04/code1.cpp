#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream f1("input.txt");
    ofstream f2("input1.txt");


    if(!f1.is_open())
    {
        cout << "Error opening\n";
        return 0;
    }
    int i = 1;
    string l;
    while(getline(f1,l)){
        if(l[0] == '/') continue;
        else{
            f2 << i << " " << l << '\n';
            i++;
        }
    }

    f1.close();
    f2.close();
}