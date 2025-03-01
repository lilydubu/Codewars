// Given a number n, find the number of trailing zeros in its binary representation.

// If n = 0 -> 1 zero
// When we n & 1 -> checks if last bit is 1
// If last bit is not one, keep counting

unsigned trailing_zeroes(unsigned n) {
    int zeroes = 0;
    if(n == 0) zeroes = 1;
    while(n != 0){
      if((n & 1) == 1) break;
      zeroes++;
      n = n >> 1;
    }
    return zeroes;
}
