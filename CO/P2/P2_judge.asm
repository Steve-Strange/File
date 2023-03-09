.macro read_int(%des)
	li $v0,5
	syscall
	move %des,$v0
.end_macro

.macro read_char(%des)
	li $v0,12
	syscall
	move %des,$v0
.end_macro

.macro print_int(%src)
	move $a0,%src
	li $v0,1
	syscall
.end_macro

.macro push(%src)
	sw %src,0($sp)
	subi $sp,$sp,4
.end_macro

.macro pop(%des)
	addi $sp,$sp,4
	lw %des,0($sp)
.end_macro


.text
	li $s3,1  #s3:flag
	read_int($s0)  #s0:n
	div $s1,$s0,2  #s1:[n/2]
	sll $s2,$s1,1  #s2=n or n-1
	
	li $t0,0  #t0:i=0
	li $t1,0  #t1:pointer
	for_in1:
	beq $t0,$s1,for_in1_end
		read_char($t2)
		push($t2)
		addi $t0,$t0,1
	j for_in1
	for_in1_end:
	
	beq $s2,$s0,even
		read_char($t2)
	even:
	

	li $t0,0  #t0:i=0
	for_in2:
	beq $t0,$s1,for_in2_end
		read_char($t2)  #t2:read_int
		pop($t3)
		beq $t2,$t3,right
		li $s3,0
		right:
		addi $t0,$t0,1
	j for_in2	
	for_in2_end:
	
	print_int($s3)
	li $v0,10
	syscall
