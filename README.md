# Fonctionnalitées de notre jeu Akari

## PICQUE Kylian & STEIMETZ Tangui

### Sommaire

- [Fonctionnalitées de notre jeu Akari](#fonctionnalitées-de-notre-jeu-akari)
  - [PICQUE Kylian \& STEIMETZ Tangui](#picque-kylian--steimetz-tangui)
    - [Sommaire](#sommaire)
    - [Le Jeu](#le-jeu)
    - [Archhitecture](#archhitecture)
      - [Modèles](#modèles)
      - [Les Vues](#les-vues)
      - [Le Présenteur](#le-présenteur)
    - [Les patrons de conceptions](#les-patrons-de-conceptions)
      - [Le Décorateur](#le-décorateur)
      - [L'Etat](#letat)
      - [Commande](#commande)
      - [Chaîne de responsabilité](#chaîne-de-responsabilité)
      - [Observateur ?](#observateur-)

### Le Jeu

### Archhitecture

***MVP*** :
Nous avons utilisé l'architecture **MVP** pour la conception du projet tout en respectant le fait que chaque classe soit à responsabilité unique.

#### Modèles

Les modèles s'occupent de charger les données nécéssaires du jeu et de les gérer suivant les commandes choisies par l'utilisateurs.

- *Le modèle de chargement de cartes* :
Ce modèle permet de charger une map selon les critères choisis par l'utilisateur et retour au présenteur les classes corréspondantent à chaque case.

- *Le modèle de gestions du jeu* :
Ce modèle permet de communiquer avec ces deux sous-modèles :

  - *Le modèle de gestions des Cellules* :
        Ce modèle a pour responsabilité de gérer et vérifier les états des Cellules qui sont initiallement vierges. C'est à dire de faire transiter correctement les états des Cellules suivant les choix de l'utilisateur. Il gère si les conditions de victoire liées aux cellules à éclairer sont remplis.

  - *Le modèle de gestions des Mûrs* :
        Ce modèle a pour responsabilité de gérer et vérifier les états des Cellules qui sont initiallement des mûrs. C'est à dire qu'il va faire transiter les mûrs dans leur état valide ou non suivant l'achèvement des contraintes, il doit donc communiquer avec le modèle précédent pour observer les états extérieurs. Il gère si les conditions de victoire liées aux mûrs sont remplis.

#### Les Vues

Les vues se chargent uniquement d'afficher les différents composants de l'interface graphique et la scène du jeu suivant les options renseignées par le Présenteur / Modèle.

Pour le visuel du jeu, nous avons choisi d'utiliser un *QGraphicsView* et un *QGraphicsScene* qui n'ont pas été vu en cours afin d'explorer de nouvelles fonctionnalitées de ***QT***. Ceux-ci nous permet une grande flexibilité, une plus grande personnalisation et beaucoup de contrôles sur les *Items* que l'ont peut insérer dans la Scène.

Dans un premier temps, nous avons surchargé des éléments nommés *QGraphicsRectItem* pour que ceux-ci repondent au besoin du jeu, c'est-à-dire que chaque élément sont indépendants les uns des autres et possèdent un arrière-plan ce qui sera une couleur (blanc, noir, jaune) et une premier-plan ce qui sera une image (un nombre, une ampoule jaune ou rouge).

Chaque élément est placé dans une Scène et doit être correctement placé, nous avons donc surchargé une Scène pour chargé chaque élément puis le placer, et surtout les centrer pour que le jeu soit au milieu de la vue.

C'est pourquoi nous avons également dû surcharger la Vue pour qu'à chaque fois que l'utilisateur modifie la taille de la fenêtre, la Vue transmet l'information à sa Scène puis celle-ci modifie l'echelle des éléments qui lui ont été ajouté.

#### Le Présenteur

Il y a un unique présenteur qui permet de gérer la logique de présentation (chronomètre par exemple) mais également de transmettre les informations entre les entrées de l'utilisateur et les impactes sur les modèles et rémonter l'information jusqu'à la vue.

### Les patrons de conceptions

Lors que la conception de notre jeu, nous avons fait le choix de privilégier le fait d'utiliser de nombreux patrons de conception au-lieu d'ajouter de nombreuses fonctionnalités. Cela dans le but d'avoir une application lisible, facile à maintenir et qui puisse nous permettre de nous entraîner sur les patrons de conpetions.

#### Le Décorateur

Le patrons de conception **Décorateur** a été utilisé pour "décorer" l'arrière plan et le premier plan des cases dites 'vierges'.
On peut ainsi les décorer d'un arrière plan :

- Vierge (blanc);
- Mûr (noir);
- Illuminé (jaune).

Ou encore d'un premier plan :

- Numéro de couleurs vert ou blanc (utilisé par les Mûrs);
- Une image d'ampoule valide (jaune) ou invalide (rouge);
- Une image d'une croix.

Nous avons conscience que ce patrons n'est pas spéciallement adapté pour une petite application où les choix possibles sont déjà pre-déterminés par les règles du jeu. Ou encore très lourd pour et compliqué pour une si petite application.

Cependant, le but était de s'entrainner à l'utilsiation de patrons de conceptions en C++ et de gérer correctement la mémoire.

#### L'Etat

Le patron de conception **état** a été utiliser pour changer automatiquement la décoration suivant l'état de transition a effectuer :

- Clic gauche -> Placer / Enlever une ampoule ou une croix dans un certains sens du cycle (impossible sur un Mûr);
- Clic droit -> Placer / Enlever une ampoule ou une croix dans l'autre sens du cycle (impossible sur un Mûr);
- Mise-à-jour -> Illuminer ou Eteindre la cellule (Rendre vert ou blanc le chiffre).

Ce patrons a rendu l'implémentation des contraintes liées à la gestion du jeu très facile. Nous pensons que ce patrons a été un choix assez judicieux et un très bon entrainnement aux patrons en C++ également.

#### Commande

Le patron de conception **commande** nous a été très utile pour pouvoir faire les actions de *retour en arrière*. En effet, c'est un patron qui est largement utilisé pour faire ce genre d'action.

On donc dû définir les commandes suivantes :

- Le clic droit quoi permet de poser une ampoule, une croix puis rien
- Le clic gauche qui fait le cycle inverse que le clic droit en partant de la croix
- Le retour en arrière qui permet d'annuler la dernière action.

Le commande passe par le présenter pour communiquer les actions aux autres models.

#### Chaîne de responsabilité

Le patron **chaîne de responsabilité** nous a été très utile lors de la lecture de la map lorsqu'elle n'est qu'un string. En effet nous ne voulions pas transmettre directement la chaîne de caractère au modèle qui créer la map mais plutôt directement les éléments à disposer.

La chaîne de responsabilité nous permet donc de lui donner un char et elle nous revoie l'élément de map adapté.

#### Observateur ?

Nous aurions également voulu implémenter le patron **Observateur** pour que le jeu soit autonome et qu'il puisse se gérer sans modèle extérieur verifiant les contraintes.
Explication : Le but aurait été que chaques cellules observent ses cellules adjacentes et mettent à jour son état suivant l'état du voisin. Puis le cellule transmet à son tour, aux cellules qui l'observent, un signal.
