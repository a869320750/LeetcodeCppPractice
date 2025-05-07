#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>
using namespace std;



// 这里默认使用int，就先不写模板了
// 我的思路是，键盘上没有左右，他一定要按照顺序键入
class TypingDistance
{
public:
    int minDistance(char* keyboard, char* szWord) {
        unordered_map<char,int> mp;
        int result = 0;
        char lastc = szWord[0];
        for (int i = 0; i < strlen(keyboard); i++)
        {
            mp[keyboard[i]] = i;
        }

        for (int i = 1; i < strlen(szWord); i++) // 第一个输入的字母不算，只保留具体是哪个
        {
            int temp = abs(mp[szWord[i]] - mp[lastc]);
            result += temp;
            lastc = szWord[i];
        }

        return result;
    }
};

// 这里就默认只会敲键盘上的字符了

int main()
{
    TypingDistance td;

    // 测试用例1
    char *a = (char *)"qwertyuiop";
    char *b = (char *)"yourtry";
    cout << td.minDistance(a, b) << endl;

    a = (char *)"asdfghjkl";
    b = (char *)"glhf";
    // 测试用例2
    cout << td.minDistance(a, b) << endl;

    a = (char *)"asdfghjkl";
    b = (char *)"adg";
    // 测试用例3
    cout << td.minDistance(a, b) << endl;

    a = (char *)"asdfghjkl";
    b = (char *)"adgda";
    // 测试用例4
    cout << td.minDistance(a, b) << endl;

    a = (char *)"asdfghjkl";
    b = (char *)"asa";
    // 测试用例5
    cout << td.minDistance(a, b) << endl;
}