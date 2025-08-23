#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream f("input.txt");
    ofstream f2("input1.txt");

    if(!f.is_open())
    {
        cout<< "file can not be opened\n";
        return 0; 
    }
    int ok = 0;
    char c;
    string s = "";
    while(f.get(c))
    {
        if(c == '[') ok = 1;
        if(ok)
        {
            s += c;
            if(c == ']') ok = 0;
        }
        else{
            // cout << s << '\n';
            if(s[0] == '[' && s[1] == 'i' && s[2] == 'd')
            {
                s[3] = '_';
            }
            else{
                size_t space_idx = s.find(' ');
                s.erase(s.begin() + 1, s.begin() + space_idx + 1);
            }
            f2 << s << ' ';
            s = "";
        }
    }
    return 0;
}