a := 10
b := 20
t0 := a + b
c := R2
d := 110
t1 := c
c := R3
t2 := d / 1
d := R6
t3 := a
t4 := 2
L100:
if_false t4 != 1 goto L101 
t3 := t3 * a 
t4 := t4 - 1 
goto L100 
L101: 
e := R7
t5 := c > a
if_false c > a goto L103
t6 := c - b
c := R11
goto L104
L103:
t7 := a + b
c := R14
L104:
