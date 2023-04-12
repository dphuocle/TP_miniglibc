Question 5 :
- Parce que quand on utilise un malloc original, la zone memoire est init avec un valeur quelconque. Alors pour meilleur optimization, on
les alloue a '\0' 

Question 6 : 
- La fonction free en C vous permet de libérer ou de désallouer les blocs de mémoire précédemment alloués par les fonctions calloc(), malloc() ou realloc(). 
Il libère les blocs de mémoire et renvoie la mémoire au tas. Cela aide à libérer de la mémoire dans votre programme qui sera disponible pour une utilisation ultérieure. 
- La fonction free ne libere pas vraiment la memoire. Parce que, la focntion free renvoie la mémoire dans n'importe quel conteneur utilisé pour enregistrer la mémoire disponible.

Question 17 :
- Si nous afficherons une chaîne de caractères qui ne contient pas de saut de ligne dans la chaine de caractères ayant besoin d'imprimer, 
Il n'imprimera pas la chaine.

Question 20 :
- Dans ce cas, on ne peut pas indiquer la fin du buffer, parce que le buffer est un chaine de caracteres sans '\0'.
- Pour resoudre le probleme, on ecrit au plus (size_buffer - 1) caracteres au buffer.

Question 22 :
- Dans la fonction mini_strlen, si on n'indique pas le caractère '\0', le résultat peut etre faux.
-> Solution : Il faut indiquer le caractère '\0' à la fin de la chaine de caractères.
- Pour la fonction mini_strcpy, si la chaine destination a la taille plus courte que la chaine source, on ne peut pas 
recopier la chaine source dans la chaine destination.
-> Solution : Si la chaine destination a la taille plus courte que la chaine source, on recopie la chaine source jusqu'à la taille 
de la chaine destination.
- Pour la fonction mini_strcmp, nous ne traitons pas le cas que la taille de 2 chaines est différent.
-> Solution : Si s1>s2 ou s1 < s2, c'est-à-dire que le caractère au premier index que le caractère de 2 chaines à cet index de s1 est avant dans 
la table d'ASCII que celui de s2 et opposant, on va retourner -1;

Question 34 :
- Si on termine le programme quand le buffer d’écriture n’était pas plein, tous les infos qu’on veut écrire dans le fichier sera 
tout perdu, donc on doit ajouter le mini_fflush() lors de la termination du program dans mini_exit()