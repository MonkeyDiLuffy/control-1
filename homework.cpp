//���˼·�����޸�һ��S��ʹ�ù����Ϊ���״ﵽȻ���ո�Ϊ�򵥵Ĺ����ж�
//��Ȼ*�ű�ʾ0����������ô���԰�����*�ҳ���֮�󣬼���ȫ����ʾ0���ٰ�S�ж������ĸĨ��
//�����Ļ��޸ĺ��S��P�����޸�Ϊ��*�ű�ʾ����ǰһ����ĸ����.����ʾ������ĸ��P��S��ͬ���TRUE
#include<stdlib.h>
#include<stdio.h>
int isMatch(char * s,char * p) {//����s��p�����Ϲ��򷵻�0���򷵻�1    (�ı���p��s��ֵ����Ϊ����Ҫ�����p��s)
char *pin_s = (char *) malloc(1000 * sizeof(char));//�����ڴ�
char *pin_p = (char *) malloc(1000 * sizeof(char));
pin_s = s;
pin_p = p;
int i_a;
for(i_a = 0; i_a < 1000; i_a++) {//��ѭ��Ŀ��������*
switch(p[i_a]) {
case '*' :
int i_b;
for(i_b = 997; i_b >= i_a-1; i_b--) {//��ѭ��Ŀ���ǽ�*��ǰ�ߵ���ĸ����S��
if(s[i_b] <= 'z' && s[i_b] >= 'a') {
s[i_b+2]  = s[i_b]; 
}
}
s[i_a-1]=p[i_a-1];
s[i_a]=p[i_a-1];
while(s[i_a] == s[i_a+1]) {//��ѭ��Ŀ����ɾ��S���ظ������*�������ĸ
int i_d;
for(i_d = i_a; i_d < 1000; i_d++) {
s[i_d] = s[i_d+1];
}
}
default:
break;
}
}
int i;
for(i = 0; i < 500; i++) {  //ѭ��
head:
switch(p[i]) {
case '.' :
break;
case '*' :
p[i] = p[i-1];
goto head;
break;
default: 
if(s[i] != p[i]) {
return 0;
}
break;
}
}
return 1;
}
int main () {
printf(" please input s and p ");
char s[1000] = {0},p[1000] = {0};
scanf("%s",&s);
scanf("%s",&p);
if(isMatch(s,p) == 0){
printf(" false ");
}else {
printf(" true ");
}
return 0;
}
