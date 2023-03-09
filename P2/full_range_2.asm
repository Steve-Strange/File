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

.macro get_index(%ans,%i,%j,%column)
	mul %ans,%i,%column
	add %ans,%ans,%j
	sll %ans,%ans,2
.end_macro

.data
	symbol: .space 28
	array: .space 28
	
.text
li $s0,0	#s0:n
li $s1,0	#s1:index
li $s2,1	#==1

main:
	read_int($s0)
	jal FullArray
	
	li $v0,10
	syscall
	
FullArray:

	li $t0,0	#t0:i
	bgt $s0,$s1 else
		li $t0,0
		for_out:
		beq $t0,$s0,for_out_end
			lb $t1,array($t0)
			print_int($t1)
			print_space
			addi $t0,$t0,1
		j for_out
		for_out_end:
		print_enter

		jr $ra
	else:
	li $t0,0
	for_search:
	beq $t0,$s0,for_search_end
		lb $t1,symbol($t0)
		bnez,$t1,continue
		
		addi $t2,$t0,1
		sb $t2,array($s1)
		sb $s2,symbol($t0)
		push($ra)
		push($t0)
		push($t1)
		push($t2)
		push($s1)
		addi $s1,$s1,1
		jal FullArray
		pop($s1)
		pop($t2)
		pop($t1)
		pop($t0)
		pop($ra)
		sb $zero,symbol($t0)
		
		continue:
		addi $t0,$t0,1
	j for_search
	for_search_end:
	
	jr $ra
	