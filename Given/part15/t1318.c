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
x_a[5]
={4444, 4444, 4444, 4444, 4444, };
int 
x_b
=8888;
int 
x_k
=8888;
for(
x_b
=
21
;
x_b
<=
24
;
x_b
++)
{
x_a[(-1)*21+
bc("a", 4, 21, 25,
x_b
)
]
=
1001
+
x_b
;
}
x_a[(-1)*21+
bc("a", 6, 21, 25,
25
)
]
=
1000
+
21
;
for(
x_b
=
21
;
x_b
<=
25
;
x_b
++)
{
printf(
"%d\n", 
x_a[(-1)*21+
bc("a", 9, 21, 25,
x_b
)
]
);
}
for(
x_k
=
1
;
x_k
<=
11
;
x_k
++)
{
int 
x_t
=8888;
x_t
=
x_a[(-1)*21+
bc("a", 15, 21, 25,
21
)
]
;
for(
x_b
=
21
;
x_b
<=
24
;
x_b
++)
{
x_a[(-1)*21+
bc("a", 17, 21, 25,
x_b
)
]
=
x_a[(-1)*21+
bc("a", 17, 21, 25,
x_b
+
1
)
]
;
}
x_a[(-1)*21+
bc("a", 19, 21, 25,
25
)
]
=
x_t
;
}
for(
x_b
=
21
;
x_b
<=
25
;
x_b
++)
{
printf(
"%d\n", 
x_a[(-1)*21+
bc("a", 23, 21, 25,
x_b
)
]
);
}
}
