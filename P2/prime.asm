.macro get_int(%des)
	li $v0,5
	syscall
	move %des,$v0
.end_macro

.macro print_int(%src)
	li $v0,1
	move $a0,%src
	syscall
.end_macro

.text
	get_int($s0)
	li $s1,1
	sub $t0,$s0,1
	for:
	blt $t0,2,for_end
		div $s0,$t0
		mfhi $t1
		bnez $t1,continue
			li $s1,0
		continue:
		subi $t0,$t0,1
	j for
	for_end:
	
	print_int($s1)
	li $v0,10
	syscall	
		