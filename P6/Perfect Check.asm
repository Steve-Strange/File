ori $1, $0, 144
ori $2, $0, 100
ori $3, $0, 68
ori $31, $0, 48
add $0,$3,$4
jal subtest1
nop
back1:
add $2,$3,$4
jal subtest2
nop
back2:
add $31,$0,$4
jal subtest3
nop
back3:
add $3,$31,$4
jal subtest4
nop
back4:
add $1,$0,$4
jal subtest5
nop
back5:
add $3,$2,$4
jal subtest6
nop
back6:
add $31,$31,$4
jal subtest7
nop
back7:
add $3,$0,$4
jal subtest8
nop
back8:
add $2,$0,$4
jal subtest9
nop
back9:
add $0,$2,$4
jal subtest10
nop
back10:
add $3,$0,$4
jal subtest11
nop
back11:
add $0,$31,$4
jal subtest12
nop
back12:
add $31,$1,$4
jal subtest13
nop
back13:
add $3,$31,$4
jal subtest14
nop
back14:
add $0,$1,$4
jal subtest15
nop
back15:

subtest1:
ori $2,$2,4
sub $3,$3,$3
lw $3,84($3)
ori $31,$0,80
ori $31,$0,20
add $1,$0,$1
ori $3,$31,48
beq $31,$2,endsubtest1
nop
ori $0,$1,100
sub $3,$3,$3
lw $1,52($3)
beq $0,$2,endsubtest1
nop
sub $3,$3,$3
sw $2,108($3)
add $31,$2,$1
ori $31,$3,84
sub $31,$31,$31
sub $2,$2,$2
lw $0,112($2)
endsubtest1:
la $ra, back1
jr $ra
nop


subtest2:
sub $3,$3,$3
sw $0,84($3)
ori $31,$3,52
sub $3,$3,$3
lw $1,72($3)
beq $1,$31,endsubtest2
nop
sub $1,$1,$1
lw $0,92($1)
sub $0,$0,$0
sw $0,112($0)
sub $0,$0,$0
sw $31,0($0)
sub $0,$1,$1
sub $2,$2,$2
lw $0,132($2)
sub $2,$2,$2
sw $31,40($2)
sub $1,$2,$0
sub $1,$1,$1
sw $2,92($1)
sub $3,$3,$3
sw $2,24($3)
endsubtest2:
la $ra, back2
jr $ra
nop


subtest3:
ori $31,$0,16
sub $3,$3,$3
lw $3,120($3)
beq $2,$2,endsubtest3
nop
sub $3,$3,$3
sw $1,84($3)
sub $2,$2,$2
sw $2,104($2)
beq $3,$2,endsubtest3
nop
sub $31,$2,$31
beq $1,$3,endsubtest3
nop
sub $1,$31,$0
ori $0,$31,72
sub $3,$0,$31
sub $0,$0,$0
sw $1,116($0)
sub $3,$3,$3
sw $31,44($3)
beq $2,$3,endsubtest3
nop
sub $3,$3,$3
lw $3,132($3)
endsubtest3:
la $ra, back3
jr $ra
nop


subtest4:
add $1,$31,$1
beq $1,$31,endsubtest4
nop
sub $1,$1,$1
lw $0,64($1)
beq $0,$1,endsubtest4
nop
add $2,$0,$0
sub $3,$3,$3
lw $2,148($3)
beq $3,$31,endsubtest4
nop
beq $0,$31,endsubtest4
nop
sub $2,$2,$2
sw $3,8($2)
sub $3,$3,$3
sw $1,120($3)
add $3,$0,$2
sub $31,$0,$31
add $2,$2,$1
sub $0,$0,$0
sw $31,36($0)
endsubtest4:
la $ra, back4
jr $ra
nop


subtest5:
sub $2,$2,$2
sw $1,128($2)
sub $3,$0,$3
sub $3,$3,$3
sw $0,156($3)
sub $3,$3,$3
lw $0,144($3)
add $1,$31,$1
sub $2,$2,$2
lw $1,72($2)
beq $3,$0,endsubtest5
nop
sub $2,$2,$2
lw $3,144($2)
sub $3,$3,$3
lw $0,140($3)
ori $1,$2,80
beq $31,$0,endsubtest5
nop
sub $1,$1,$1
sw $0,76($1)
ori $0,$0,36
sub $0,$0,$31
sub $3,$3,$3
sw $2,64($3)
endsubtest5:
la $ra, back5
jr $ra
nop


subtest6:
add $2,$31,$3
sub $2,$3,$2
ori $3,$0,16
beq $0,$0,endsubtest6
nop
ori $3,$2,92
sub $1,$1,$1
lw $3,64($1)
add $0,$2,$3
sub $1,$1,$1
sw $0,40($1)
add $0,$0,$0
sub $1,$1,$1
lw $3,56($1)
beq $0,$0,endsubtest6
nop
sub $1,$1,$1
sw $31,124($1)
sub $3,$3,$3
lw $1,128($3)
sub $31,$31,$3
endsubtest6:
la $ra, back6
jr $ra
nop


