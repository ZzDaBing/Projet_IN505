Dans cette partie 2 nous avons créé le fichier Cryptage.h qui permet, dans un premier temps, de lire
un fichier texte en entrée et de trouver toutes les occurrences des lettres contenues dans ce
fichier texte pour les implémenter dans un tableau.
Puis dans un second temps, on utilise ensuite ce tableau pour trier les occurrences  et utilisons 
un vecteur pour construire notre arbre.
Nous avons rencontré quelques problèmes lors de la construction de notre arbre et avons donc
fait quelques ajustements de la classe ArbreB afin de régler ces problèmes.
Par la suite, dans la classe ArbreB nous avons créé une fonction utilisant l'arbre obtenu pour
codifier le texte, renvoyant un string.
Enfin, nous créons un fichier en écriture et nous lisons caractère par caractère
le premier fichier passé en paramètre , et affichons son code en parallèle dans le fichier
créé ouvert en écriture.
Les tests de notre code sont réalisés dans la classe Main.

La partie interface graphique n'est pas implémentée.

Les commandes de compilation et d'éxécution à partir du dossier du projet sont : 
$ make
$ ./main
