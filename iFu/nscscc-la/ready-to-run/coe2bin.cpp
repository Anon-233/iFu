#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    string base = argv[1];
    string coe = ".coe";
    string bin = ".bin";
    ofstream out((base + bin).c_str(), ios_base::out | ios  ::binary);
    ifstream in((base + coe).c_str(), ios_base::in);
    uint32_t x;
    string s;
    // memory_initialization_radix = 16;
    // memory_initialization_vector =
    in >> s;
    in >> s;
    in >> s;
    in >> s;
    in >> s;
    // cout << s << endl;
    while (in >> hex >> x) out.write((char *)&x, 4);
    
    return 0;
}