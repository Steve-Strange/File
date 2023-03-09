.macro end
    li      $v0, 10
    syscall
.end_macro

.macro getInt(%des)
    li      $v0, 5
    syscall
    move    %des, $v0
.end_macro

.macro printInt(%src)
    move    $a0, %src
    li      $v0, 1
    syscall
.end_macro

.macro push(%src)
    sw      %src, 0($sp)
    subi    $sp, $sp, 4
.end_macro

.macro pop(%des)
    addi    $sp, $sp, 4
    lw      %des, 0($sp) 
.end_macro

.macro  getIndex(%ans, %i, %j)
    sll %ans, %i, 3             # %ans = %i * 8
    add %ans, %ans, %j          # %ans = %ans + %j
    sll %ans, %ans, 2           # %ans = %ans * 4
.end_macro



.data
	G: .space 320
	book: .space 40
	
	
.text


main:
	getInt($s0)
	getInt($s1)
	li $s2 0
	
	input_begin:
	beq $s2,$s1, input_end
	nop
	addi $s2,$s2,1
	getInt($t0)
	getInt($t1)	
	getIndex($t2,$t0,$t1)
	li $v0,1
	sw $v0,G($t2)
	getIndex($t2,$t1,$t0)
	sw $v0,G($t2)	
	j input_begin
	
input_end:
	li $v0,0
	li $a0,0
	jal dfs
	nop
	li $t0,0
	printInt($t0)
	end

		
dfs:

    push($ra)
    push($a0)
    push($t2)
    push($v0)
    move $t3,$a0
	li $v0,1
	mul $t7,$t3,4
	sw $v0,book($t7)
	li $t5,0
	li $t4,1
	
	all_begin:
	
	beq $t5,$s0,all_end
	nop
	mul $t7,$t5,4
	lw $t8,book($t7)
	mul $t4,$t4,$t8
	addi $t5,$t5,1
	
	j all_begin
	nop
	
	all_end:
	
	getIndex($t2,$t3,0)
	lw $t2,G($t2)
	mul $t2,$t2,$t4
		
	li $t5,0
	beqz $t2,continue
	nop
	li $s3,1
	printInt($s3)
	end

	continue:
	beq $t5,$s0,search_end
	nop
	
	li $t7 1
	getIndex($t6,$t3,$t5)
	mul $t7,$t5,4
	lw $t8,book($t7)
	lw $a2,G($t6)
	add $s4,$t8,$a2
	mul $s4,$a2,$s4
	addi $s4,$s4,-1
	addi $t5,$t5,1
	beqz $s4,next
	nop
	
	move $a0,$t5
	jal dfs

	next:
	j continue
	nop
	
	search_end:
	mul $t7,$a0,4
	sw $zero,book($t7)

    pop($v0)
    pop($t2)
	pop($a0)	
	pop($ra)
	jr $ra
