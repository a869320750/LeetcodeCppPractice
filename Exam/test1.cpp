#include<iostream>
#include<cstring>
using namespace std;

bool CheckStringSymmetry(const char* pValue)
{
    // 使用双指针
    int left = 0;
    int right = strlen(pValue) - 1;
    while(right > left) {
        if (pValue[right] != pValue[left])
        {
            return false;
        }
        --right;
        ++left;
    }
    return true;
}

int main()
{
    cout << CheckStringSymmetry("aa") << endl;
    cout << CheckStringSymmetry("aba") << endl;
    cout << CheckStringSymmetry("abc") << endl;
    cout << CheckStringSymmetry("abccba") << endl;
    cout << CheckStringSymmetry("abcba") << endl;
    cout << CheckStringSymmetry("abcdefedcba") << endl;
    cout << CheckStringSymmetry("a") << endl;
    cout << CheckStringSymmetry("") << endl; // 这里默认空的也是对称的
}