#include<bits/stdc++.h>
using namespace std;
class Symbol{
    public:
        int sl;
        string name = "";
        string idType = "";
        string dataType = "";
        string scope = "";
        string value = "";

        Symbol(int sl, string name, string dataType)
        {
            this->sl = sl;
            this->name = name;
            this->dataType = dataType;
        }
        void update(string value)
        {
            this->value = value;
        }      
};
vector<string> ss;
vector<Symbol> tt;
bool check(string dt)
{
    return (dt == "int" || dt == "char" || dt == "float" || dt == "long long" || dt == "double" || dt == "string" || dt == "bool");
}
bool checkID(int len, char c1, char c2, char c3)
{
    return (len>3 && (c1 == 'i' && c2 == 'd' && c3 == '_'));
}

void insert(int cnt, string name, string dt)
{
        Symbol obj(cnt,name,dt);

        if(cnt == 1) obj.scope = "global";
        tt.push_back(obj);
}
int search(string id)
{
    for(int i = tt.size()-1; i>=0 ; i--)
    {
        if(tt[i].name == id) return i;
    }
    return -1;
}
void display()
{

    cout << "Sl.\tname\tIdType\tDataType Scope\tvalue\n";
    for(auto x:tt)
    {
        cout << x.sl <<"\t" << x.name << "\t" <<x.idType << "\t" << x.dataType <<  "\t" << x.scope << "\t"<< x.value << '\n';
    }

     
}
int main()
{
    ifstream f("input1.txt");
    ofstream f2("output.txt");

    if(!f.is_open())
    {
        cout<< "file can not be opened\n";
        return 0; 
    }
    string line, tok;
    while(getline(f,line))
    {
        stringstream word(line);
        while(word >> tok)
        {
            tok.erase(tok.begin());
            tok.pop_back();
            // cout << tok << '\n';
            ss.push_back(tok);
        }
    }
    int count = 0, idx;
    for(int i = 0; i<ss.size(); i++)
    {
        // cout << ss[i] << ' ';
        if(checkID(ss[i].size(), ss[i][0] , ss[i][1] ,ss[i][2]))
        {
            ss[i].erase(ss[i].begin(), ss[i].begin()+3);
            // cout << ss[i] << ' ';
            if(check(ss[i-1]))
            {
                insert(++count,ss[i],ss[i-1]);

                // scope
                int flag = 0;
                for(int j = i-1; j>=0; j--)
                {
                    if(ss[j] == "}")
                    {
                        idx = search(ss[i]);
                        tt[idx].scope = "global";
                        flag = 1;
                        break;
                    }
                    else if(ss[j] == "{" || ss[j] == "("){
                        for(int k = j-1; k>=0; k--)
                        {
                            idx = search(ss[k]);
                            if(idx != -1 && tt[idx].idType == "func")
                            {
                                string type = tt[idx].name;
                                idx = search(ss[i]);
                                tt[idx].scope = type;
                                flag = 1;
                                break;
                            }
                        }
                        if(flag) break;
                    }
                }
                if(!flag){
                    idx = search(ss[i]);
                    tt[idx].scope = "global";
                } 


            }
            idx = search(ss[i]);
            if(ss[i+1] == "(")
            {
                tt[idx].idType = "func";
            }
            else{
                tt[idx].idType = "var";
            }

            if(ss[i+1] == "=")
            {
                if(ss[i+2][0] != 'i') tt[idx].update(ss[i+2]);
            }
            
        }
    }

   display();
}