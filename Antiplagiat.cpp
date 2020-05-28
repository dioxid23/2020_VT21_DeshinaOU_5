#include "Antiplagiat.h"

string Antiplag::adjective(string &word)
{
    string tword = word.substr(word.size()-3);
    if (tword == "ого" || tword == "его" || tword == "ому" || tword == "ему" || tword == "ыми" || tword == "ими")
        return word.erase(word.size()-3) + "ый";
    tword = word.substr(word.size()-2);
    if (tword == "ий" || tword == "ое" || tword == "ым" || tword == "им" || tword == "ом" || tword == "ем" ||
        tword == "ая" || tword == "яя" || tword == "ой" || tword == "ей" || tword == "ую" || tword == "юю" || tword == "ые" ||
        tword == "ие" || tword == "ых" || tword == "их")
        return word.erase(word.size()-2) + "ый";
}

string Antiplag::delete_ending(string &word)
{
    string tword = word.substr(word.size()-3);
    if (tword == "ешь" || tword == "ете" || tword == "ишь" || tword == "ите")
        return word.erase(word.size()-3);
    tword = word.substr(word.size()-2);
    if (tword == "ем" || tword == "им" || tword == "ет" || tword == "ут" || tword == "ют" || tword == "ит" || tword == "ат" ||
        tword == "ят")
        return word.erase(word.size()-2);
    tword = word.substr(word.size()-1);
    if (tword == "а" || tword == "е" || tword == "и" || tword == "о" || tword == "у" || tword == "ю" || tword == "я")
        return word.erase(word.size()-1);
}

vector<string> Antiplag::read_file(string fname)
{
    vector<string> ftext;
    ifstream file;
    file.open(fname);
    string str;
    while (!file.eof())
    {
        file >> str;
        ftext.push_back(str);
    }
    file.close();
    return ftext;
}

string Antiplag::get_word(string str, int &i)
{
    string tword;
    while(isspace(str[i]))
          i++;
    while (i<str.length()-1 && str[i]>' ')
    {
        tword[i]=str[i];
        i++;
    }
    tword[i]='\0';
    return tword;
}

vector<string> Antiplag::check_text(vector<string> vecint, string &intext)
{
    vector<string> restext;
    vector<string> outtext;
    string tword;
    int i = 0;
    while (i<intext.length()-1)
    {
        tword = get_word(intext, i);
        tword = adjective(tword);
        tword = delete_ending(tword);
        restext.push_back(tword);
    }
    if (vecint.size()>=3)
    {
        for (int i=0;i<vecint.size();i++)
        {
            vecint[i]=adjective(vecint[i]);
            vecint[i]=delete_ending(vecint[i]);
        }

        int j=0;
        while (j<restext.size())
        {
            int z=0;
            while(z<vecint.size())
            {
                if(vecint[z]==restext[j])
                    outtext.push_back(restext[j]);
                z++;
            }
            j++;
        }
    }
    return outtext;
}
