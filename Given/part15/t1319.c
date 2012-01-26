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
x_a[(-1)*21+
bc("a", 3, 21, 25,
21
)
]
=
24
;
x_a[(-1)*21+
bc("a", 4, 21, 25,
22
)
]
=
21
;
x_a[(-1)*21+
bc("a", 5, 21, 25,
23
)
]
=
25
;
x_a[(-1)*21+
bc("a", 6, 21, 25,
24
)
]
=
22
;
x_a[(-1)*21+
bc("a", 7, 21, 25,
25
)
]
=
23
;
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
bc("a", 11, 21, 25,
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
x_a[(-1)*21+
bc("a", 16, 21, 25,
x_a[(-1)*21+
bc("a", 16, 21, 25,
x_b
)
]
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
x_a[(-1)*21+
bc("a", 21, 21, 25,
x_a[(-1)*21+
bc("a", 21, 21, 25,
x_a[(-1)*21+
bc("a", 21, 21, 25,
x_b
)
]
)
]
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
x_a[(-1)*21+
bc("a", 26, 21, 25,
x_a[(-1)*21+
bc("a", 26, 21, 25,
x_a[(-1)*21+
bc("a", 26, 21, 25,
x_a[(-1)*21+
bc("a", 26, 21, 25,
x_b
)
]
)
]
)
]
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
x_a[(-1)*21+
bc("a", 31, 21, 25,
x_a[(-1)*21+
bc("a", 31, 21, 25,
x_a[(-1)*21+
bc("a", 31, 21, 25,
x_a[(-1)*21+
bc("a", 31, 21, 25,
x_a[(-1)*21+
bc("a", 31, 21, 25,
x_b
)
]
)
]
)
]
)
]
)
]
);
}
}
