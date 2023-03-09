.data
	matrix1: .space 400
	matrix2: .space 400
	output: .space 400
	str_space:  .asciiz " "
	str_enter: .asciiz "\n"
	
.macro getaddr(%ans,%i,%j,%columns)
	mul %ans,%i,%columns
	add %ans,%ans,%j
	sll %ans,%ans,2
.end_macro

.text
	li $v0,5  #read n
	syscall
	move $s0,$v0   # s0:n
	
	li $t0,0  #t0:i
	li $t1,0  #t1:j
	
	#matrix1
	la $a0,matrix1
	jal scan_matrix
	
	#matrix2
	la $a0,matrix2
	jal scan_matrix
	
	output_x:
		output_y:
			cover:   #t3: cnt
				getaddr($t2,$t0,$t3,$s0)  #t2:(i,cnt)addr
				lw $t4,matrix1($t2)  #t4: (i,cnt)
				getaddr($t2,$t3,$t1,$s0)  #t2:(cnt,j)addr
				lw $t5,matrix2($t2)  #t5: (cnt,j)
				mul $t5,$t4,$t5   #t5: (i,cnt)*(cnt,j)
				getaddr($t2,$t0,$t1,$s0)  #t2:(i,j)addr
				lw $t4,output($t2)
				add $t5,$t5,$t4
				sw $t5,output($t2)
				addi $t3,$t3,1  #cnt++
				bne $t3,$s0,cover
			li $t3,0
			addi $t1,$t1,1  #j++
			bne $t1,$s0,output_y
		li $t1,0
		addi $t0,$t0,1  #i++
		bne $t0,$s0,output_x
		li $t0,0
	
	jal print_matrix	
		
	li $v0,10
	syscall
	
scan_matrix:
	input_x:
		input_y:
			li $v0,5  #read (i,j)
			syscall
			getaddr($t2,$t0,$t1,$s0)  #t2:(i,j)addr
			add $t2,$a0,$t2
			sw $v0,0($t2)
			addi $t1,$t1,1  #j++
			bne $t1,$s0,input_y
		li $t1,0
		addi $t0,$t0,1  #i++
		bne $t0,$s0,input_x
	li $t0,0
	jr $ra
		
	print_matrix:
		output_x2:
			output_y2:
				getaddr($t2,$t0,$t1,$s0)  #t2:(i,j)addr
				lw $a0,output($t2)
				li $v0,1
				syscall
				la $a0,str_space
				li $v0,4
				syscall
				addi $t1,$t1,1  #j++
				bne $t1,$s0,output_y2
			li $t1,0
			la $a0,str_enter
			li $v0,4
			syscall
			addi $t0,$t0,1  #i++
			bne $t0,$s0,output_x2
		li $t0,0
		jr $ra
		