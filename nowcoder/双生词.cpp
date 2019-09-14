#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> vecStr;
vector<bool> vecFlag;
int main()
{
    int N, T;
    cin >> T;
    string str;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        getline(cin, str);
        for (int j = 0; j < N; j++)
        {
            getline(cin, str);
            vecStr.push_back(str);
        }
        bool flag = false;
        for (int j = 0; j < N; j++)
        {
            string pStr = vecStr[j];
            pStr = pStr + pStr;
            string pStrR = pStr;
            reverse(pStrR.begin(), pStrR.end());
            for (int k = j + 1; k < N; k++)
            {
                if (vecStr[j].length() != vecStr[k].length())
                    continue;
                if (pStr.find(vecStr[k], 0) != string::npos || pStrR.find(vecStr[k], 0) != string::npos)
                {
                    flag = true;
                    break;
                }                   
            }

        }
        vecStr.clear();
        vecFlag.push_back(flag);


    }
    for (vector<bool>::iterator it = vecFlag.begin(); it != vecFlag.end(); it++)
    {
        if (*it)
            cout << "Yeah" << endl;
        else
            cout << "Sad" << endl;
    }

    return 0;
}
