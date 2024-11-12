t0 := x + y
t1 := t0
t2 := t1 / 2
a := t2
t3 := b + 1
t4 := t3
t5 := t4 < 3
if_false t4 < 3 goto L102
t6 := i - 1
i := t6
goto L102
L101:
t7 := i + 1
i := t7
L102:
t8 := a == 3
L103:
if_false a == 3 goto L104
t9 := a + 1
a := t9
t10 := b - 1
b := t10
goto L103
L104:
