addi	$v0	$zero	9	#load syscall code to allocate heap
addi	$a0	$zero	27	#26 bytes / characters plus one null terminator
syscall
add	$t0	$v0	$zero	#store pointer to allocated memory for the loop
add	$t4	$v0	$zero	#store pointer to allocated memory for printing

addi	$t1	$zero	65	#store 'A' in $t1
addi	$t2	$zero	1	#initialize counter

LOOP:
sb	$t1	0($t0)		#store letter in $t0 offset by counter
addi	$t0	$t0	1	#incremenet heap pointer
addi	$t1	$t1	1	#increment letter
addi	$t2	$t2	1	#increment counter
bne	$t2	$a0	LOOP

add	$t1	$zero	$zero	#load null character
sb	$t1	0($t0)		#store null character
add	$a0	$t4	$zero	#load starting address for printing
addi 	$v0	$zero	4	#load the print op code
syscall