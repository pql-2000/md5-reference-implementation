#include <cassert>
#include "md5.h"

void MD5::update(std::vector<std::uint8_t> &message)
{
    this->plaintext.insert(this->plaintext.end(), message.begin(), message.end()); 
    this->delta = true;    
}

void MD5::update(std::string message)
{
    std::vector<uint8_t> vec(message.begin(), message.end());
    this->update(vec);
}

void MD5::clear(void)
{
    this->plaintext.clear();
    this->delta = true;
}
std::string MD5::hexdigest()
{

    static const char table[] = {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
    };
    std::string hexdigest = "";

    for(std::uint8_t byte : this->digest())
    {
        hexdigest += std::string(1, table[(byte >> 4) & 15]) + std::string(1, table[byte & 15]);
    }

    return hexdigest;
}

std::array<std::uint8_t, 0x10> MD5::digest()
{
    if(this->delta == false)
    {
        return this->ciphertext;
    }
    this->compute();
    this->delta = false;
    return this->ciphertext;
}

void MD5::compute()
{
    std::uint32_t Aresult = 0x67452301;
    std::uint32_t Bresult = 0xefcdab89;
    std::uint32_t Cresult = 0x98badcfe;
    std::uint32_t Dresult = 0x10325476;
    static const std::array<std::uint32_t, 0x40> rads
    {    
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
    };
    static const std::array<std::uint8_t, 0x40> shifts
    {
        0x07, 0x0c, 0x11, 0x16, 0x07, 0x0c, 0x11, 0x16, 0x07, 0x0c, 0x11, 0x16, 0x07, 0x0c, 0x11, 0x16,
        0x05, 0x09, 0x0e, 0x14, 0x05, 0x09, 0x0e, 0x14, 0x05, 0x09, 0x0e, 0x14, 0x05, 0x09, 0x0e, 0x14,
        0x04, 0x0b, 0x10, 0x17, 0x04, 0x0b, 0x10, 0x17, 0x04, 0x0b, 0x10, 0x17, 0x04, 0x0b, 0x10, 0x17,
        0x06, 0x0a, 0x0f, 0x15, 0x06, 0x0a, 0x0f, 0x15, 0x06, 0x0a, 0x0f, 0x15, 0x06, 0x0a, 0x0f, 0x15
    };


    std::vector<uint8_t> plaintext = this->plaintext;

    /*
        Pad plaintext to nearest 512 bit length.
    */
    this->pad(plaintext);

    size_t n_chunks = plaintext.size() / 64;

    for(size_t current_chunk = 0; current_chunk < n_chunks; current_chunk++)
    {
        std::vector<std::uint8_t> chunk(plaintext.begin() + current_chunk*0x40, plaintext.begin() + (current_chunk+1)*0x40);
        std::array<std::uint32_t, 0x10> words;

        /*
            Split chunk up in 32 bit pieces for further operation.
        */
        for(int i = 0; i < 0x40; i += 0x04)
        {
            words[i / 4] = *((std::uint32_t*)&chunk[i]);
        }

        std::uint32_t A = Aresult, B = Bresult, C = Cresult, D = Dresult;

        for(int j = 0; j < 64; j++)
        {
            uint32_t f, g;
            if(j < 16)
            {
                /*
                    F(B, C, D) = (B ∧ C) ∨ (¬B ∧ D)
                */
                f = (B & C) | (~B & D);
                g = j;
            }

            else if(j < 32)
            {
                /*
                    G(B, C, D) = (B ∧ D) ∨ (C ∧ ¬D)
                */
                f = (D & B) | (C & ~D);
                g = (5*j + 1) % 16;
            }

            else if(j < 48)
            {
                /*
                    H(B, C, D) = B ⊕ C ⊕ D
                */
                f = B ^ C ^ D;
                g = (3*j + 5) % 16;
            }

            else if(j < 64)
            {
                /*
                    I(B, C, D) = C ⊕ (B ∨ ¬D)
                */
                f = C ^ (B | ~D);
                g = (7*j) % 16;
            }
            f = f + A + rads[j] + words[g];
            A = D;
            D = C;
            C = B;
            B += (f << shifts[j]) | (f >>(32-shifts[j]));
        }
        
        Aresult += A;
        Bresult += B;
        Cresult += C;
        Dresult += D;
    }

    /*
        Convert the 32 bit pieces to bytes again.
    */
    this->ciphertext[0] = ((uint8_t*) &Aresult)[0];
    this->ciphertext[1] = ((uint8_t*) &Aresult)[1];
    this->ciphertext[2] = ((uint8_t*) &Aresult)[2];
    this->ciphertext[3] = ((uint8_t*) &Aresult)[3];

    this->ciphertext[4] = ((uint8_t*) &Bresult)[0];
    this->ciphertext[5] = ((uint8_t*) &Bresult)[1];
    this->ciphertext[6] = ((uint8_t*) &Bresult)[2];
    this->ciphertext[7] = ((uint8_t*) &Bresult)[3];

    this->ciphertext[8] = ((uint8_t*) &Cresult)[0];
    this->ciphertext[9] = ((uint8_t*) &Cresult)[1];
    this->ciphertext[10] = ((uint8_t*)&Cresult)[2];
    this->ciphertext[11] = ((uint8_t*)&Cresult)[3];

    this->ciphertext[12] = ((uint8_t*)&Dresult)[0];
    this->ciphertext[13] = ((uint8_t*)&Dresult)[1];
    this->ciphertext[14] = ((uint8_t*)&Dresult)[2];
    this->ciphertext[15] = ((uint8_t*)&Dresult)[3];
}

void MD5::pad(std::vector<std::uint8_t>& message)
{

    /*
        First calculate the n amount of bytes to be appended, which is defined as
        the amount of bytes needed to make the total length (in bytes) divisible by 64.

        Then append n amount of bytes to the plaintext.
    */

    size_t old_length = message.size();
    size_t padding_size = 64 - old_length % 64;

    for(size_t i = 0; i < padding_size; ++i) 
        message.push_back(0);

    /*
        To be safe, check if padding was applied correctly, 
        and prevent possible edge case off-by-one bugs and similar.
    */
    assert(message.size() % 64 == 0);

    /*
        Set the MSB of the first padding byte to 1 to delimit the padding from the message. 
    */

    message[old_length] |= (1 << 7); 

    /*
        Set last 8 bytes to the length in bits of the original message. 
    */
    *((std::uint64_t*)&message[message.size() - 8]) = (std::uint64_t)(old_length * 8);
}

MD5::MD5() {}

MD5::~MD5() {}
