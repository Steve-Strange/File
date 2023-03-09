.text
#addu写0寄存器
	ori $t0,$0,0xaabb
	addu $0,$t0,$t0
	addu $t1,$0,$t0
	
	addu $0,$t1,$t0
	subu $t2,$t1,$0
	
	addu $0,$t1,$t1
	ori $t3,$0,0xccdd
	
	addu $0,$t2,$t2
	sw $t2,4($0)
	
	addu $0,$t2,$t2
	lw $t4,4($0)
	
	addu $0,$t2,$0
	beq $0,$t2,label1
label1:
	#间隔一条指令
	ori $t0,$0,0x1122
	addu $0,$t0,$t0
	nop
	addu $t1,$0,$t0
	
	addu $0,$t1,$t0
	nop
	subu $t2,$t1,$0
	
	addu $0,$t1,$t1
	nop
	ori $t3,$0,0x3344
	
	addu $0,$t2,$t2
	nop
	sw $t2,4($0)
	
	addu $0,$t2,$t2
	nop
	lw $t4,4($0)
	
	addu $0,$t2,$0
	nop
	beq $0,$t2,label1
	
	#间隔两条指令
	ori $t0,$0,0x4321
	addu $0,$t0,$t0
	nop
	nop
	addu $t1,$0,$t0
	
	addu $0,$t1,$t0
	nop
	nop
	subu $t2,$t1,$0
	
	addu $0,$t1,$t1
	nop
	ori $t3,$0,0x0543
	
	addu $0,$t2,$t2
	nop
	nop
	sw $t2,4($0)
	
	addu $0,$t2,$t2
	nop
	nop
	lw $t4,4($0)
	
	addu $0,$t2,$0
	nop
	nop
	beq $0,$t2,label1

# subu写0寄存器
	ori $t1,$0,0xaabb
	ori $t2,$0,0xccdd
	
	subu $0,$t2,$t1
	addu $t3,$0,$0
	
	subu $0,$t2,$t1
	subu $t3,$t1,$0
	
	subu $0,$t2,$t1
	subu $t3,$0,$t1
	
	subu $0,$t2,$t1
	ori $t3,$0,0x1234
	
	subu $0,$t1,$t2
	sw $t1,16($0)
	
	subu $0,$t2,$t1
	lw $t4,16($0)
	
	subu $0,$t1,$0
	beq $t1,$0,label1
	
	subu $0,$t2,$0
	beq $0,$t2,label1
	
	#间隔1条指令
	ori $t1,$0,0xaabb
	ori $t2,$0,0xccdd
	
	subu $0,$t2,$t1
	nop
	addu $t3,$0,$0
	
	subu $0,$t2,$t1
	nop
	subu $t3,$t1,$0
	
	subu $0,$t2,$t1
	nop
	subu $t3,$0,$t1
	
	subu $0,$t2,$t1
	nop
	ori $t3,$0,0x1234
	
	subu $0,$t1,$t2
	nop
	sw $t1,16($0)
	
	subu $0,$t2,$t1
	nop
	lw $t4,16($0)
	
	subu $0,$t1,$0
	nop
	beq $t1,$0,label1
	
	subu $0,$t2,$0
	nop
	beq $0,$t2,label1
	
	#间隔两条指令
	ori $t1,$0,0xaabb
	ori $t2,$0,0xccdd
	
	subu $0,$t2,$t1
	nop
	nop
	addu $t3,$0,$0
	
	subu $0,$t2,$t1
	nop
	nop
	subu $t3,$t1,$0
	
	subu $0,$t2,$t1
	nop
	nop
	subu $t3,$0,$t1
	
	subu $0,$t2,$t1
	nop
	nop
	ori $t3,$0,0x1234
	
	subu $0,$t1,$t2
	nop
	nop
	sw $t1,16($0)
	
	subu $0,$t2,$t1
	nop
	nop
	lw $t4,16($0)
	
	subu $0,$t1,$0
	nop
	nop
	beq $t1,$0,label1
	
	subu $0,$t2,$0
	nop
	nop
	beq $0,$t2,label1
	
# ori 写0寄存器
	ori $0,$t1,0xaabb
	addu $t3,$0,$0
	
	ori $0,$t2,0xbbcc
	subu $t3,$t2,$0
	
	ori $0,$t2,0xddee
	subu $t3,$0,$t2
	
	ori $0,$t1,0x1234
	ori $t3,$0,0xaabb
	
	ori $0,$t2,0x1234
	sw $0,4($0)
	
	ori $0,$t2,0x3344
	sw $t2,0($0)
	
	ori $0,$t1,0x100
	lw $t3,0($0)
	
	ori $t1,$0,0xaabb
	ori $0,$0,0xaabb
	beq $0,$t1,label1
	
	ori $t1,$0,0xaabb
	ori $0,$0,0xaabb
	beq $t1,$0,label1
	
	#间隔一条指令
	ori $0,$t1,0xaabb
	nop
	addu $t3,$0,$0
	
	ori $0,$t2,0xbbcc
	nop
	subu $t3,$t2,$0
	
	ori $0,$t2,0xddee
	nop
	subu $t3,$0,$t2
	
	ori $0,$t1,0x1234
	nop
	ori $t3,$0,0xaabb
	
	ori $0,$t2,0x1234
	nop
	sw $0,4($0)
	
	ori $0,$t2,0x3344
	nop
	sw $t2,0($0)
	
	ori $0,$t1,0x100
	nop
	lw $t3,0($0)
	
	ori $t1,$0,0xaabb
	ori $0,$0,0xaabb
	nop
	beq $0,$t1,label1
	
	ori $t1,$0,0xaabb
	ori $0,$0,0xaabb
	nop
	beq $t1,$0,label1
	
	#间隔两条指令
	ori $0,$t1,0xaabb
	nop
	nop
	addu $t3,$0,$0
	
	ori $0,$t2,0xbbcc
	nop
	nop
	subu $t3,$t2,$0
	
	ori $0,$t2,0xddee
	nop
	nop
	subu $t3,$0,$t2
	
	ori $0,$t1,0x1234
	nop
	nop
	ori $t3,$0,0xaabb
	
	ori $0,$t2,0x1234
	nop
	nop
	sw $0,4($0)
	
	ori $0,$t2,0x3344
	nop
	nop
	sw $t2,0($0)
	
	ori $0,$t1,0x100
	nop
	nop
	lw $t3,0($0)
	
	ori $t1,$0,0xaabb
	ori $0,$0,0xaabb
	nop
	nop
	beq $0,$t1,label1
	
	ori $t1,$0,0xaabb
	ori $0,$0,0xaabb
	nop
	nop
	beq $t1,$0,label1
	nop