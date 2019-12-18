AutomaticMailAnswering: gestion_de_fichier.o gestion_de_reponses.o mainHotelBooking.o
	gcc -o AutomaticMailAnswering gestion_de_fichier.o mainHotelBooking.o gestion_de_reponses.o

mainHotelBooking.o: Sources/mainHotelBooking.c Headers/e_mail.h Headers/gestion_de_fichier.h Headers/keywords.h Headers/reponses.h
	gcc -c -Wall Sources/mainHotelBooking.c

gestion_de_fichier.o: Sources/gestion_de_fichier.c Headers/gestion_de_fichier.h
	gcc -c -Wall Sources/gestion_de_fichier.c

gestion_de_reponses.o: Sources/gestion_de_reponses.c Headers/reponses.h
	gcc -c -Wall Sources/gestion_de_reponses.c
