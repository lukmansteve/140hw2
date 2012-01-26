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
x_k
=8888;
int 
x_sum
=8888;
x_k
=
0
;
x_sum
=
0
;
do
{
x_k
=
x_k
+
1
;
x_sum
=
x_sum
+
x_k
;
}
while(!(
x_k
==
10
));
printf(
"%s\n", 
"sum is"
);
printf(
"%d\n", 
x_sum
);
}
