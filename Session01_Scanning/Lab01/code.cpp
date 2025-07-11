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
    while(getline(f,line))
    {
        if(line.find("#include") !=  string::npos)
        {
            size_t start = line.find('<');
            size_t end = line.find('>');

            string ans = line.substr(start+1, end-start-1);
            
            f2 << ans << '\n';
        }
    }
    f.close();
    f2.close();
    return 0;
}