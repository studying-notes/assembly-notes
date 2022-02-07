         ;代码清单6-1
         ;文件名：c06_mbr.asm
         ;文件说明：硬盘主引导扇区代码
         ;创建日期：2011-4-12 22:12

         jmp near start

  mytext db 'L',0x07,'a',0x07,'b',0x07,'e',0x07,'l',0x07,' ',0x07,'o',0x07,\
            'f',0x07,'f',0x07,'s',0x07,'e',0x07,'t',0x07,':',0x07
  number db 0,0,0,0,0

  start:
         mov ax,0x7c0                  ;设置数据段基地址，该程序放入内存的段地址
         mov ds,ax

         mov ax,0xb800                 ;设置附加段基地址，显存映射起始地址
         mov es,ax

         cld  ;方向标志清零指令，以指示传送是正方向，低地址端到高地址端
         mov si,mytext      ;设置 SI 寄存器的内容到源串的首地址，即标号 mytext 处的汇编地址
         mov di,0    ;设置目的地的首地址到 DI 寄存器。第一个字符的位置为 0xB800 段的开始处，即偏移为 0
         mov cx,(number-mytext)/2      ;实际上等于 13，设置要批量传送的字节数到 CX 寄存器，除以 2 的原因是每个要显示的字符实际上占两字节
         rep movsw   ;重复执行 movsw 直到 CX 的内容为零

         ;得到标号所代表的偏移地址
         mov ax,number

         ;计算各个数位
         mov bx,ax
         mov cx,5                      ;循环次数
         mov si,10                     ;除数
  digit:
         xor dx,dx
         div si
         mov [bx],dl                   ;保存数位
         inc bx
         loop digit

         ;显示各个数位
         mov bx,number
         mov si,4
   show:
         mov al,[bx+si]
         add al,0x30
         mov ah,0x04
         mov [es:di],ax
         add di,2
         dec si
         jns show

         mov word [es:di],0x0744

         jmp near $  ;$标记等同于标号，转移到当前指令继续执行

  times 510-($-$$) db 0 ; $$标记代表当前汇编段的起始汇编地址，计算需要填充的字节数
                   db 0x55,0xaa