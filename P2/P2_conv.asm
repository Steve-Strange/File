.macro read_int(%des)
	li $v0,5
	syscall
	move %des,$v0
.end_macro

.macro print_int(%src)
	move $a0,%src
	li $v0,1
	syscall
.end_macro

.macro get_index(%ans,%i,%j,%column)
	mul %ans,%i,%column
	add %ans,%ans,%j
	sll %ans,%ans,2
.end_macro

.macro push(%src)
	sw %src,0($sp)
	subi $sp,$sp,4
.end_macro

.macro pop(%des)
	addi $sp,$sp,4
	lw %des,0($sp)
.end_macro

.macro print_space()
	li $a0,' '
	li $v0,11
	syscall
.end_macro

.macro print_enter()
	li $a0,'\n'
	li $v0,11
	syscall
.end_macro

.data
	f: .space 400
	h: .space 400
	g: .space 400
	
.text 
	main:
		read_int($s0)	#m1
		read_int($s1)	#n1
		read_int($s2)	#m2
		read_int($s3)	#n2
		# sub $s4,$s0,$s2 
		# addi $s4,$s4,1	#m3
		# sub $s5,$s1,$s3
		# addi $s5,$s5,1	#n3
		la $s4 f
		la $s5 h
		move $a0,$s0  #row
		move $a1,$s1  #column
		move $a2,$s4  #add
		jal matrix_input
		
		move $a0,$s2  #row
		move $a1,$s3  #column
		move $a2,$s5  #add
		jal matrix_input
		
		sub $t5,$s0,$s2
		sub $t6,$s1,$s3
		addi $t5,$t5,1
		addi $t6,$t6,1
		li $t0,0
		li $t1,0
		
		for1:
		beq $t0,$t5,for1_end
			li $t1,0
			for2:
			beq $t1,$t6,for2_end
				move $a2,$t0
				move $a3,$t1
				jal matrix_mul
				#get_index($t2,$t0,$t1,$s1)
				#lw $t2 g($t2)
				#print_int($t2)
				print_space()
				addi $t1,$t1,1
				j for2
			for2_end:
			print_enter()
			addi $t0,$t0,1
			j for1
		for1_end:
		
		li $v0,10
		syscall

		
	matrix_input:
	push($t3)
	push($t4)
	push($t5)
	push($t6)
		li $t3,0  #i
		li $t4,0  #j
		
		for_i1:
		beq $t3,$a0 for_i1_end
			li $t4,0  #j
			for_j1:
			beq $t4,$a1 for_j1_end
				li $t5,0  #index
				li $t6,0  #content
				get_index($t5,$t3,$t4,$a1)
				add $t5,$t5,$a2
				read_int($t6)
				sw $t6,0($t5)
				addi $t4,$t4,1
				j for_j1
			for_j1_end:
			addi $t3,$t3,1
			j for_i1
		for_i1_end:
	pop($t6)
	pop($t5)
	pop($t4)
	pop($t3)
	jr $ra
		
		
		
	matrix_mul:
	push($s1)
	push($s2)
	push($s3)
	push($s5)
	push($s7)
	push($t3)
	push($t4)
	push($t5)
	push($t6)
	push($t7)
	push($t8)
	push($t9)	
	
		li $t3,0  #k
		li $t4,0  #l
		li $s7,0
		for_i2:
		beq $t3,$s2 for_i2_end
			li $t4,0  #l
			for_j2:
			beq $t4,$s3 for_j2_end
				li $t5,0  #j(i+k,j+l)
				li $t6,0  #h(k,l)
				add $t7,$t3,$a2  #k+i
				add $t8,$t4,$a3  #l+j
				#print_int($t7)
				#print_int($t8)
				get_index($t5,$t7,$t8,$s1)
				lw $t5,f($t5)
				#print_int($t5)
				get_index($t6,$t3,$t4,$s3)
				lw $t6,h($t6)
				#print_int($t6)
				mul $t5,$t5,$t6
				add $s7,$s7,$t5
				addi $t4,$t4,1
				j for_j2
			for_j2_end:
			
			addi $t3,$t3,1
			j for_i2
		for_i2_end:
		print_int($s7)
	pop($t9)
	pop($t8)
	pop($t7)
	pop($t6)
	pop($t5)
	pop($t4)
	pop($t3)
	pop($s7)
	pop($s5)
	pop($s3)
	pop($s2)
	pop($s1)	
	jr $ra
