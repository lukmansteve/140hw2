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
printf(
"%s\n", 
"hi"
);
if(
3
>
4
)
{
printf(
"%s\n", 
"not okay"
);
}
else
{
printf(
"%s\n", 
"this works okay"
);
printf(
"%s\n", 
"really it does"
);
}
printf(
"%s\n", 
"bye, bye for now"
);
}