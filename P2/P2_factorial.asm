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

.macro print_enter
	li $a0, '\n'
	li $v0,11
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

.data
	arr: .space 40000
	
.text
	li $s7,1
	sw $s7,arr
	li $s7,10	#10
	get_int($s0)	#n
	li $s1,1	#cnt
	li $t0,1	#i
	for1:
	bgt $t0,$s0,for1_end
		li $s2,0	#up
		li $t1,0	#j
		
		for2:
		beq $t1,$s1,for2_end
			sll,$t2,$t1,2	#index_j
			lw $t3,arr($t2)		#arr[j]
			#print_int($t3)
			mul $t4,$t3,$t0
			add $t4,$t4,$s2
			div $t4,$s7
			mflo $s2
			mfhi $t3
			sw $t3,arr($t2)
			addi $t1,$t1,1
		j for2
		for2_end:
		beqz $s2,out
			sll $t2,$s1,2
			div $s2,$s7
			mflo $s2
			mfhi $t3
			sw $t3,arr($t2)
			addi $s1,$s1,1
		j for2_end
		out:
		addi $t0,$t0,1
	j for1
	for1_end:

	subi $t5,$s1,1
	subi $s1,$s1,1
	
	for3:
	bltz $t5,for3_end
		sll $t6,$t5,2
		lw $t6,arr($t6)
		print_int($t6)
		subi $t5,$t5,1
	j for3
	for3_end:
	li $v0,10
	syscall