subtest7:
beq $1,$31,endsubtest7
nop
sub $3,$3,$3
sw $2,8($3)
add $0,$3,$2
add $1,$31,$2
sub $1,$1,$1
sw $1,68($1)
sub $3,$3,$3
sw $2,124($3)
sub $31,$31,$2
sub $2,$2,$2
lw $3,108($2)
ori $31,$3,132
beq $31,$0,endsubtest7
nop
beq $0,$0,endsubtest7
nop
add $0,$1,$1
sub $3,$3,$3
lw $1,48($3)
ori $0,$2,64
endsubtest7:
la $ra, back7
jr $ra
nop


subtest8:
sub $2,$2,$2
lw $3,148($2)
beq $2,$0,endsubtest8
nop
sub $3,$2,$3
sub $3,$1,$0
sub $3,$3,$3
sw $0,120($3)
sub $31,$3,$31
ori $0,$1,40
add $2,$3,$1
add $2,$31,$2
beq $1,$31,endsubtest8
nop
sub $3,$3,$3
sw $31,148($3)
sub $1,$1,$1
sw $0,20($1)
sub $31,$0,$31
ori $31,$2,8
sub $0,$2,$0
endsubtest8:
la $ra, back8
jr $ra
nop


subtest9:
beq $31,$0,endsubtest9
nop
sub $2,$2,$2
sw $0,12($2)
ori $3,$2,132
sub $1,$2,$31
sub $2,$2,$2
lw $0,8($2)
sub $3,$3,$3
lw $0,8($3)
ori $31,$1,16
beq $2,$0,endsubtest9
nop
sub $31,$1,$1
sub $1,$1,$1
sw $0,40($1)
beq $2,$1,endsubtest9
nop
sub $2,$2,$2
sw $2,140($2)
sub $0,$0,$0
lw $1,32($0)
sub $2,$2,$2
lw $1,64($2)
endsubtest9:
la $ra, back9
jr $ra
nop


subtest10:
sub $0,$0,$31
sub $3,$2,$0
sub $2,$2,$2
lw $2,64($2)
sub $3,$3,$3
sw $31,124($3)
add $0,$0,$1
beq $2,$0,endsubtest10
nop
sub $3,$3,$3
sw $1,120($3)
beq $31,$31,endsubtest10
nop
ori $0,$31,100
sub $1,$1,$1
sub $2,$0,$2
ori $3,$2,24
beq $2,$3,endsubtest10
nop
ori $31,$2,104
endsubtest10:
la $ra, back10
jr $ra
nop


subtest11:
sub $0,$3,$2
sub $1,$1,$1
sw $1,68($1)
beq $2,$2,endsubtest11
nop
ori $0,$2,80
beq $0,$31,endsubtest11
nop
add $1,$0,$0
sub $1,$1,$1
sw $0,152($1)
ori $2,$0,8
add $2,$1,$31
ori $0,$1,0
sub $0,$0,$0
lw $31,80($0)
ori $1,$0,112
ori $3,$1,96
sub $1,$3,$31
endsubtest11:
la $ra, back11
jr $ra
nop


subtest12:
ori $3,$31,60
beq $2,$0,endsubtest12
nop
add $31,$31,$31
sub $1,$31,$31
sub $3,$3,$3
lw $0,136($3)
sub $3,$3,$3
sw $0,4($3)
ori $1,$3,44
sub $2,$31,$31
sub $3,$3,$3
lw $0,124($3)
sub $0,$2,$31
beq $1,$3,endsubtest12
nop
ori $3,$1,108
sub $0,$0,$0
sw $31,52($0)
endsubtest12:
la $ra, back12
jr $ra
nop


subtest13:
sub $1,$1,$1
sw $0,4($1)
sub $3,$3,$3
sw $2,132($3)
add $2,$1,$0
add $31,$31,$31
sub $2,$2,$2
lw $3,156($2)
ori $1,$0,92
sub $2,$0,$31
sub $3,$3,$3
sw $2,112($3)
sub $3,$3,$3
lw $2,152($3)
sub $1,$1,$1
lw $3,100($1)
beq $3,$0,endsubtest13
nop
beq $31,$31,endsubtest13
nop
endsubtest13:
la $ra, back13
jr $ra
nop


subtest14:
add $1,$1,$0
add $31,$1,$1
ori $1,$2,88
add $1,$0,$2
sub $3,$3,$3
sw $1,136($3)
sub $3,$3,$3
sw $31,148($3)
sub $0,$0,$0
sw $2,100($0)
sub $2,$2,$2
sw $0,28($2)
sub $0,$0,$0
lw $31,112($0)
beq $31,$1,endsubtest14
nop
sub $1,$31,$31
sub $1,$1,$1
lw $1,124($1)
endsubtest14:
la $ra, back14
jr $ra
nop


subtest15:
beq $2,$3,endsubtest15
nop
sub $3,$3,$3
sw $1,116($3)
ori $0,$1,60
add $0,$1,$3
sub $3,$31,$1
sub $1,$1,$1
lw $0,136($1)
beq $1,$2,endsubtest15
nop
sub $1,$1,$1
lw $2,144($1)
beq $1,$0,endsubtest15
nop
sub $0,$0,$0
lw $3,124($0)
beq $3,$0,endsubtest15
nop
ori $1,$2,40
beq $2,$31,endsubtest15
nop
sub $31,$3,$0
endsubtest15:
la $ra, back15
jr $ra
nop