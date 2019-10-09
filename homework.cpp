//设计思路是先修改一下S，使得规则更为容易达到然后按照更为简单的规则判断
//既然*号表示0个或多个，那么可以把所有*找出来之后，假设全部表示0个再把S中多余的字母抹掉
//这样的话修改后的S与P规则修改为：*号表示复制前一个字母，“.”表示任意字母，P与S相同输出TRUE
#include<stdlib.h>
#include <string.h>
#include<stdio.h>
bool isMatch(char * s, char * p){
char *pin_s = (char *) malloc(150 * sizeof(char));//分配内存
char *pin_p = (char *) malloc(150 * sizeof(char));
char *pin_S = (char *) malloc(150 * sizeof(char));
char S[100]={0};
int t ,f,g;
g=0;
int a;
pin_s = s;
pin_S =S;
pin_p = p;
t=strlen(s);
f=strlen(p);
int b;
for(a=0;a<t;a++)
{
S[a]=s[a];
}
int i_a;
int i_b;   
for(i_a = 0; i_a < f; i_a++) {//此循环目的是搜索*
switch(p[i_a]) {
case '*' :
g=g+1;
t=strlen(S);
for(i_b = t+1-2*g; i_b >= i_a+1-2*g; i_b--) {//此循环目的是将*号前边的字母插入S中
if(s[i_b] <= 'z' && s[i_b] >= 'a') 
{
S[i_b+2*g]  = s[i_b]; 
}
}
S[i_a-1]=p[i_a-1];
S[i_a]=p[i_a-1];
while(S[i_a] == S[i_a+1]) {//此循环目的是删除S中重复多余的*代表的字母
int i_d;
g=g-0.5;
t=strlen(S);
for(i_d = i_a; i_d < t; i_d++) 
{
S[i_d] =S[i_d+1];
}
}
default:
break;
}
}
int i;
t=strlen(S);
for(i = 0; i < t; i++) {  //循环
head:
switch(p[i]) {
case '.' :
break;
case '*' :
p[i] = p[i-1];
goto head;
break;
default: 
if(S[i] != p[i]) {
return false;
}
break;
}
}
return true;
}
int main () {
printf(" please input s and p ");
char s[100] = {0},p[100] = {0};
scanf("%s",&s);
scanf("%s",&p);
if(isMatch(s,p) == 0){
printf(" false ");
}else {
printf(" true ");
}
return 0;
}