#include "VM.hpp"
typedef long long ll;


VirtualM::VirtualM(vector<long long> code)
{
    this->code = code;
    registerValues.insert({r0, 0});
    registerValues.insert({r1, 0});
    registerValues.insert({r2, 0});
    registerValues.insert({r3, 0});
    registerValues.insert({r4, 0});
    registerValues.insert({r5, 0});
    registerValues.insert({r6, 0});
    registerValues.insert({r7, 0});
    registerValues.insert({r8, 0});
    registerValues.insert({r9, 0});
}

void VirtualM::RUN()
{
    while (pos < code.size())
    {
        ll current = peek(0);

        if (match(CONST)) 
        {
            registerValues[Registers(peek(0))] = peek(1);
            pos += 2;
        }
        else if (match(MOV)) 
        {
            registerValues[Registers(peek(0))] = registerValues[Registers(peek(1))];
            pos += 2;
        }
        else if (match(PRINT))
        {
            cout << "RESULT: " << registerValues.at(Registers(peek(0))) << endl;
            pos++;
        }
        else 
        {
            cerr << "Unknown operator at pos : " << pos << endl;
            exit(EXIT_FAILURE);
        }
    }
}

long long VirtualM::peek(long long rpos)
{
    if (rpos + pos < code.size()) return code[rpos + pos];
    return -1;
} 

bool VirtualM::match(long long check)
{
    if (check != peek(0)) return false;
    pos++;
    return true;
}  
