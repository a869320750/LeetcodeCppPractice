#include<iostream>
#include<cstring>
#include<vector>
using namespace std;



// 这里默认使用int，就先不写模板了
class Stack
{
private:
    int count = 0;
    vector<int> data;
public:
    int Peek() {
        if (count > 0)
        {
            return data[count - 1];
        } else {
            return -1; // 或者事先定义的错误码
        }
    }

    int Pop() {
        if (count <= 0)
        {
            return -1; // 或者事先定义的错误码
        }
        else
        {
            int temp = count--;
            return data[temp - 1];
        }
        
    }

    void Push(int x) {
        if (count >= data.size())
        {
            data.push_back(x);
        } else {
            data[count - 1] = x;
        }
        ++count;
    }
};


int main()
{
    Stack st;
    st.Push(5);
    st.Push(4);
    st.Push(3);
    st.Push(2);
    st.Push(1);
    cout << st.Peek() << endl;
    cout << st.Pop() << endl;
    cout << st.Peek() << endl;
    cout << st.Pop() << endl;
    cout << st.Peek() << endl;
    cout << st.Pop() << endl;
    cout << st.Peek() << endl;
    cout << st.Pop() << endl;
    cout << st.Peek() << endl;
    cout << st.Pop() << endl;
    cout << st.Peek() << endl;
    cout << st.Pop() << endl;
}