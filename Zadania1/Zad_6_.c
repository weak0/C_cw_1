#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compareMoves(int player, int computer) {
    if (player == computer) {
        return 2; // Tie
    } else if ((player == 0 && computer == 2) ||
               (player == 1 && computer == 0) ||
               (player == 2 && computer == 1)) {
        return 0; // Player wins
    } else {
        return 1; // Computer wins
    }
}

void gameLogic(char *moves[], char *scores[], char *dbResult[], int game) {
    printf("\n");
    for (int i = 0; i < 3; ++i) {
        printf("%d. %s\n", i+1, moves[i]);
    }
    printf("Wybierz ruch: ");

    int playerChose;
    scanf("%d", &playerChose);
    playerChose--;

    srand(time(NULL)); // seed random generator
    int computerChose = rand() % 3;

    int result = compareMoves(playerChose, computerChose);
    char *resultString = scores[result];
    printf("Wybrales: %s, komputer wybral: %s, wynik: %s\n", moves[playerChose], moves[computerChose], scores[result]);
    dbResult[game] = resultString;
}

void printScores(char *dbResult[], int gameNumber) {
    printf("\nWyniki:\n");
    for (int i = 0; i < gameNumber; i++) {
        printf("%d. %s\n", i+1, dbResult[i]);
    }
}

int main() {
    char *moves[3] = {"papier", "kamien", "nozyce"};
    char *scores[3] = {"wygrana", "przegrana", "remis"};
    char *dbResult[100]; // Assuming maximum 100 games
    int continueGame;
    int gameNumber = 0;

    do {
        gameLogic(moves, scores, dbResult, gameNumber);
        gameNumber++;
        printf("\nAby wyswietli  wyniki wpisz 1 lub 0 aby kontynuowac: ");
        int command;
        scanf("%d", &command);
        if (command == 1) {
            printScores(dbResult, gameNumber);
        }

        printf("\nCzy chcesz zagrac jeszcze raz? (0 - nie, 1 - tak): ");
        scanf("%d", &continueGame);
    } while (continueGame == 1);

    return 0;
}
