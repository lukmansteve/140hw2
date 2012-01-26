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
x_e[2]
={4444, 4444, };
int 
x_c[3]
={4444, 4444, 4444, };
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
bc("a", 4, 1, 10,
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
bc("c", 8, -4, -2,
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
"forward x: a"
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
int 
x_a
=8888;
x_a
=
12
;
printf(
"%d\n", 
x_x
);
printf(
"%d\n", 
x_a
);
}
}}
printf(
"%s\n", 
"forward x: c"
);
{
int 
x_x
;
int i;
for(i=-4; i<=-2; i++){
x_x = 
x_c[i-(-4)];
{
int 
x_c[4]
={4444, 4444, 4444, 4444, };
printf(
"%d\n", 
x_x
);
printf(
"%d\n", 
x_c[(-1)*22+
bc("c", 23, 22, 25,
24
)
]
);
{
int 
x_x
;
int i;
for(i=22; i<=25; i++){
x_x = 
i;
{
x_c[(-1)*22+
bc("c", 25, 22, 25,
x_x
)
]
=
20000
+
x_x
;
}
}}
{
int 
x_x
;
int i;
for(i=22; i<=25; i++){
x_x = 
x_c[i-(22)];
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
}}
printf(
"%s\n", 
"bottom forward x: c"
);
{
int 
x_x
;
int i;
for(i=-4; i<=-2; i++){
x_x = 
x_c[i-(-4)];
{
int 
x_c[4]
={4444, 4444, 4444, 4444, };
printf(
"%d\n", 
x_x
);
printf(
"%d\n", 
x_c[(-1)*22+
bc("c", 37, 22, 25,
24
)
]
);
{
int 
x_y
;
int i;
for(i=22; i<=25; i++){
x_y = 
i;
{
x_c[(-1)*22+
bc("c", 39, 22, 25,
x_y
)
]
=
20000
+
x_y
;
}
}}
{
int 
x_y
;
int i;
for(i=22; i<=25; i++){
x_y = 
x_c[i-(22)];
{
printf(
"%d\n", 
x_y
);
{
int 
x_y
;
int i;
for(i=84; i<=85; i++){
x_y = 
i;
{
printf(
"%d\n", 
x_y
);
}
}}
}
}}
printf(
"%d\n", 
x_x
);
}
}}
}
