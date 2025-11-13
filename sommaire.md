# Compiler un test simple
gcc test.c -lmlx -framework OpenGL -framework AppKit
```

Testez les fonctions de base :
- `mlx_init()` : initialiser la connexion
- `mlx_new_window()` : créer une fenêtre
- `mlx_pixel_put()` : dessiner des pixels
- `mlx_xpm_file_to_image()` : charger des images
- `mlx_loop()` : boucle d'événements

### 3. **Découper le projet en modules**

**a) Parsing de la carte (.ber)**
- Lire le fichier ligne par ligne
- Vérifier que la carte est rectangulaire
- Vérifier les murs (entourée de '1')
- Valider les éléments : 1 joueur (P), au moins 1 collectible (C), 1 sortie (E)
- Vérifier qu'un chemin valide existe (utilisez un flood fill ou BFS)

**b) Gestion graphique**
- Initialiser MLX
- Charger les textures (sprites XPM)
- Afficher la carte initiale
- Rafraîchir l'affichage après chaque mouvement

**c) Gestion des événements**
- Hook clavier pour les déplacements
- Hook de fermeture de fenêtre (croix rouge + ESC)
- Logique de collision
- Compteur de mouvements

**d) Game logic**
- Gérer les déplacements du joueur
- Collecter les objets
- Condition de victoire (tous les collectibles + atteindre la sortie)

### 4. **Structure de fichiers recommandée**
```
so_long/
├── Makefile
├── includes/
│   └── so_long.h
├── srcs/
│   ├── main.c
│   ├── parsing/
│   │   ├── map_parser.c
│   │   ├── map_validation.c
│   │   └── path_checker.c
│   ├── graphics/
│   │   ├── init_mlx.c
│   │   ├── render.c
│   │   └── sprites.c
│   └── game/
│       ├── movement.c
│       ├── events.c
│       └── game_logic.c
├── maps/
│   ├── valid_map.ber
│   └── test_maps/
└── textures/
    ├── player.xpm
    ├── wall.xpm
    ├── collectible.xpm
    └── exit.xpm