.text
	ori $t1,$0,0xaabb
	ori $t3,$0,0xccff
	
	# 1
	addu $t2,$t1,$t3
	addu $t4,$t2,$t3
	subu $t5,$t4,$t1
	addu $t6,$t5,$t3
	subu $t7,$t6,$t3
	subu $t8,$t7,$t1
	
	#2
	lui $t1,0xaadd
	lui $t2,0xccee
	
	addu $t3,$t1,$t2
	addu $t4,$t1,$t3
	subu $t5,$t3,$t4
	addu $t6,$t2,$t5
	subu $t7,$t1,$t6
	subu $t8,$t2,$t7
	
	#3
	ori $s1,$0,0xaabb
	lui $s3,0xccdd
	ori $s3,$s3,0xeeff
	
	addu $s2,$s1,$s3
	nop
	addu $s4,$s2,$s3
	nop
	subu $s5,$s4,$s1
	nop
	addu $s6,$s5,$s3
	nop
	subu $s7,$s6,$s3
	nop
	subu $s0,$s7,$s1
	nop
	
	#4
	lui $s1,0xaadd
	lui $s2,0xccee
	
	addu $s3,$s1,$s2
	nop
	addu $s4,$s1,$s3
	nop
	subu $s5,$s3,$s4
	nop
	addu $s6,$s2,$s5
	nop
	subu $s7,$s1,$s6
	nop
	subu $s0,$s2,$s7
	nop
	
	#5
	ori $s0,$s1,0xddee
	addu $s2,$s0,$s1
	lui $s3,0xffee
	addu $s4,$s3,$s2
	ori $s5,$s2,0xffaa
	subu $s6,$s5,$s4
	lui $s6,0xddff
	subu $s7,$s6,$s0
	
	# 6
	ori $s0,$s1,0xddee
	addu $s2,$s1,$s0
	lui $s3,0xffee
	addu $s4,$s2,$s3
	ori $s5,$s2,0xffaa
	subu $s6,$s4,$s5
	lui $s6,0xddff
	subu $s7,$s0,$s6
	
	#7
	ori $t0,$t1,0xddee
	nop
	addu $t2,$t0,$t1

	lui $t3,0xffee
	nop
	addu $t4,$t3,$t2

	ori $t5,$t2,0xffaa
	nop
	subu $t6,$t5,$t4

	lui $t6,0xddff
	nop
	subu $t7,$t6,$t0
	
	# 8
	ori $t0,$t1,0xddee
	nop
	addu $t2,$t1,$t0

	lui $t3,0xffee
	nop
	addu $t4,$t2,$t3

	ori $t5,$t2,0xffaa
	nop
	subu $t6,$t4,$t5

	lui $t6,0xddff
	nop
	subu $t7,$t0,$t6
	
	# 9
	jal label1
	addu $ra,$ra,$t7
	nop
	nop
	nop
label1:
	jal label2
	subu $t2,$ra,$t6
	nop
	nop
	nop
	nop
	
	#10
label2:
	jal label3
	addu $ra,$t6,$ra
	nop
	nop
label3:
	jal label4
	subu $t3,$t4,$ra
	nop
	nop
	nop
label4:
	#11
	jal label5
	nop
	nop
	nop
label5:
	addu $ra,$ra,$t7
	jal label6
	nop
	nop
	nop
	nop
	
label6:
	subu $t2,$ra,$t6
	#12	
	jal label7
	nop
	nop
label7:
	addu $ra,$t6,$ra
	jal label8
	nop
	nop
	nop
label8:
	addu $ra,$t6,$ra
	
	
	
	
	
	
	