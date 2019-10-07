#include<iostream.h>
int isMatch(char * s,char * p) {//输入s和p若符合规则返回0否则返回1    (按规则翻译了p的值，因为不需要再输出p)
char *pin_s = new char[100];//分配内存
char *pin_p = new char[100];
pin_s = s;
pin_p = p;
int i;
for(i = 0; i < 100; i++) {  //循环
head:
switch(p[i]) {
case '.' :
break;
case '*' :
p[i] = p[i-1];
goto head;
break;
default: {
if(s[i] != p[i]) {
return 0;
}
}
break;
}
}
return 1;
}
void main () {
cout << " please input s and p " << endl;
char s[100],p[100];
cin >> s >> p ;
int n;
if(isMatch(s,p) == 0){
cout << " false " << endl;
}else{
cout << " true " << endl;
}
}
