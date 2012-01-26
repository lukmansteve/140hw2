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
"0000000001111111111222222222233333333334"
);
printf(
"%s\n", 
"1234567890123456789012345678901234567890"
);
}
