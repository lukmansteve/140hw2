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
x_x
=8888;
x_x
=
9999
;
printf(
"%d\n", 
x_x
);
printf(
"%s\n", 
""
);
printf(
"%d\n", 
x_x
);
printf(
"%s\n", 
" space first and last "
);
}
