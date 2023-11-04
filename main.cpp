#include <iostream>
#include "Game.h"

using namespace std;

int main() {
    std::cout << "___________.__         ___________               ___________            \n"
                 "\\__    ___/|__| ____   \\__    ___/____    ____   \\__    ___/___   ____  \n"
                 "  |    |   |  |/ ___\\    |    |  \\__  \\ _/ ___\\    |    | /  _ \\_/ __ \\ \n"
                 "  |    |   |  \\  \\___    |    |   / __ \\\\  \\___    |    |(  <_> )  ___/ \n"
                 "  |____|   |__|\\___  >   |____|  (____  /\\___  >   |____| \\____/ \\___  >\n"
                 "                   \\/                 \\/     \\/                      \\/" <<
              std::endl;
    Player player1('X'), player2('O');
    Game game(player1, player2);
    game.play();

    return 0;
}
