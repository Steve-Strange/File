.text
    mtc0 $0, $12
    ori $at, $0, 0xfffc

	#====OV=====
    lui $t0, 0x7fff
    lui $t1, 0xffff
    add $t2, $t0, $t1
    sub $t2, $t0, $t1
    sub $t2, $t1, $t0
    lui $t1, 0x7fff
    add $t2, $t0, $t1
    ori $t1, $t1, 0xffff
    addi $t2, $t1, 0xfffffff0
    addi $t1, $t1, 0x0010

	#=====SYSCALL=====
    syscall
    
    #=====ADEL=====
    lui $t1, 0x7fff
    jal label1
    add $ra, $ra, $t1
label1:
    jr $ra
    nop
    jal label2
    addi $ra, $ra, 1
label2:
    jr $ra
    nop
    ori $t0, $0, 0x7f00
    ori $t2, $0, 0x7f20
    sw $t0, 0($0)
    lw $t0, 0($0)
    lw $t0, 1($0)
    lw $t0, 2($0)
    lh $t0, 3($0)
    lh $t0, 0($t0)
    lh $t0, 2($t0)
    lb $t0, 0($t0)
    lb $t0, 3($t0)
loop_timer1:
    lw $t1, 0($t0)
    addi $t0, $t0, 4
    bne $t0, $t2, loop_timer1
    nop
    ori $t0, $0, 0x3000
    lw $t0, 0($t0)
    lui $t0, 0x7fff
    ori $t0, $t0, 0xffff
	lw $t0, 1($t0)
	lw $t0, -4($0)
	
	#=====ADES=====
	sw $0, 1($0)
    sw $0, 2($0)
    sh $0, 3($0)
    sw $0, 4($0)
    sh $0, 6($0)
    sb $0, 7($0)
    ori $t0, $0, 0x7f00
    sh $0, 0($t0)
    sh $0, 2($t0)
    sb $0, 0($t0)
    sb $0, 3($t0)
    ori $t1, $0, 0x7f30
loop_timer2:
	sw $0, 0($t0)
	addi $t0, $t0, 4
    bne $t0, $t1, loop_timer2
    nop
    ori $t0, $0, 0x3000
    sw $0, 0($t0)
    lui $t0, 0x7fff
    ori $t0, $t0, 0xffff
	sw $0, 1($t0)
	sw $0, -1($0)

	#=====ALTOGETHER=====
	lui $t0, 0x7fff
	ori $t1, $t0, 0xffff
	sw $0, 0($t0)
	addi $t1, $t1, 1
	syscall
	
	sw $0, 0($t0)
	addi $t1, $t1, 1
	nop
	
	sw $0, 0($t0)
	addi $t1, $t1, 0
	syscall
	
	sw $0, 0($0)
	addi $t1, $t1, 1
	syscall
	
	lui $t0, 0x8000
	addi $t1, $t1, 1
	beq $t0, $t1, end
	nop

end:
    beq $0, $0, end
    nop

.ktext 0x4180
_main_handler:
    mfc0 $k0, $13
    mfc0 $k0, $14
    and $k0, $k0, $at
    addi $k0, $k0, 4
    mtc0 $k0, $14
    eret
