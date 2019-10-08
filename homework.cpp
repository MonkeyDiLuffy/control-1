//设计思路是先修改一下S，使得规则更为容易达到然后按照更为简单的规则判断
//既然*号表示0个或多个，那么可以把所有*找出来之后，假设全部表示0个再把S中多余的字母抹掉
//这样的话修改后的S与P规则修改为：*号表示复制前一个字母，“.”表示任意字母，P与S相同输出TRUE
#include<stdlib.h>
#include<stdio.h>
int isMatch(char * s,char * p) {//输入s和p若符合规则返回0否则返回1    (改变了p和s的值，因为不需要再输出p和s)
char *pin_s = (char *) malloc(1000 * sizeof(char));//分配内存
char *pin_p = (char *) malloc(1000 * sizeof(char));
pin_s = s;
pin_p = p;
int i_a;
for(i_a = 0; i_a < 1000; i_a++) {//此循环目的是搜索*
switch(p[i_a]) {
case '*' :
int i_b;
for(i_b = 997; i_b >= i_a-1; i_b--) {//此循环目的是将*号前边的字母插入S中
if(s[i_b] <= 'z' && s[i_b] >= 'a') {
s[i_b+2]  = s[i_b]; 
}
}
s[i_a-1]=p[i_a-1];
s[i_a]=p[i_a-1];
while(s[i_a] == s[i_a+1]) {//此循环目的是删除S中重复多余的*代表的字母
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
for(i = 0; i < 500; i++) {  //循环
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
