.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

/* Generated by spimdisasm 1.32.1 */

glabel bcmp
    /* 37FB0 800373B0 28C10010 */  slti       $at, $a2, 0x10
    /* 37FB4 800373B4 14200037 */  bnez       $at, .L80037494_38094
    /* 37FB8 800373B8 00851026 */   xor       $v0, $a0, $a1
    /* 37FBC 800373BC 30420003 */  andi       $v0, $v0, 0x3
    /* 37FC0 800373C0 14400019 */  bnez       $v0, .L80037428_38028
    /* 37FC4 800373C4 0004C023 */   negu      $t8, $a0
    /* 37FC8 800373C8 33180003 */  andi       $t8, $t8, 0x3
    /* 37FCC 800373CC 13000007 */  beqz       $t8, .L800373EC_37FEC
    /* 37FD0 800373D0 00D83023 */   subu      $a2, $a2, $t8
    /* 37FD4 800373D4 00601025 */  or         $v0, $v1, $zero
    /* 37FD8 800373D8 88820000 */  lwl        $v0, 0x0($a0)
    /* 37FDC 800373DC 88A30000 */  lwl        $v1, 0x0($a1)
    /* 37FE0 800373E0 00982021 */  addu       $a0, $a0, $t8
    /* 37FE4 800373E4 00B82821 */  addu       $a1, $a1, $t8
    /* 37FE8 800373E8 14430036 */  bne        $v0, $v1, .L800374C4_380C4
  .L800373EC_37FEC:
    /* 37FEC 800373EC 2401FFFC */   addiu     $at, $zero, -0x4
    /* 37FF0 800373F0 00C13824 */  and        $a3, $a2, $at
    /* 37FF4 800373F4 10E00027 */  beqz       $a3, .L80037494_38094
    /* 37FF8 800373F8 00C73023 */   subu      $a2, $a2, $a3
    /* 37FFC 800373FC 00E43821 */  addu       $a3, $a3, $a0
    /* 38000 80037400 8C820000 */  lw         $v0, 0x0($a0)
  .L80037404_38004:
    /* 38004 80037404 8CA30000 */  lw         $v1, 0x0($a1)
    /* 38008 80037408 24840004 */  addiu      $a0, $a0, 0x4
    /* 3800C 8003740C 24A50004 */  addiu      $a1, $a1, 0x4
    /* 38010 80037410 1443002C */  bne        $v0, $v1, .L800374C4_380C4
    /* 38014 80037414 00000000 */   nop
    /* 38018 80037418 5487FFFA */  bnel       $a0, $a3, .L80037404_38004
    /* 3801C 8003741C 8C820000 */   lw        $v0, 0x0($a0)
    /* 38020 80037420 1000001C */  b          .L80037494_38094
    /* 38024 80037424 00000000 */   nop
  .L80037428_38028:
    /* 38028 80037428 00053823 */  negu       $a3, $a1
    /* 3802C 8003742C 30E70003 */  andi       $a3, $a3, 0x3
    /* 38030 80037430 10E0000A */  beqz       $a3, .L8003745C_3805C
    /* 38034 80037434 00C73023 */   subu      $a2, $a2, $a3
    /* 38038 80037438 00E43821 */  addu       $a3, $a3, $a0
    /* 3803C 8003743C 90820000 */  lbu        $v0, 0x0($a0)
  .L80037440_38040:
    /* 38040 80037440 90A30000 */  lbu        $v1, 0x0($a1)
    /* 38044 80037444 24840001 */  addiu      $a0, $a0, 0x1
    /* 38048 80037448 24A50001 */  addiu      $a1, $a1, 0x1
    /* 3804C 8003744C 1443001D */  bne        $v0, $v1, .L800374C4_380C4
    /* 38050 80037450 00000000 */   nop
    /* 38054 80037454 5487FFFA */  bnel       $a0, $a3, .L80037440_38040
    /* 38058 80037458 90820000 */   lbu       $v0, 0x0($a0)
  .L8003745C_3805C:
    /* 3805C 8003745C 2401FFFC */  addiu      $at, $zero, -0x4
    /* 38060 80037460 00C13824 */  and        $a3, $a2, $at
    /* 38064 80037464 10E0000B */  beqz       $a3, .L80037494_38094
    /* 38068 80037468 00C73023 */   subu      $a2, $a2, $a3
    /* 3806C 8003746C 00E43821 */  addu       $a3, $a3, $a0
    /* 38070 80037470 88820000 */  lwl        $v0, 0x0($a0)
  .L80037474_38074:
    /* 38074 80037474 8CA30000 */  lw         $v1, 0x0($a1)
    /* 38078 80037478 98820003 */  lwr        $v0, 0x3($a0)
    /* 3807C 8003747C 24840004 */  addiu      $a0, $a0, 0x4
    /* 38080 80037480 24A50004 */  addiu      $a1, $a1, 0x4
    /* 38084 80037484 1443000F */  bne        $v0, $v1, .L800374C4_380C4
    /* 38088 80037488 00000000 */   nop
    /* 3808C 8003748C 5487FFF9 */  bnel       $a0, $a3, .L80037474_38074
    /* 38090 80037490 88820000 */   lwl       $v0, 0x0($a0)
  .L80037494_38094:
    /* 38094 80037494 18C00009 */  blez       $a2, .L800374BC_380BC
    /* 38098 80037498 00C43821 */   addu      $a3, $a2, $a0
    /* 3809C 8003749C 90820000 */  lbu        $v0, 0x0($a0)
  .L800374A0_380A0:
    /* 380A0 800374A0 90A30000 */  lbu        $v1, 0x0($a1)
    /* 380A4 800374A4 24840001 */  addiu      $a0, $a0, 0x1
    /* 380A8 800374A8 24A50001 */  addiu      $a1, $a1, 0x1
    /* 380AC 800374AC 14430005 */  bne        $v0, $v1, .L800374C4_380C4
    /* 380B0 800374B0 00000000 */   nop
    /* 380B4 800374B4 5487FFFA */  bnel       $a0, $a3, .L800374A0_380A0
    /* 380B8 800374B8 90820000 */   lbu       $v0, 0x0($a0)
  .L800374BC_380BC:
    /* 380BC 800374BC 03E00008 */  jr         $ra
    /* 380C0 800374C0 00001025 */   or        $v0, $zero, $zero
  .L800374C4_380C4:
    /* 380C4 800374C4 03E00008 */  jr         $ra
    /* 380C8 800374C8 24020001 */   addiu     $v0, $zero, 0x1
    /* 380CC 800374CC 00000000 */  nop
.size bcmp, . - bcmp
