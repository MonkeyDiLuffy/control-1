#include<iostream.h>
int isMatch(char * s,char * p) {//����s��p�����Ϲ��򷵻�0���򷵻�1    (����������p��ֵ����Ϊ����Ҫ�����p)
char *pin_s = new char[100];//�����ڴ�
char *pin_p = new char[100];
pin_s = s;
pin_p = p;
int i;
for(i = 0; i < 100; i++) {  //ѭ��
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
