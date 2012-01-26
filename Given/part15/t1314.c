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
x_a[10]
={4444, 4444, 4444, 4444, 4444, 4444, 4444, 4444, 4444, 4444, };
int 
x_k
=8888;
for(
x_k
=
1
;
x_k
<=
10
;
x_k
++)
{
x_a[(-1)*1+
bc("a", 5, 1, 10,
x_k
)
]
=
100
-
x_k
;
}
for(
x_k
=
1
;
x_k
<=
10
;
x_k
++)
{
printf(
"%d\n", 
x_a[(-1)*1+
bc("a", 8, 1, 10,
x_k
)
]
);
}
}
