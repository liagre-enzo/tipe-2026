# tipe-cycles-boucles

Git pour le tipe 2026, thème Cycles et boucles.

## Différentes idées parcourues

### A la date du 12/02

- La machine récursive, avec l'os le language type assembleur...
- d'Adrien, les assistants de preuves, sujet plutôt chargé en maths

### A la date du 6/03

- bug de l'an 2038

### Retenu le 13/03

- Comment finir un roguelike : Essaie de finir chaque partie lancer à l'aide des instructions d'un algorithme.
Mèle de la th des graphes et des probas.
À finir sur réussir à faire jouer l'ordinateur seul.

Cette idée a été abandonné courrant juin. L'une des stratégie était trop intrusive au niveau du jeu au point de demander de modifier le code source du jeu, chose que je veux absolument éviter.

### Nouvelle piste, à présenter

- Comment émuler un logiciel ?
  - Intéressant sur le plan théorique de l'architecture matérielle.
  - On se servira de *Pokémon Rouge* pour essayer d'implémenter du low et high level emulation. Autrement dit la partie investisement du tipe se repose sur un exemple.

## Présentation du sujet

### Lien avec cycles et boucles

Le sujet n'a pas de lien direct avec le thème, comme on pourrait imaginer un sujet être autour d'un algorithme itératif par exemple. Le lien se fait sur l'idée de l'émulation; avec l'évolution des systèmes d'exploitations, la rétrocompatibilité (bien que celle-ci peut déjà être considérer comme une forme d'émulation), n'est pas viable et pose des contraintes sur l'évolution des systèmes.

Il est donc indispensable pour la conservation de logiciel de se trourner vers ces méthodes. Si l'on prend en compte le fait que les différents systèmes d'exploitations, et que le jeu-vidéo est un art depuis 2018, l'interêt de l'émulation devient presque évident; pour l'histoire de l'informatique et la conservation des arts.

### Émulation

On se tournera pendant tous se tipe sur une image (ou ROM) de *Pokémon Version Rouge* (développé par Game Freak), dans le but de l"émuler sur une machine opérant sous linux. Il s'agit ici d'un exemple comme un autre, on aurait bien pu prendre un système d'exploitation quelconque ou un autre logiciel, le choix ne s'est fait qu'à partir de préférences personnelles.

On se donne alors comme projet de créer une interface pour du low-level emulation et du high-level emulation pour un jeu Gameboy.

NB :

- L'appellation ROM pour les images à émuler n'est pas sans rappeler la Read Only Memory en architecture matériel, et en effet cela a bien une corrélation; si l'on retourne dans le passer, un fichier image n'est que le contenu de la mémoire morte d'une cartouche.

- La copie de *Pokémon Version Rouge* n'est utilisée que pour la recherche et ne sera partagé.

Toutes les sources sont disponibles [ici](ressources/sources.md).

La présentation de première année est disponible [ici](latex/presentation_premiere_annee/presentation.pdf) en format pdf.
