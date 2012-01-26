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
x_b[10]
={4444, 4444, 4444, 4444, 4444, 4444, 4444, 4444, 4444, 4444, };
int 
x_k
=8888;
{
int 
x_x
;
int i;
for(i=10; i>=1; i--){
x_x = 
i;
{
x_a[(-1)*1+
bc("a", 4, 1, 10,
x_x
)
]
=
1000
-
x_x
;
}
}}
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
x_a[(-1)*1+
bc("a", 9, 1, 10,
5
)
]
=
100
;
}
}}
{
int 
x_x
;
int i;
for(i=10; i>=1; i--){
x_x = 
i;
{
x_b[(-1)*1+
bc("b", 13, 1, 10,
x_x
)
]
=
3000
-
x_x
;
}
}}
x_k
=
0
;
{
int 
x_x
;
int i;
for(i=1; i<=10; i++){
x_x = 
x_b[i-(1)];
{
x_k
=
x_k
+
1
;
x_b[(-1)*1+
bc("b", 20, 1, 10,
x_k
)
]
=
9000
-
x_k
;
printf(
"%d\n", 
x_x
);
}
}}
{
int 
x_x
;
int i;
for(i=1; i<=10; i++){
x_x = 
x_b[i-(1)];
{
printf(
"%d\n", 
x_x
);
}
}}
}
