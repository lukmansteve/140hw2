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
x_i
=8888;
int 
x_j
=8888;
for(
x_i
=
1
;
x_i
<=
4
;
x_i
++)
{
printf(
"%d\n", 
x_i
);
}
x_i
=
77
*
100
+
44
;
printf(
"%d\n", 
x_i
);
for(
x_i
=
1
;
x_i
<=
3
;
x_i
++)
{
int 
x_k
=8888;
for(
x_k
=
444
;
x_k
<=
444
;
x_k
++)
{
printf(
"%d\n", 
x_k
);
