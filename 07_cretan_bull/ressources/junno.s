.name "JUNNO"
.comment "ADIOS MOTHER FUCKERS!!!!!!!!!!!!!!!!!!!!"

live:	live %1
		fork %-10

protect:
		zjmp %:live
		ld %20, r4
		st r4, -200
		zjmp %:protect
