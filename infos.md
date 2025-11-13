📁 Fichiers créés
Header

so_long.h - Toutes les structures et prototypes

Parsing

map_parser.c - Lecture du fichier .ber / griller les lignes (sans "\n") / remplir game->map
map_validation.c - Validation de la carte / check walls, rectangular, elements
path_checker.c - Vérification du chemin avec flood fill

Graphics

init_mlx.c - Initialisation de MLX et chargement des sprites
render.c - Rendu de la carte et de l'interface

Game

movement.c - Gestion des déplacements
events.c - Gestion des événements clavier
game_logic.c - Logique de collecte et victoire

Utils

error.c - Gestion des erreurs
cleanup.c - Libération de la mémoire

Main

main.c - Point d'entrée du programme

Exemple

valid_map.ber - Carte de test

⚠️ Points importants à ne pas oublier
1. Vous devez avoir :

Une libft fonctionnelle avec get_next_line
La MiniLibX installée

2. Créer les sprites :
Créez un dossier textures/ avec 5 fichiers .xpm (64x64 pixels) :

player.xpm
wall.xpm
empty.xpm
collectible.xpm
exit.xpm