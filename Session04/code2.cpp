#include <bits/stdc++.h>
using namespace std;

bool checkSemi(string l)
{
    for(int i = 1; i<l.size(); i++)
    {
        if(l[i] == l[i-1] && l[i] == ';') return true;
    }
    return false;
}
int main()
{
    ifstream f1("input1.txt");
    ofstream f2("output.txt");
    // ofstream f3("index.txt");

    if (!f1.is_open())
    {
        cout << "Error opening\n";
        return 0;
    }
    int i, st_line = 0, sz = 0;
    string l;
    
    stack<char> st;
    int count = 0;

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
        }
        // checked semicolon errors here
        if(checkSemi(l))
        {
            f2 << "misplaced \';\' at line " << l[0] << '\n';
        }

        // checked if else errors here
        for(int i = 0; i<l.size()-1; i++)
        {
            string s1 = l.substr(i,2);
            if(s1 == "if") count++;
        }
        for(int i = 0; i<l.size()-3; i++)
        {
            string s1 = l.substr(i,4);
            if(s1 == "else") {
                if(count <= 0) f2 << "Unmatched else at line " << l[0] << '\n';
                count--; 
            }
        }
        string word;
        stringstream ss(l);
        while(ss >> word)
        {
            if(word == "int" || word == "float" || word == "double")
            {
                size_t m = l.find(word);
                int ok  = 0;
                int j = m+word.size();
                cout << j << '\n';
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