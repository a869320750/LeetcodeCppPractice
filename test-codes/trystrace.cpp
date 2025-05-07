#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("nonexistent.txt");
    char buffer[100];
    file.read(buffer, 100);
    std::cout << buffer << std::endl;
    file.close();
    return 0;
}

/* 这是一段错误代码，使用下面命令查看输出
g++ trystrace.cpp -o trystrace
strace ./trystrace
ltrace ./trystrace

*/