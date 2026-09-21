#include <cassert>
#include <cstddef>
#include <cstdint>

uint64_t expand(uint64_t input, uint32_t scale) {
    uint64_t result = 0;
    uint32_t i = 0;
    while(i*scale < 64)
    {
        if(input & (1ULL << i))
        {
            result |= (1ULL << (i * scale));
        }
        i++;
    }

    return result;  
}

int main() {
    assert(expand(0b1111ull, 3) == 0b001001001001ull);
    assert(expand(0b0101ull, 2) == 0b00010001ull);

    assert(expand(0b1010ull, 1) == 0b1010ull);

    assert(expand(0ull, 5) == 0ull);

    assert(expand(0b1ull, 4) == 0b1ull);
    assert(expand(0b10ull, 4) == 0b10000ull);
    return 0;
}
