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
int 
x_c[5]
={4444, 4444, 4444, 4444, 4444, };
x_a[(-1)*21+
bc("a", 3, 21, 25,
21
)
]
=
0
-
4
;
x_a[(-1)*21+
bc("a", 4, 21, 25,
22
)
]
=
0
-
1
;
x_a[(-1)*21+
bc("a", 5, 21, 25,
23
)
]
=
0
-
5
;
x_a[(-1)*21+
bc("a", 6, 21, 25,
24
)
]
=
0
-
2
;
x_a[(-1)*21+
bc("a", 7, 21, 25,
25
)
]
=
0
-
3
;
for(
x_k
=
0
-
5
;
x_k
<=
0
-
1
;
x_k
++)
{
x_c[(-1)*-5+
bc("c", 10, -5, -1,
x_k
)
]
=
x_k
*
111
;
}
printf(
"%d\n", 
0
-
111111
);
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
bc("a", 15, 21, 25,
x_b
)
]
);
}
printf(
"%d\n", 
0
-
111111
);
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
x_c[(-1)*-5+
bc("c", 20, -5, -1,
x_a[(-1)*21+
bc("a", 20, 21, 25,
x_b
)
]
)
]
);
}
}
