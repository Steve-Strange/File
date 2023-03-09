.macro get_int(%des)
	li $v0,5
	syscall
	move %des,$v0
.end_macro

.macro print_int(%src)
	push($a0)
	move $a0,%src
	li $v0,1
	syscall
	pop($a0)
.end_macro

.macro push(%src)
	sw %src,0($sp)
	subi $sp,$sp,4
.end_macro

.macro pop(%des)
	addi $sp,$sp,4
	lw %des,0($sp)	
.end_macro

.macro print_space
	push($a0)
	li $a0,' '
	li $v0,11
	syscall
	pop($a0)
.end_macro

.macro get_index(%ans,%i,%j,%column)
	mul %ans,%i,%column
	add %ans,%ans,%j
	sll %ans,%ans,2
.end_macro

.macro get_matrix(%des,%m,%n)
	push($t0)
	push($t1)
	push($t2)
	push($t3)
	li $t0,1
	for1:
	bgt $t0,%m,for1_end
		li $t1,1
		for2:
			bgt $t1,%n,for2_end
			get_index($t3,$t0,$t1,%n)
			get_int($t2)
			sw $t2,%des($t3)
			addi $t1,$t1,1
		j for2
		for2_end:
		addi $t0,$t0,1
	j for1
	for1_end:
	pop($t3)
	pop($t2)
	pop($t1)
	pop($t0)
.end_macro

.data
	map: .space 256
	book: .space 256

.text

li $s0,0	#m
li $s1,0	#n
li $s2,0	#beginx
li $s3,0	#beginy
li $s4,0	#endx
li $s5,0	#endy
li $s6,0	#sum
main:
	get_int($s0)
	get_int($s1)
	get_matrix(map,$s0,$s1)
	lw $t1,map
	get_int($s2)
	get_int($s3)
	get_int($s4)
	get_int($s5)
	

	
	get_index($t0,$s2,$s3,$s1)
	li $t1,1
	sw $t1,book($t0)
	
	jal dfs
	
	print_int($s6)
	
	
	li $v0,10
	syscall

dfs:
	li $t2,0	#tx
	li $t3,0	#ty
	li $t4,0	#k
	li $t5,0	#index [tx][ty]
	li $t6,1
	
	bne $s2,$s4 not_end
	bne $s3,$s5 not_end
	addi $s6,$s6,1	#sum++
	jr $ra
	
	not_end:
	addi $t2,$s2,0
	addi $t3,$s3,1
	blt $t2,1,next1
	blt $t3,1,next1
	bgt $t2,$s0,next1
	bgt $t3,$s1,next1
	get_index($t5,$t2,$t3,$s1)
	lw $t5,map($t5)
	bnez $t5,next1
	get_index($t5,$t2,$t3,$s1)
	lw $t5,book($t5)
	bnez $t5,next1
	get_index($t5,$t2,$t3,$s1)
	
	sw $t6,book($t5)
	push($t2)
	push($t3)
	push($t4)
	push($t5)
	push($t6)
	push($s2)
	push($s3)
	push($ra)
	move $s2,$t2
	move $s3,$t3
	jal dfs
	pop($ra)
	pop($s3)
	pop($s2)
	pop($t6)
	pop($t5)
	pop($t4)
	pop($t3)
	pop($t2)
	sw $zero,book($t5)
	
	next1:
	addi $t2,$s2,1
	addi $t3,$s3,0
	
	blt $t2,1,next2
	blt $t3,1,next2
	bgt $t2,$s0,next2
	bgt $t3,$s1,next2
	get_index($t5,$t2,$t3,$s1)
	lw $t5,map($t5)
	bnez $t5,next2
	get_index($t5,$t2,$t3,$s1)
	lw $t5,book($t5)
	bnez $t5,next2
	get_index($t5,$t2,$t3,$s1)
	
	
	sw $t6,book($t5)
	push($t2)
	push($t3)
	push($t4)
	push($t5)
	push($t6)
	push($s2)
	push($s3)
	push($ra)
	move $s2,$t2
	move $s3,$t3
	jal dfs
	pop($ra)
	pop($s3)
	pop($s2)
	pop($t6)
	pop($t5)
	pop($t4)
	pop($t3)
	pop($t2)
	sw $zero,book($t5)
	
	next2:
	addi $t2,$s2,0
	addi $t3,$s3,-1
	
	blt $t2,1,next3
	blt $t3,1,next3 
	bgt $t2,$s0,next3
	bgt $t3,$s1,next3
	get_index($t5,$t2,$t3,$s1)
	lw $t5,map($t5)
	bnez $t5,next3
	get_index($t5,$t2,$t3,$s1)
	lw $t5,book($t5)
	bnez $t5,next3
	get_index($t5,$t2,$t3,$s1)
	
	
	sw $t6,book($t5)
	push($t2)
	push($t3)
	push($t4)
	push($t5)
	push($t6)
	push($s2)
	push($s3)
	push($ra)
	move $s2,$t2
	move $s3,$t3
	jal dfs
	pop($ra)
	pop($s3)
	pop($s2)
	pop($t6)
	pop($t5)
	pop($t4)
	pop($t3)
	pop($t2)
	sw $zero,book($t5)
	
	next3:
	addi $t2,$s2,-1
	addi $t3,$s3,0
	
	blt $t2,1,next4
	blt $t3,1,next4
	bgt $t2,$s0,next4
	bgt $t3,$s1,next4
	get_index($t5,$t2,$t3,$s1)
	lw $t5,map($t5)
	bnez $t5,next4
	get_index($t5,$t2,$t3,$s1)
	lw $t5,book($t5)
	bnez $t5,next4
	get_index($t5,$t2,$t3,$s1)
	
	
	sw $t6,book($t5)
	push($t2)
	push($t3)
	push($t4)
	push($t5)
	push($t6)
	push($s2)
	push($s3)
	push($ra)
	move $s2,$t2
	move $s3,$t3
	jal dfs
	pop($ra)
	pop($s3)
	pop($s2)
	pop($t6)
	pop($t5)
	pop($t4)
	pop($t3)
	pop($t2)
	sw $zero,book($t5)
	
	next4:
	jr $ra