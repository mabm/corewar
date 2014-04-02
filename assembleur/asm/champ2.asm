: Le bombardier mobile
: balance un DAT puis se deplace
:mov #0 30 : balance le DAT en avant
mov @9 @10 : copie adresse depart vers adresse destination
add #1 8 : ajoute 1 a adresse depart
add #1 8 : ajoute 1 a adresse destination
cmp #0 6 : si tout a ete copie...
jmp 2 : ... saute en fin de la duplication
jmp -5 : retourne au mov @11 @12
mov #-10 16 : cree un DAT -10 a la fin de la copie
mov #2 16 : cree un DAT 2 a la fin de la copie
jmp 4 : saute au debut de la copie
dat -10 : adresse depart
dat 2 : adresse destination