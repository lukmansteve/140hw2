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
if(
1
==
1
)
{
int 
x_a
=8888;
printf(
"%d\n", 
1111
);
if(
1
<
2
)
{
printf(
"%d\n", 
x_a
);
}
printf(
"%d\n", 
3333
);
}
printf(
"%d\n", 
4444
);
}
