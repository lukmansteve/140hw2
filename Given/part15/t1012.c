#include <stdio.h>
#include <stdlib.h>
int bc(char s[], int lno, int lb, int ub, int exp) {
if (exp < lb || exp > ub) {
fprintf(stderr, "subscript (%d) out of bounds for array %s[%d:%d] on line %d\n", exp, s, lb, ub, lno);
exit(1);
} else {
return exp;
}}
main() 
{
int 
x_N
=
10
;
int 
x_i
=8888;
x_i
=
1
;
if(
x_i
!=
x_N
)
{
printf(
"%d\n", 
99
);
}
}