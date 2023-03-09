.macro push(%src)
    sw      %src, 0($sp)
    subi    $sp, $sp, 4
.end_macro
.macro pop(%des)
    addi    $sp, $sp, 4
    lw      %des, 0($sp) 
.end_macro
.data
	G: .space 256
	book: .space 32
	li $s3,0 #use as ans
.text
	li $v0,5
	syscall
	move $s0,$v0 # use as n
	li $v0,5
	syscall	
	move $s1,$v0 # use as m
	li $t0,0 # use as i(out of fun)	
begin_for:
	beq $t0,$s1,end_for
	nop
	li $v0,5
	syscall
	move $s4,$v0 #use as x
	li $v0,5
	syscall
	move $s5,$v0 #use as y
	addi $s6,$s4,-1 #x-1
	addi $s7,$s5,-1 #y-1
	sll $s6,$s6,3 # $6=$6<<3
	add $s6,$s6,$s7
	li $t1,0
	add $t1,$t1,$s6
	sll $t1,$t1,2
	li $s7,1
	sw $s7,G($t1)
	
	addi $s6,$s4,-1 #x-1
	addi $s7,$s5,-1 #y-1
	sll $s7,$s7,3
	add $s7,$s7,$s6
	li $t1,0
	add $t1,$t1,$s7
	sll $t1,$t1,2
	li $s7,1
	sw $s7,G($t1)
	addi $t0,$t0,1 #i++
	j begin_for
	nop
end_for:
	li $v0,0
	li $a0,0
	jal dfs
	nop
	move $a0,$v0
	li $v0,1
	syscall
	li $v0,10
	syscall
dfs:
	push($ra)
	push($a0) #store x
	push($t2)
	move $t0,$a0 # x
	li $t1,1 #use as flag
	sll $t0,$t0,2 #t0*4
	li $s7,1
	sw $s7,book($t0) 
	li $t2,0 #use as i
for_begin1:
	beq $t2,$s0,for_end1
	nop
	sll $t3,$t2,2 # t3=t2*4
	lw $t4,book($t3)
	and $t1,$t1,$t4
	addi $t2,$t2,1
	j for_begin1
	nop
for_end1:	
	sll $t3,$a0,5
	lw $t3,G($t3)
	and $t3,$t3,$t1
	beq $t3,1,dfs_end
	nop
	li $t2,0 #use as i
for_begin2:
	beq $t2,$s0,for_end2
	nop
	sll $t3,$t2,2
	lw $t3,book($t3)
	sll $t7,$a0,3
	add $t4,$t7,$t2
	sll $t4,$t4,2
	lw $t4,G($t4)
	xori $t3,$t3,1 # 1^x=!x
	and $t3,$t3,$t4
	beq $t3,1,if_1
	nop
	addi $t2,$t2,1
	j for_begin2
	nop
fun_back:
	addi $t2,$t2,1
	j for_begin2
	nop
for_end2:
	pop($t2)
	pop($a0)
	pop($ra)
	sll $t0,$a0,2
	li $s7,0
	sw $s7,book($t0)
	jr $ra
	nop
dfs_end:
		pop($t2)
		pop($a0)
		pop($ra)
		li $v0,1
		jr $ra
		nop
if_1:
	move $a0,$t2
	jal dfs	
	j fun_back
	nop