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
x_b
=8888;
int 
x_x
=8888;
int 
x_c[3]
={4444, 4444, 4444, };
x_x
=
12
;
for(
x_b
=
1
;
x_b
<=
10
;
x_b
++)
{
x_a[(-1)*1+
bc("a", 6, 1, 10,
x_b
)
]
=
100
+
x_b
;
}
for(
x_b
=
0
-
2
;
x_b
>=
0
-
4
;
x_b
--)
{
x_c[(-1)*-4+
bc("c", 10, -4, -2,
x_b
)
]
=
1000
-
x_b
;
}
printf(
"%s\n", 
"element forward x: a"
);
{
int 
x_x
;
int i;
for(i=1; i<=10; i++){
x_x = 
x_a[i-(1)];
{
printf(
"%d\n", 
x_x
);
}
}}
printf(
"%d\n", 
x_x
);
}
