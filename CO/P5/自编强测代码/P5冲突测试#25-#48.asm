.text
    lui     $t1,        0xaabb
    ori     $t2,        0xccdd
                                            # 25
    addu    $t3,        $t1,    $t2
    addu    $t4,        $t2,    $t1
    beq     $t3,        $t4,    label1      # 跳转
    ori     $t8,        $t3,    0xaabb
    nop     
label2:
    nop     
label3:
    subu    $t3,        $t9,    $t1
    beq     $t4,        $t3,    label1      # 不跳转
                                            # 27
    addu    $s1,        $t8,    $t9
    addu    $s2,        $s1,    $0
    nop     
    beq     $s2,        $s1,    label4      # 跳转
    subu    $s6,        $t8,    $t9
label1:
    subu    $t3,        $t2,    $t1
    beq     $t3,        $t4,    label2      # 不跳转
                                            # 26
    addu    $t3,        $t1,    $t2
    beq     $t4,        $t3,    label3      # 跳转
    lui     $t9,        0xaabb
label4:
    subu    $s2,        $s6,    $s1
    beq     $s2,        $s1,    label2      # 不跳转
                                            # 28
    addu    $t1,        $t8,    $t9
    subu    $t2,        $t1,    $0
    nop     
    beq     $t2,        $t1,    label5      # 跳转
    nop     
label6:
    subu    $t2,        $t1,    $0
    nop     
    nop     
    beq     $t2,        $t1,    label7      # 跳转
                                            # 30
    ori     $s1,        $0,     0xffff
label5:
                                            # 29
    addu    $t3,        $t1,    $t2
    addu    $t4,        $t1,    $t2
    nop     
    nop     
    beq     $t3,        $t4,    label6      # 跳转
    lui     $t1,        0xbbdd
    nop     
    nop     
label7:
    addu    $s2,        $s1,    $s1
    subu    $s3,        $s2,    $s1
    nop     
    beq     $s1,        $s2,    label8      # 不跳转
    beq     $s1,        $s3,    label8      # 跳转
    nop     
    nop     
label8:
                                            # 31
    ori     $t1,        $s1,    0xffea
    ori     $t2,        $s3,    0xffea
    beq     $t2,        $t1,    label9      # 跳转
    lui     $t2,        0xffff
    nop     
label10:
    lui     $t6,        0xddee
    lui     $t6,        0xddff
    beq     $t5,        $t6,    label11     # 不跳转
    lui     $t6,        0xddee
    beq     $t5,        $t6,    label11     # 跳转
                                            # 33
    ori     $t7,        $0,     0xdefd
label9:
    beq     $t2,        $t1,    label8      # 不跳转
                                            # 32
    ori     $t3,        $0,     0xaaee
    ori     $t4,        $0,     0xaaee
    beq     $t3,        $t4,    label10     # 跳转
    lui     $t5,        0xddee
label11:
    ori     $t8,        $0,     0xdefd
    nop     
    beq     $t8,        $t7,    label12     # 跳转
    lui     $t8,        0xdefa
    nop     
    nop     
label12:
    nop     
    beq     $t8,        $t7,    label9      # 不跳转
                                            # 34
    ori     $1,         $t8,    0xaabb
    ori     $2,         $t8,    0xaabb
    nop     
    beq     $1,         $2,     label13     # 跳转
    lui     $5,         0xddaa
label13:
    lui     $6,         0xddaa
    nop     
    beq     $5,         $6,     label14     # 跳转
    nop     
label15:
                                            # 36
    ori     $2,         $1,     0xaabb
    nop     
    nop     
    beq     $1,         $2,     label13     # 不跳转

# 37，38不考
# 39
    jal     label16
    addu    $30,        $31,    $0
label14:
                                            # 35
    lui     $1,         0x1234
    lui     $2,         0x1234
    nop     
    beq     $1,         $2,     label15     # 跳转
    nop     
label17:
                                            # 40
    jal     label18
    subu    $29,        $31,    $0
label16:
    beq     $31,        $30,    label17     # 跳转
    nop     
label18:
    beq     $29,        $31,    label19     # 跳转
    nop     
    nop     
label19:
                                            # 41
    jal     label20
    sw      $ra,        12($0)
    nop     
label20:
    lw      $1,         12($0)
    beq     $ra,        $1,     label21     # 跳转
    ori     $1,         $0,     9
label22:
    lw      $2,         -5($1)
    beq     $2,         $ra,    label23     # 跳转
    nop     
label21:
                                            # 42
    jal     label22
    sw      $ra,        4($0)
label24:
                                            # 46
    sw      $8,         0($0)
    lw      $10,        -9($1)
    nop     
    beq     $8,         $10,    label25     # 跳转
    nop     
label23:
                                            # 43, 44已经测过了
                                            # 45
    lw      $8,         12($0)
    lw      $9,         3($1)
    beq     $8,         $9,     label24     # 跳转
    nop     
label25:
                                            # 47
    lw      $28,        0($0)
    lw      $29,        0($0)
    nop     
    nop     
    beq     $29,        $28,    label26     # 跳转
    addu    $30,        $29,    $28
    nop     
label26:
                                            # 48
    sw      $30,        4($0)
    lw      $29,        4($0)
    nop     
    nop     
    beq     $28,        $29,    label25     # 不跳转
    nop     










