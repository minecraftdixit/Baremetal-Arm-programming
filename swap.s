AREA SWAP,CODE,READONLY 
ENTRY
EXPORT main[D[D[D[D__main
[A [A[A[C[C[C[C[C[C[C[C[C[C[A[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[AREA SWAP,CODE, READONLY
                     ENTRY
                     EXPORT __main
        __main
                     LDR  R0 , =0xBABEFACE
                     LDR  R1  , =0xDEADBEEF
                     EOR R0, R0, R1
                    EOR R0, R0, R1
                     EOR R0, R0, R1
[A[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[C[0[D[D[D[D[A[1[B[B[D[D[D[D[D[D[D[D[D[D[D[D[D[D[D[D[DSTOP
                     [AB   STOP
                     ALIGN
                      END
