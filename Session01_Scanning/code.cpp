#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream f("datafile1.c"); // reading a file
    ofstream f2("output.txt"); // Writing a file
    

    if(!f.is_open()){
        cout << "File can not be opened\n";
        return 0;
    }
    char ch;
    string ans = "";
    while(f.get(ch))
    {
        if(ch == '(' || ch == ')')
        {
            ans += ch;
            // f2.put(ch);
            f2 << ch;
        }
    }
    f.close();
    f2.close();
    cout << ans << '\n';

    return 0;
}