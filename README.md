Dans cette partie 3 nous avons créé le fichier Decryptage.h qui permet, dans un premier temps, de vérifier si le texte passé
en argument peut être encodé par l'arbre que nous créons dans la partie 2.
Puis dans un second temps, si le texte est reconnu par l'arbre, nous utilisons une fonction de décryptage qui va
pour chaque chaine de 0 et de 1 dans le fichier que nous ouvrons en lecture, parcourir l'arbre et retrouver le caractère correspondant,
et ainsi l'afficher dans le fichier TexteDecodifie.txt.

Les tests de notre code sont réalisés dans la classe Main.

La partie interface graphique n'est pas implémentée.

Les commandes de compilation et d'éxécution à partir du dossier du projet sont : 
$ make
$ ./main
