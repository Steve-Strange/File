  .text 
  lui $1,0xffff
  ori $1,$1,0xfc01
  mtc0 $1,$12
  lui $2,0xffff
  #int-grf
  ori $2,$2,0x1234
  #int-store
  sw $2,0($0)
  ori $3,$0,0xfc01
  #int-mfc0
  mtc0 $3,$12
  #int-load
  lw $4,0($0)
  lw $5,0($0)
  #int-stall
  add $6,$5,$4
  lui $7,0x7fff
  lui $8,0x7fff
  #int-beq
  beq $7,$8,label1
  #int&exc-BD
  add $9,$7,$8
  #int-D beq
  addi $10,$0,0x0001
  addi $11,$0,0x0002
  beq $7,$8,label1
  nop

  label1:
  mult $7,$8
  syscall
  div $7,$8
  syscall
  mthi $7
  syscall
  mtlo $8
  syscall
  mfhi $10
  mflo $11
  mult $7,$8
  beq $7,$8,label2
  #int-many nop
  mflo $12
  addi $12,$0,0x0001
  addi $12,$0,0x0002

  label2:
  addi $13,$0,0x0001

  end:
  beq $0,$0,end
  nop


  .ktext 0x4180
  main_handler:
  mfc0 $26,$13
  mfc0 $27,$14
  ori $27,$0,0x007c
  and $26,$27,$26
  beq $0,$26,interrupt
  nop
  mfc0 $26,$14
  add $26,$26,4
  mtc0 $26,$14
  beq $0,$0,return
  nop
  
  interrupt:
  ori $27,$0,0x2137
  sw $27,0x7f20($0)
  beq $0,$0,return
  nop

  return:
  eret