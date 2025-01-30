# Solución

```asm
@SCREEN
  D=A
  @R12
  AD=D+M
  M=-1
  AD=A+1
  @7
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  M=1
  AD=A+1
  @4
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  M=1
  AD=A+1
  @4
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  M=1
  AD=A+1
  @4
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  M=1
  AD=A+1
  @4
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  M=1
  AD=A+1
  @4
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  @3971
  D=D+A
  A=D-A
  M=A-D
  AD=A+1
  @5
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  @3971
  D=D+A
  A=D-A
  M=A-D
  AD=A+1
  @5
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  @24535
  D=D+A
  A=D-A
  M=A-D
  AD=A+1
  @4
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  @24535
  D=D+A
  A=D-A
  M=A-D
  AD=A+1
  @4
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  @24529
  D=D+A
  A=D-A
  M=A-D
  AD=A+1
  @7
  D=D+A
  A=D-A
  M=D-A
  
  D=A
  @31
  AD=D+A
  @24536
  D=D+A
  A=D-A
  M=A-D
  
  D=A
  @32
  AD=D+A
  @24536
  D=D+A
  A=D-A
  M=A-D
  
  D=A
  @32
  AD=D+A
  @24536
  D=D+A
  A=D-A
  M=A-D
  
  D=A
  @32
  AD=D+A
  @24536
  D=D+A
  A=D-A
  M=A-D
  
  D=A
  @32
  AD=D+A
  @24536
  D=D+A
  A=D-A
  M=A-D
  
  D=A
  @32
  AD=D+A
  @24536
  D=D+A
  A=D-A
  M=A-D
  
  D=A
  @32
  AD=D+A
  @20568
  D=D+A
  A=D-A
  M=A-D
  
  D=A
  @32
  AD=D+A
  @22360
  D=D+A
  A=D-A
  M=A-D
  
  D=A
  @32
  AD=D+A
  @1800
  D=D+A
  A=D-A
  M=A-D
  
  @R13
  A=M
  D;JMP
