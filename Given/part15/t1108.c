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
"here's a %s does it work for you?"
);
printf(
"%d\n", 
123456
);
printf(
"%s\n", 
"here's a %d"
);
printf(
"%s\n", 
"are we having fun yet?"
);
printf(
"%s\n", 
"here's a kinda, kinda, kinda, kinda, kinda, kinda, kinda, kinda, kinda, kinda, kinda long string that is all on 1 line. does it work for you?"
);
}
