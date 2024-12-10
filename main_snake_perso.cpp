
// Exemple de code:
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // pour exit et rand

vector<char> board(35) ;
// board ={.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.}

void reset_board() {        // qui ré-initialise le board

}
void generate_apple() {     // qui génère une pomme

}
void add_snake_to_board() { // qui met le serpent sur le board

}
void add_apple_to_board() { // qui met la pomme sur le board

}


void draw_board()
{ // qui affiche le board
    // bien sûr c'est n'importe quoi cette fonction qui affiche des '.' sur 5 lignes et 7 colonnes...
    // Il faut repenser tout le programme pour afficher le board que vous avez créé en début de partie (de la taille désirée)
    // et dans lequel vous aurez mis le serpent et la pomme.
    // Vous pouvez supprimer ou rajouter des fonctions et surtout faire des classes.
    int i {0};
    for (char c : board){
    std::cout<<c;
    if (i%7 == 0){
        std::cout<<"/n";
    }
    i += 1;
    }

}

void print_message(const std::string &msg) // qui affiche un message
{                                          // const (pour ne pas modifier le message dans la fonction)
                                           // &     (pour ne pas le recopier on le passe par référence)
    std::cout << msg;
}

// la fonction play_game() qui gère le jeu serait alors une boucle sans fin dans le genre :
void play_game()
{

    // Supposons qu'on dispose d'un board de rows lignes et columns colonnes (ici resp. 5 et 7).
    //                         d'un serpent de taille 3 et d'une pomme

    // Le jeu est alors une boucle sans fin qui:
    //   - attend que le joueur tape sur une touche
    //   - fait l'action demandée
    //   - et recommence ou échoue.

    // Le caractère pour stocker la clé qui sera entrée au clavier.
    char key;
    while (true)
    {
        reset_board();        // on réinitialise le board
        add_snake_to_board(); // on ajoute le serpent au board
        add_apple_to_board(); // on ajoute la pomme au board
        draw_board();         // on affiche le board
        print_message("what do you want to do ('q' to quit):");

        std::cin >> key; // on attend que l'utilisateur entre un caractère au clavier
        if (key)
        {
            if ((key == 'i') or (key == 'k') or (key == 'j') or (key == 'l'))
            {
                // on sait calculer la case dans laquelle la tête du serpent doit aller
                //    si il y a une pomme dans cette case: il la mange et il grandit
                //    si il se mange lui-même ou sort du board: on quitte le jeu
                //    sinon on déplace le serpent
                // et on recommence la boucle sans fin
            }
            else if (key == 'q')
            {
                print_message("bye bye !\n");
                exit(0); // l'utilisateur demande à quitter le jeu
            }
            // sinon une clé inconnue a été entrée: on ne fait rien...

            // mais on pourrait ajouter des fonctionnalités par exemple:
            // si l'utilisateur tape 's', vous pouvez sauver l'état du jeu dans un fichier pour le reprendre plus tard
            // et passer le fichier en argument à votre programme pour reprendre le jeu
        }
    }
}

int simple_random(int n) // simple random generation of a integer between 0 and n
{
    return rand() % n;
}

int main(int argc, char **argv)
{
    // exemple où on génère un nombre aléatoire entre 0 et 35
    // (par exemple cela vous donne une case sur un board de 5 lignes 7 colonnes pour y placer une pomme
    //  si il n'y a pas de bout de serpent à cet endroit...)
    std::cout << simple_random(35) << std::endl;
    draw_board();
    // Il manque tous les objets (le board, le serpent, la pomme).
    // Dans un premier temps, vous pouvez utiliser des variables globales pour stocker ces objets
    //                        que vous manipulez alors directement dans des fonctions
    // dans un second temps, vous devez proposer une structure de classes
    // play_game();
    return 0;
}
