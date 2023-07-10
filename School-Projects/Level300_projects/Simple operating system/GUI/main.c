int start(){
 char* vbuff = (char*) 0xA0000;
 char colr = 0x00;
 int i = 0;
 while(i < 320 * 200){
 *(vbuff + i) = colr;
 colr++;
 i++;
 }
 }
