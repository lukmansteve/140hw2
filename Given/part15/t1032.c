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
x_a
=8888;
int 
x_b
=8888;
int 
x_ab
=8888;
int 
x_x
=
99
;
int 
x_z
=8888;
x_a
=
999
;
x_b
=
1888
;
printf(
"%d\n", 
x_a
+
x_b
+
x_x
);
}