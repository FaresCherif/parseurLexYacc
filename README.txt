//Fares Cherif

Code réalisé seul par FARES CHERIF meme si "theoriquement" en binome avec Abel AMOUH 

Exercice final : 5 ( non fini)

Il se trouve dans l'archive :

- un makefile pour lancer le projet
- parser.yy est le yacc et lexer.ll est le lex . Ils servent à définir la grammaire du Language
- Variable.h sert a creer la liste des variables
- Position.h contient la classe permettant de savoir la position actuelle du crayon
- demo est l'executable du projet , pour le lancer il faut donner un fichier en paramettre
- dessin1.txt ( carree noir avec diagonales bleu),dessin2.txt (quadrillage) et dessin3.txt (erreur affectation dans boucle)
  sont des exemples de fichiers 
- visiteur.hh, printer.hh et printer.cc servent tout les trois à faire le design pattern visiteur.
  Les fonctions se trouvent dans printer.cc
- carree.cc/hh , ligne.cc/hh , couleur.cc/hh  sont des classes "block" qui servent à remetter des infos et a pouvoir 
  etre appele par le parseurs
- while.cc/hh est une classe "block" a ete legerement modifier car il ne s'agit pas d'un while classique d'apres le sujet.
  Il a desormais une variable, une valeur initial (varMin) et une valeur finale (varMax)
- le reste des classes sont également des classes blocs, celles-ci non modifies



Une variable declare a par defaut comme valeur 0

Le lex a ete legerement modifie au cours du projet afin d'avoir le moins d'operateur possible et d'avoir la grammaire 
la plus comprehensible possible.

Comme demande, toute les commandes sont suivis d'un poit-virgule pour preciser qu'elle est fini. Cela est egalement vrai
pour les expression sans valeur ( epsilon comme possible dans DESSIN) qui sont donc uniquement compose d'un point-virgule.

Les fichiers acceptes commencent forcement par DEBUTPROGRAMME, cela permet de cree le tableau contenant les variables. On y
met une premiere variable qui servira de premiere tete de liste . Cette variable a des espaces dans son nom ce qui la rend
non appelable puisque les variables acceptés n'ont pas d'espace.


Pour la boucle plusieurs verifications sont faites :
- la variable de la boucle ne doit pas etre modifie (les variable ont un boolean qui est mis a trou en debut de boucles se
  qui lance une erreur si cette fonction essaye d'tre affecter une valeur. Le boolean est remis a faux a la fin de la 
  boucle
- la valeur initial doit etre strictement inferieur a la valeur final
- la variable donne doit etre declarer ( on cherche dans la liste des variables si on la retrouve, 
  sinon on lance une erreur;


Un fichier visuel 