#ifndef __VM_H__
#define __VM_H__

#include <iostream>
#include <unordered_map>
#include <vector>

typedef std::vector<long long> byte;

using namespace std;

enum Registers : long long
{
    r0 = 1,r1,r2,r3,r4,r5,r6,r7,r8,r9
};


enum OPTYPES : long long
{
    CONST = 1, PRINT, MOV 
};

class VirtualM 
{
public:
    unordered_map<Registers, long long> registerValues;
    VirtualM(vector<long long> code);
    void RUN();
private:
    long long peek(long long rpos);
    bool match(long long check);

    long long pos = 0;
    vector<long long> code;
};

#endif 