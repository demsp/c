#include <dos.h>
#include <stdio.h>

union REGS inregs, outregs;
struct SREGS segregs;

void main(void);

void main(void) {

char _far *dir_name = "DIR";

// delete DIR. For the Deletion use
// function 0x3A intrrupt INT 21h.

        inregs.h.ah = 0x3a;
        segregs.ds = FP_SEG(dir_name);
        inregs.x.dx = FP_OFF(dir_name);
        intdosx(&inregs, &outregs, &segregs);

// if the transfer flag is set up after deletion,
// then output Error message

        if(outregs.x.cflag != 0) {
           printf( "Error deleting directory: %d",
           outregs.x.ax);

// Get extended information about the Error
// with function 0x59 interrupt INT 21h.

           inregs.h.ah = 0x59;
           inregs.x.bx = 0;

// Save REGs in STACk, i.e. the content 
// of REGS will change

        _asm {
              push ds
              push es
              push si
              push di
        }

        intdosx(&inregs, &outregs, &segregs);

        _asm {
               pop di
               pop si
               pop es
               pop ds
        }

// Output extended information about Error

        printf("\nExtended Error code:   %d"
               "\nClass of the Error:             %d"
               "\nIntended actions:  %d"
               "\nLocalithation of the Error:       %d",
               outregs.x.ax,
               outregs.h.bh,
               outregs.h.bl,
               outregs.h.ch);
        }
}
