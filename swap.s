AREA SWAP,CODE,READONLY 
ENTRY
EXPORT main
  AREA SWAP,CODE, READONLY
                     ENTRY
                     EXPORT __main
         
                     LDR  R0 , =0xBABEFACE
                     LDR  R1  , =0xDEADBEEF
                     EOR R0, R0, R1
                    EOR R0, R0, R1
                     EOR R0, R0, R1
                     STOP
                     ALIGN
                      END
