#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream f1("input1.txt");
    ofstream f2("output.txt");
    ofstream f3("index.txt");

    if (!f1.is_open())
    {
        cout << "Error opening\n";
        return 0;
    }
    int i, st_line = 0, sz = 0;
    string l;
    stack<char> st;
    while (getline(f1, l))
    {
        i = l[0] - '0';
        int strt = 0, ed = 0;
        for (char c : l)
        {
            if (c == '{')
            {
                st.push('{');
            }
            if (c == '}')
            {
                if (st.size() == 0)
                {
                    f2 << "Misplaced '}' at line " << l[0] << "\n";
                }
                else
                    st.pop();
            }
            if (st.size() > sz)
            {
                sz = st.size();
                st_line = l[0] - '0';
            }


            // prob 1
            string word;
            stringstream ss(l);
            while(ss >> word)
            {
                if(word == "int" || word == "float" || word == "double")
                {
                    size_t m = l.find(word);
                    int ok  = 0;
                    for(int j = m; j<l.size(); j++)
                    {
                        if(l[j] == ' ')
                        {
                            ok ^= 1;
                        }
                    }
                }
            }   
                     
        }
       
    }
     if (st.size())
        {
            f2 << "Misplaced '{' at line " << st_line << "\n";
        }
        f1.close();
        f2.close();
}