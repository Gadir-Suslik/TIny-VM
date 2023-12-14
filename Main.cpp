#include "VM.hpp"

int main()
{
    /*EXAMPLE */

    byte code = {
        CONST, r5, 75,
        PRINT, r5,
        MOV, r9, r5,
        PRINT, r5,


};  

    VirtualM VM(code);

    VM.RUN();

    return 0;
}