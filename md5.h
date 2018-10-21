#ifndef MD5_H
#define MD5_H

#include <vector>
#include <array>
#include <string>
#include <cinttypes>

class MD5 {

    public:
        MD5();
        ~MD5();
        void update(std::vector<std::uint8_t>& message);
        void update(std::string message);
        void clear(void);
        std::array<std::uint8_t, 0x10> digest();
        std::string hexdigest();
    private:
        bool delta = true;
        std::vector<std::uint8_t> plaintext;
        std::array<std::uint8_t, 0x10> ciphertext;

        std::array<std::uint8_t, 0x10> gethash();
        void compute();
        void pad(std::vector<uint8_t>& message);

        

};

#endif // MD5_H
