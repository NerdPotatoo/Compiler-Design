#include<bits/stdc++.h>
using namespace std;
bool kw(string str)
{
    if ((str== "if") || (str == "else") ||
        (str== "while") || (str == "do") ||
        (str== "break") ||  (str =="continue")
        || (str== "int") || (str =="double")
        || (str== "float") || (str == "return")
        || (str== "char") || (str == "case")
        || (str== "long") || (str =="short")
        || (str== "typedef") || (str == "switch")
        || (str== "unsigned") || (str == "void")
        || (str== "static") || (str == "struct")
        || (str== "sizeof") || (str == "long")
        || (str== "volatile") || (str == "typedef")
        || (str== "enum") || (str =="const")
        || (str == "union") || (str ==  "extern")
        || (str =="bool"))
        {
            return true;
        }
        else return false;
}
bool op(string s)
{
    if(s == "+" || s == "-" || s == "<" || s == ">" || s == "*" || s == "/" || s == "%" || s == "=" || s == "!" || s == "&" || s == "^" || s == ">=" || s == "<=" || s == "==" || s== "|" || s == "||" || s == "&&") return true;
    return false;
}
bool sep(string s)
{
    if(s=="\'" || s == ","|| s == "\"" || s== ";") return true;
    else return false;
}
bool par(string s)
{
    if(s=="(" || s == ")") return true;
    else return false;
}
bool id(string str)
{
if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' )
        {
            return false;
        }									
    int i,len = str.size();
    if (len == 1)
    {
        return true;
    }										
    else
    {
    for (i = 1 ; i < len ; i++)						
    {
        if (sep(to_string(str[0])) == true || op(to_string(str[0])) == true)
        {
            return false;
        }
    }
    }
    return true;
}
bool num(string s)
{
    int cnt = 0;
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9' && s[i]  != '.')
        {
            return false;
        }
        if(s[i] == '.') cnt++;
    }
    if(cnt>1) return false;

    return true;
}

int main()
{
    ifstream f("input.txt");
    ofstream f2("output.txt");


    if(!f.is_open())
    {
        cout << "File can't be opened\n";
        return 0;
    }
    string line, word;
    vector<string> errors;
    while(getline(f,line))
    {
        stringstream s(line);
        while(s>>word)
        {
            // cout << word << '\n';
            string lexem = "";
            for(int i = 0; i<word.size(); i++)
            {

                if(word[i] == '>')
                {
                    if(i<word.size()-1 && word[i+1] == '=')
                    {
                        lexem += " >= "; 
                        i++;
                    }
                    else{
                        lexem += " > ";
                    }
                    
                    continue;
                }
                if(word[i] == '=')
                {
                    if(i<word.size()-1 && word[i+1] == '=')
                    {
                        lexem += " == "; 
                        i++;
                    }
                    else{
                        lexem += " = ";
                    }
                    
                    continue;
                }
                if(word[i] == '<')
                {
                    if(i<word.size()-1 && word[i+1] == '=')
                    {
                        lexem += " <= ";
                        i++;
                    }
                    else{
                        lexem += " < ";
                    }
                    continue;
                }
                if(word[i] == ',' || word[i] == ';' || word[i] == '(' || word[i] == ')' || word[i] == '*' || word[i] == '/' || word[i] == '+' || word[i] == '-' || word[i] == '|' || word[i] == '&' || word[i] == '\'')
                {
                    lexem += " ";
                    lexem += word[i];
                    lexem += " ";
                    continue;
                }
                lexem += word[i];
            }
            // cout << sub << '\n';
            stringstream lex(lexem);
            while(lex>>word)
            {
                if(kw(word))
                {
                    f2 << "[kw " << word << "] ";
                }
                else if(op(word))
                {
                    f2 << "[op " << word << "] ";
                }
                
                else if(sep(word))
                {
                    f2 << "[sep " << word << "] ";
                }   
                else if(par(word))
                {
                    f2 << "[par " << word << "] ";
                }
                else if(num(word))
                {
                    f2 << "[num " << word << "] ";
                }
                else if(id(word))
                {
                    f2 << "[id " << word << "] ";
                }
                else{   
                    // cout << word << " is unknown\n";
                    // errors.push_back(word);
                    f2 << "[unkn " << word << "] ";
                }
            }
            
        }
    }
    f2 << '\n';
    for(auto s:errors)
    {
        //  cout << s << " is unknown\n";
    }
    f.close();
    f2.close();
    
}