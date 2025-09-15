/*
Remember _Find_first() and _Find_next() ex- ist, and run in O(N/W), where W is word size of machine.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    bitset<8> b(10);
    cout << b.to_string() << '\n';

    bitset<8> c("101");
    cout << c.to_ullong() << '\n';

    bitset<8> d = b | c;
    d.flip(0);
    d.count();
}