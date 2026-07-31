class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> B(n);
        for(int i=0; i<16; i++){
            B[i]=B[i]^B[31-i];
            B[31-i]=B[i]^B[31-i];
            B[i]=B[i]^B[31-i];
        }     
        return B.to_ulong();
    }
};