#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

// 将 16 进制字符串转换成 ASCII 字符串
std::string hex_to_string(const std::string &hex) {
    std::string result;
    for (size_t i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);
        char byte = (char) strtol(byteString.c_str(), NULL, 16);
        result.push_back(byte);
    }
    return result;
}

int main() {
    // 16 进制字符串
    std::string hex_string = "2f2f20496620796f7527736520726561642074686973206661722c20796f75277265206120646576656c6f7065722077686f2062656c696576657320696e207468652070757273756974206f662074727574682e0a2f2f20496620796f752064697665206465656570657220696e746f207468652060736f757263652f636f6e74657874206265696f6e64207374646f75742c20796f75206d69676874207265616c697a653a0a2f2f2054686973207265706f7274206973206e6f74206f6e6c792061626f75742073797374656d732e0a2f2f205468652073797374656d206973206d6572656c792061207265666c656374696f6e206f662074686520776f726c64206f7574736964652e0a";
    
    // 调用转换函数
    std::string decoded_string = hex_to_string(hex_string);

    // 输出解码后的字符串
    std::cout << "Decoded string:\n" << decoded_string << std::endl;

    return 0;
}
