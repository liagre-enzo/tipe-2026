# tipe-cycles-boucles

Git pour le tipe 2026, thème Cycles et boucles.

## Différentes idées parcourues

A la date du 12/02 :

- La machine récursive, avec l'os le language type assembleur...
- d'Adrien, les assistants de preuves, sujet plutôt chargé en maths

A la date du 6/03 :

- bug de l'an 2038

Retenu le 13/03 :

- Comment finir un roguelike : Essaie de finir chaque partie lancer à l'aide des instructions d'un algorithme.
Mèle de la th des graphes et des probas.
À finir sur réussir à faire jouer l'ordinateur seul.

## Balatro

### Partie 1 : Knowing the seed

Objectif : En connaissant la graine réussir à finir une run de Balatro grâce à un logiciel

-> Il s'agit d'un problème de recherche de chemin puisque l'on peut représenter l'état du jeu par un graphe (voir un arbre).

On dénombre plusieurs étapes importantes :

- Réussir à récupéer la seed dans la mémoire du jeu
- À partir de la seed réussir à générer l'état du jeu
- à partir d'un deck et de jokers donnés, trouvé la configuration qui permet de terminer une étape.
- finir le jeu en prenant des jokers sur la route

#### Première stratégie en tête

1. Trouver les chemins donnant le plus de points à chaque étape.
2. Prendre les jokers en fonction des chemins pris (i.e. ceux qui rapporte les meilleurs résultats)
3. Si on ne tout de même pas passer une étape malgrè cela, refaire le chemin avec le joker

### Partie 2 : Without the seed

Objetctif: Lancé le logiciel sur une partie random et réussir à finir le jeu

-> pb de probabilités et de débombrement.

On a encore plusieurs étapes importantes :

- Réussir à choisir la main qui rapporte le plus de points à partir d'un deck
- réussir à finir une manche
- réussir un finir un boss (i.e. prendre en compte les malus)
- faire le meilleur choix de joker
- gérer l'argent
- tout reconstituer

⚠️ À faire en dernier car compliqué.
