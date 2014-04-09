.name "Zork"
.comment "Wahoo, un commentaire O_O"
sti r1, %:live, %:label
label:	sti %2, r3, %42
and r1, %0, r1
live: live %1
zjmp %:live
label:	%45