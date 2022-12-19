; this is a commment 
VAL1      RN   R1
VAL2      RN   R2
VAL3      RN   R3
		
		
		AREA  Rn , CODE , READONLY 
        ENTRY
        EXPORT __main 
__main
     MOV  VAL1,#0x1234
     MOV  VAL2,#0x1234
     ADD  VAL3,VAL1,VAL2
    
STOP   B  STOP 
  
     END
