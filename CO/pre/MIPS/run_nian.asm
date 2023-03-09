
.text
	li $v0,5
	syscall
	li $t3,4
	li $t1,100
	li $t2,400
	div $v0,$t1
	mfhi $t0
	beq $t0,0,else
	nop
	div $v0,$t3
	mfhi $t0
	beq $t0,0,output1
	nop
	j output0
	nop 
	
else:
	div $v0,$t2	
	mfhi $t0
	beq $t0,0,output1	
	nop
	j output0
	nop
	
output0:
	li $a0,0
	li $v0,1
	syscall
	li $v0,10
	syscall

output1:
	li $a0,1
	li $v0,1
	syscall
	li $v0,10
	syscall
