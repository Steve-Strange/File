.data
	matrix: .space 12000
	str_space: .asciiz " "
	str_enter: .asciiz "\n"
	
.macro  getindex(%ans, %i, %j)
    mul %ans, %i, 50            # %ans = %i * 50
    add %ans, %ans, %j          # %ans = %ans + %j
    sll %ans, %ans, 2           # %ans = %ans * 4
.end_macro


.text
	la $t0,matrix	
	li $v0,5
	syscall
	move $s0,$v0
	li $v0,5
	syscall
	move $s1,$v0
	
	li $t0,0
	in_i:
		beq $t0,$s0,in_i_end
		li $t1,0
		
		in_j:
			beq $t1,$s1,in_j_end
			li $v0,5
			syscall
			getindex($t2,$t0,$t1)
			sw $v0,matrix($t2)
			addi $t1,$t1,1
			j in_j
			nop
		in_j_end:
		addi $t0,$t0,1
		j in_i
		nop
	in_i_end:
	
	subi $t0,$s0,1
	out_i:
		beq $t0,-1,out_i_end
		subi $t1,$s1,1
		
		out_j:
			beq $t1,-1,out_j_end
			getindex($t2,$t0,$t1)
			lw $t3,matrix($t2)
			beqz $t3, none
			
			addi $a0,$t0,1
			li $v0,1
			syscall
			
			la $a0,str_space
			li $v0,4
			syscall		
			
			addi $a0,$t1,1
			li $v0,1
			syscall
			
			la $a0,str_space
			li $v0,4
			syscall
			
			move $a0,$t3
			li $v0,1
			syscall
			
			la $a0,str_enter
			li $v0,4
			syscall
			
			none:
			subi $t1,$t1,1
			j out_j
			nop
		out_j_end:
		subi $t0,$t0,1
		j out_i
		nop
	out_i_end:
	li $v0,10
	syscall
		
		
		
	
