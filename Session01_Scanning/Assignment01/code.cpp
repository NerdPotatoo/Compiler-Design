#include<bits/stdc++.h>
using namespace std;
int main()
{

    ifstream f("input1.c");
    ofstream f2("output.txt");

    if(!f.is_open()){
        cout << "File can not be opened\n";
        return 0;
    }

    string l;
    int ok = 0;
    while(getline(f,l))
    {
        
        size_t flag1 = l.find("/*");
        size_t flag2 = l.find("*/");
        if(flag1 != string::npos) ok = 1;
        if(flag2 != string::npos) {
            ok = 0;
            continue;
        }
        if(ok) continue;
        
        size_t start = l.find("//");
        if(start != string::npos)
        {
            string l2 = l.substr(0, start);
            f2 << l2;
        }
        else{
            int flag = 0;
            for(char c : l)
            {
                if(c != ' ' && flag == 0)
                {
                    flag = 1;
                }

                if(flag) f2 << c;
            }
            // f2 << l;
        }
    }
    f.close();
    f2.close();
    return 0;
}