
// Exemple de code:
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // pour exit et rand

int simple_random(int n) // simple random generation of a integer between 0 and n
{
    return rand() % n;
}

std::vector<char> myBoard(35,'.');
std::vector<std::pair<int,int>> snake = {{1,1},{1,2},{1,3}};
int apple = 10;

void reset_board()
{
    for (int i = 0; i <= 35; ++i) {
        myBoard[i]='.';
    }
}

void generate_apple()
{ // qui génère une pomme
    apple = simple_random(35);
    while (myBoard[apple] == 'o' or myBoard[apple] == 'O'){
        apple = simple_random(35);
    }
}

void add_snake_to_board() // initialisé en haut à gauche
{ // qui met le serpent sur le board
    myBoard[(snake[0].first-1)*7 + snake[0].second-1] = 'O';
    for (int i=1; i< snake.size();i++){
        myBoard[(snake[i].first-1)*7 + snake[i].second-1] = 'o';
    }

    
}
void add_apple_to_board()
{ // qui met la pomme sur le board
        myBoard[apple]='@';


}

void draw_board()
{
    for (int i = 0; i <= 35; ++i) {
        if (i % 7 == 0)
        {
            std::cout<<std::endl;
        }
        std:: cout << myBoard[i];
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

        std::vector<std::pair<int,int>> snakeCopy = snake;
        std::vector<char> myBoardCopy = myBoard;
        std::cin >> key; // on attend que l'utilisateur entre un caractère au clavier
        if (key)
        {
            if ((key == 'i') or (key == 'k') or (key == 'j') or (key == 'l'))
            {
                if (key == 'i'){
                    snake.insert(snake.begin(), {snake[0].first-1, snake[0].second});
                    snake.pop_back();
                }

                if (key == 'j'){
                    snake.insert(snake.begin(), {snake[0].first, snake[0].second-1});
                    snake.pop_back();
                }

                if (key == 'k'){
                    snake.insert(snake.begin(), {snake[0].first+1, snake[0].second});
                    snake.pop_back();
                }

                if (key == 'l'){
                    snake.insert(snake.begin(), {snake[0].first, snake[0].second+1});
                    snake.pop_back();
                }
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
        if ( myBoardCopy[(snake[0].first-1)*7 + snake[0].second-1] == '@'){
            snake.push_back(snakeCopy[-1]);
            generate_apple();

        }
    }
}


int main()
{
    // exemple où on génère un nombre aléatoire entre 0 et 35
    // (par exemple cela vous donne une case sur un board de 5 lignes 7 colonnes pour y placer une pomme
    //  si il n'y a pas de bout de serpent à cet endroit...)
    // Il manque tous les objets (le board, le serpent, la pomme).
    // Dans un premier temps, vous pouvez utiliser des variables globales pour stocker ces objets
    //                        que vous manipulez alors directement dans des fonctions
    // dans un second temps, vous devez proposer une structure de classes
    play_game();
    return EXIT_SUCCESS;
}
