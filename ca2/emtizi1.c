
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define length 15
#define width 30

void shuffle_card(int *card);
void pakhsh(int array[4][44]);
void equal_to(int h, int w, int array[h][w]);
void sbuffer(int array[4][44], int ssymbol[11], int snumber[11], int *scounter, int count);
void f_value(int size, int array[size]);
void show(int snumber[11], int ssymbol[11], int selectedsym[4], int selectednum[4], int counter, int bool, int *selsymbol1, int *selnumber1, int hokm); //
void board(int selectednum[4], int selectedsym[4], int winner, int hokm, int point1, int point2, int set1, int set2);
int flush(void);
void sort(int symbol[], int number[], int size);
void winnerbot(int number[], int symbol[], int selectednum[], int selectedsym[], int hokm, int counter, int *selsymbol, int *selnumber);       //
void bot(int number[], int symbol[], int selectednum[], int selectedsym[], int counter, int winner, int hokm, int *selsymbol, int *selnumber); //
void printsymbol(int selectedsym);
void printnumber(int selectednum);
int iswinner(int selectedsym[4], int selectednum[4], int hokm, int selsymbol1, int selnumber1, int selsymbol2, int selnumber2, int selsymbol3, int selnumber3, int selsymbol4, int selnumber4);
void point(int *point1, int *point2, int winner);
void reset(int selectednum[], int selectedsym[]);
int check(int symbol[11], int hokm);
int main()
{
    int set1 = 0;
    int set2 = 0;
    while (set1 < 5 && set2 < 5)
    {
        /*whats the hokm*/
        int hokm = -1;
        char hokms;
        /*counter for selected cards*/
        int counter = 0;
        /*winner person*/
        int winner = 0;
        /*teams points*/
        int point1 = 0;
        int point2 = 0;
        /*all of cards*/
        int cards[4][44];
        equal_to(4, 44, cards);
        pakhsh(cards);

        /*selected cards*/
        int selectedsym[4];
        int selectednum[4];
        f_value(4, selectedsym);
        f_value(4, selectednum);
        int selsymbol1;
        int selnumber1;
        int selsymbol2;
        int selnumber2;
        int selsymbol3;
        int selnumber3;
        int selsymbol4;
        int selnumber4;

        /*boolian for panel*/
        int bool = 0;
        /*player1 cards*/
        int ssymbol1[11];
        int snumber1[11];
        f_value(11, snumber1);
        f_value(11, ssymbol1);
        int scounter1 = 0;

        /*player2 cards*/
        int ssymbol2[11];
        int snumber2[11];
        f_value(11, snumber2);
        f_value(11, ssymbol2);
        int scounter2 = 0;

        /*player3 cards*/
        int ssymbol3[11];
        int snumber3[11];
        f_value(11, snumber3);
        f_value(11, ssymbol3);
        int scounter3 = 0;

        /*player4 cards*/
        int ssymbol4[11];
        int snumber4[11];
        f_value(11, snumber4);
        f_value(11, ssymbol4);
        int scounter4 = 0;

        int scan;
        sbuffer(cards, ssymbol1, snumber1, &scounter1, 5);
        sbuffer(cards, ssymbol2, snumber2, &scounter2, 5);
        sbuffer(cards, ssymbol3, snumber3, &scounter3, 5);
        sbuffer(cards, ssymbol4, snumber4, &scounter4, 5);
        board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);

        show(snumber1, ssymbol1, selectedsym, selectednum, counter, bool, &selsymbol1, &selnumber1, hokm);
        bool = 1;
        printf("hokm ro entekhab kon: \n");
        do
        {
            printf("enter A , B , C or D: ");
            scanf("%c", &hokms);
            scan = flush();
        } while (hokms != 'A' && hokms != 'a' && hokms != 'B' && hokms != 'b' && hokms != 'C' && hokms != 'c' && hokms != 'D' && hokms != 'd' || scan == 1);
        /*change hokme*/
        if (hokms == 'A' || hokms == 'a')
            hokm = 0;
        else if (hokms == 'B' || hokms == 'b')
            hokm = 1;
        else if (hokms == 'C' || hokms == 'c')
            hokm = 2;
        else if (hokms == 'D' || hokms == 'd')
            hokm = 3;

        sbuffer(cards, ssymbol1, snumber1, &scounter1, 4);
        sbuffer(cards, ssymbol2, snumber2, &scounter2, 4);
        sbuffer(cards, ssymbol3, snumber3, &scounter3, 4);
        sbuffer(cards, ssymbol4, snumber4, &scounter4, 4);
        sbuffer(cards, ssymbol1, snumber1, &scounter1, 2);
        sbuffer(cards, ssymbol2, snumber2, &scounter2, 2);
        sbuffer(cards, ssymbol3, snumber3, &scounter3, 2);
        sbuffer(cards, ssymbol4, snumber4, &scounter4, 2);

        board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
        show(snumber1, ssymbol1, selectedsym, selectednum, counter, bool, &selsymbol1, &selnumber1, hokm);
        counter++;
        /*playerS act*/
        bot(snumber4, ssymbol4, selectednum, selectedsym, counter, winner, hokm, &selsymbol4, &selnumber4);
        getchar();
        board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
        counter++;
        bot(snumber3, ssymbol3, selectednum, selectedsym, counter, winner, hokm, &selsymbol3, &selnumber3);
        getchar();
        board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
        counter++;
        bot(snumber2, ssymbol2, selectednum, selectedsym, counter, winner, hokm, &selsymbol2, &selnumber2);
        getchar();
        board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
        winner = iswinner(selectedsym, selectednum, hokm, selsymbol1, selnumber1, selsymbol2, selnumber2, selsymbol3, selnumber3, selsymbol4, selnumber4);
        point(&point1, &point2, winner);
        counter = 0;
        reset(selectednum, selectedsym);

        while ((point1) < 6 && (point2 < 6))
        {
            if (winner == 0)
            {
                getchar();
                board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
                show(snumber1, ssymbol1, selectedsym, selectednum, counter, bool, &selsymbol1, &selnumber1, hokm);
                counter++;
                bot(snumber4, ssymbol4, selectednum, selectedsym, counter, winner, hokm, &selsymbol4, &selnumber4);
                getchar();
                board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
                counter++;
                bot(snumber3, ssymbol3, selectednum, selectedsym, counter, winner, hokm, &selsymbol3, &selnumber3);
                getchar();
                board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
                counter++;
                bot(snumber2, ssymbol2, selectednum, selectedsym, counter, winner, hokm, &selsymbol2, &selnumber2);
                getchar();
                board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
                winner = iswinner(selectedsym, selectednum, hokm, selsymbol1, selnumber1, selsymbol2, selnumber2, selsymbol3, selnumber3, selsymbol4, selnumber4);
                point(&point1, &point2, winner);
                counter = 0;
                reset(selectednum, selectedsym);
            }

            if (winner == 1)
            {
                winnerbot(snumber2, ssymbol2, selectednum, selectedsym, hokm, counter, &selsymbol2, &selnumber2);
                counter++;
                getchar();
                board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
                show(snumber1, ssymbol1, selectedsym, selectednum, counter, bool, &selsymbol1, &selnumber1, hokm);
                counter++;
                bot(snumber4, ssymbol4, selectednum, selectedsym, counter, winner, hokm, &selsymbol4, &selnumber4);
                getchar();
                board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
                counter++;
                bot(snumber3, ssymbol3, selectednum, selectedsym, counter, winner, hokm, &selsymbol3, &selnumber3);
                getchar();
                board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
                winner = iswinner(selectedsym, selectednum, hokm, selsymbol1, selnumber1, selsymbol2, selnumber2, selsymbol3, selnumber3, selsymbol4, selnumber4);
                point(&point1, &point2, winner);
                counter = 0;
                reset(selectednum, selectedsym);
            }

            if (winner == 2)
            {
                winnerbot(snumber3, ssymbol3, selectednum, selectedsym, hokm, counter, &selsymbol3, &selnumber3);
                getchar();
                board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
                counter++;
                bot(snumber2, ssymbol2, selectednum, selectedsym, counter, winner, hokm, &selsymbol2, &selnumber2);
                getchar();
                board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
                counter++;
                show(snumber1, ssymbol1, selectedsym, selectednum, counter, bool, &selsymbol1, &selnumber1, hokm);
                counter++;
                bot(snumber4, ssymbol4, selectednum, selectedsym, counter, winner, hokm, &selsymbol4, &selnumber4);
                getchar();
                board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
                winner = iswinner(selectedsym, selectednum, hokm, selsymbol1, selnumber1, selsymbol2, selnumber2, selsymbol3, selnumber3, selsymbol4, selnumber4);
                point(&point1, &point2, winner);
                counter = 0;
                reset(selectednum, selectedsym);
            }

            if (winner == 3)
            {
                winnerbot(snumber4, ssymbol4, selectednum, selectedsym, hokm, counter, &selsymbol4, &selnumber4);
                getchar();
                board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
                counter++;
                bot(snumber3, ssymbol3, selectednum, selectedsym, counter, winner, hokm, &selsymbol3, &selnumber3);
                getchar();
                board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
                counter++;
                bot(snumber2, ssymbol2, selectednum, selectedsym, counter, winner, hokm, &selsymbol2, &selnumber2);
                getchar();
                board(selectednum, selectedsym, winner, hokm, point1, point2, set1, set2);
                counter++;
                show(snumber1, ssymbol1, selectedsym, selectednum, counter, bool, &selsymbol1, &selnumber1, hokm);
                winner = iswinner(selectedsym, selectednum, hokm, selsymbol1, selnumber1, selsymbol2, selnumber2, selsymbol3, selnumber3, selsymbol4, selnumber4);
                point(&point1, &point2, winner);
                counter = 0;
                reset(selectednum, selectedsym);
            }
        }

        if (point1 == 6)
        {
            if (point2 == 0)
            {
                set1 += 2;
                printf("team1 got 2 setpoint!\n");
            }
            else
            {
                set1++;
                printf("team1 got 1 setpoint!\n");
            }
        }

        else if (point2 == 6)
        {
            if (point1 == 0)
            {
                set2 += 2;
                printf("team2 got 2 setpoint!\n");
            }
            else
            {
                set2++;
                printf("team2 got 1 setpoint!\n");
            }
        }
    }

    if (set1 >= 5)
    printf("team 1 won the game!\n");
    else if (set2 >= 5)
    printf("team 2 won the game!\n");
}

void point(int *point1, int *point2, int winner)
{
    if (winner == 0 || winner == 2)
    {
        *point1 += 1;
        printf("your team got a point!\n");
    }
    else if (winner == 1 || winner == 3)
    {
        *point2 += 1;
        printf("The opponent's team got a point!\n");
    }
}

void reset(int selectednum[], int selectedsym[])
{
    for (int i = 0; i < 4; i++)
    {
        selectedsym[i] = -1;
        selectednum[i] = -1;
    }
}

int flush(void)
{
    int output = 0;
    while (getchar() != '\n')
    {
        output = 1;
    }
    return output;
}

void shuffle_card(int *card)
{
    int i, r, temp;
    for (temp = 0, i = 0; temp < 44; i++, temp++)
        card[temp] = i;
    srand(time(NULL));
    for (i = 43; i > 0; i--)
    {
        r = rand() % i;
        temp = card[i];
        card[i] = card[r];
        card[r] = temp;
    }
}

void pakhsh(int array[4][44])
{
    int card[44];
    shuffle_card(card);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 44; j++)
        {
            if (i == (card[j] / 11))
            {
                array[i][j] = (card[j] % 11);
            }
        }
    }
}

void equal_to(int h, int w, int array[h][w])
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            array[i][j] = -1;
        }
    }
}

void sbuffer(int array[4][44], int ssymbol[11], int snumber[11], int *scounter, int count)
{
    int c = 0;

    for (int j = 0; j < 44; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (array[i][j] != -1 && c < count)
            {
                ssymbol[(int)*scounter] = i;
                snumber[(int)*scounter] = array[i][j] + 1;
                array[i][j] = -1;
                *scounter = 1 + *scounter;
                c++;
            }
        }
    }
}

void f_value(int size, int array[size])
{
    for (int i = 0; i < size; i++)
    {
        array[i] = -1;
    }
}

int check(int symbol[11], int selectedsym)
{
    for (int i = 0; i < 11; i++)
    {
        if (symbol[i] == selectedsym)
            return 0;
    }
    return 1;
}

void show(int snumber[11], int ssymbol[11], int selectedsym[4], int selectednum[4], int counter, int bool, int *selsymbol1, int *selnumber1, int hokm)
{
    int selectionnum;
    int scan;
    /*print up*/
    printf("        ");
    for (int i = 0; i < width - 8; i++)
    {
        printf("--");
    }
    printf("-");
    printf("\n");
    /*print symbol*/
    printf("symbol: |");
    for (int i = 0; i < 11; i++)
    {
        if (ssymbol[i] == -1)
        {
            printf(" - |");
        }
        else
        {
            if (ssymbol[i] == 0)
                printf(" A |");
            else if (ssymbol[i] == 1)
                printf(" B |");
            else if (ssymbol[i] == 2)
                printf(" C |");
            else if (ssymbol[i] == 3)
                printf(" D |");
        }
    }
    printf("\n");
    /*print numbers of cards*/
    printf("number: |");
    for (int i = 0; i < 11; i++)
    {
        if (snumber[i] == -1)
        {
            printf(" 0 |");
        }
        else
        {

            if (snumber[i] / 10 == 0)
                printf(" %i |", snumber[i]);
            else
                printf(" %i|", snumber[i]);
        }
    }
    printf("\n");
    /*print down*/
    printf("        ");
    for (int i = 0; i < width - 8; i++)
    {
        printf("--");
    }
    printf("-");
    printf("\n");
    /*print numbers */
    printf("         ");
    for (int i = 0; i < 11; i++)
    {
        printf(" %i  ", i);
    }
    printf("\n");
    printf("\n");
    /*get input*/

    if (bool != 0)
    {

        if (counter == 0 || check(ssymbol, selectedsym[0]) == 1)
        {
            do
            {
                printf("Choose your card : ");
                scanf("%i", &selectionnum);
                scan = flush();
            } while (selectionnum < 0 || selectionnum > 10 || snumber[selectionnum] == -1 || scan == 1);
        }

        else if (counter != 0)
        {
            do
            {
                printf("Choose your card : ");
                scanf("%i", &selectionnum);
                scan = flush();
            } while (selectionnum < 0 || selectionnum > 10 || snumber[selectionnum] == -1 || scan == 1 || ((selectedsym[0] != ssymbol[selectionnum])));
        }

        selectednum[counter] = snumber[selectionnum];
        selectedsym[counter] = ssymbol[selectionnum];
        *selsymbol1 = ssymbol[selectionnum];
        *selnumber1 = snumber[selectionnum];

        for (int i = 0; i < 11; i++)
        {
            if (selectionnum == i)
            {
                snumber[i] = -1;
                ssymbol[i] = -1;
            }
        }
    }
}

void printsymbol(int selectedsym)
{
    if (selectedsym != -1)
    {
        if (selectedsym == 0)
        {
            printf(" A");
        }

        if (selectedsym == 1)
        {
            printf(" B");
        }

        if (selectedsym == 2)
        {
            printf(" C");
        }
        if (selectedsym == 3)
        {
            printf(" D");
        }
    }
    else
        printf("  ");
}

void printnumber(int selectednum)
{
    if (selectednum != -1)
    {
        if (selectednum / 10 == 0)
            printf("%i ", selectednum);
        else
            printf("%i", selectednum);
    }
    else
        printf("  ");
}

void board(int selectednum[4], int selectedsym[4], int winner, int hokm, int point1, int point2, int set1, int set2)
{
    for (int l = -2; l <= length + 2; l++)
    {
        printf("");
        for (int w = -1; w <= width + 3; w++)
        {
            /*print up*/
            if (l == -1 && w == 0)
                printf("  ");

            else if (l == -1 && w > 0 && w < width + 2)
                printf("--");

            /*print l and r*/
            else if (l >= 0 && l <= length && l != 0 && l != length && l != length / 2 && w > 0 && w < width)
                printf("  ");

            else if (l >= 0 && l <= length && l != 0 && l != length && l != length / 2 && (w == 0 || w == width))
                printf("  |");

            /*print down*/
            if (l == length + 1 && w == 0)
                printf("  ");

            /*print p2*/
            else if (l == length / 2 && w == -1)
                printf("P4|");

            /*print player p3*/
            if (l == -2 && w == (width / 2) - 1)
                printf("  P3");
            else if (l == -2 && w != (width / 2))
                printf("  ");

            else if (l == 0 && w == 0)
                printf("|");

            else if (l == 0 && w < (width / 2))
                printf("  ");

            else if (l == 0 && w > (width / 2) && w < width)
                printf("  ");

            else if (l == 0 && w == width)
                printf("|");

            else if (l == length / 2 && w > 2 && w < width - 1)
                printf("  ");

            /*print player 4*/
            else if (l == length / 2 && w > 2 && w == width + 2)
                printf("P2");

            else if (l == length && w == 0)
                printf("|");

            else if (l == length && w < (width / 2))
                printf("  ");

            else if (l == length && w > (width / 2) && w < width)
                printf("  ");

            else if (l == length && w == width)
                printf("|");

            /*print player 1*/
            else if (l == length + 2 && w == (width / 2) - 1)
                printf("  P1");

            else if (l == length + 1 && w > 0 && w < width + 2)
                printf("--");

            /*print team 1*/
            else if (l == -1 && w == width + 3)
                printf("    team 1 point : %i | team 1 set : %i", point1, set1);

            /*print team 2*/
            else if (l == length + 1 && w == width + 3)
                printf("    team 2 point : %i | team 2 set : %i", point2, set2);

            else if (l == length + 2 && w != (width / 2))
                printf("  ");

            if (winner == 0)
            {
                /*print s1*/
                if (l == length && w == (width / 2))
                {
                    printsymbol(selectedsym[0]);
                    printnumber(selectednum[0]);
                }
                /*print s4*/
                else if (l == length / 2 && w == width)
                    printsymbol(selectedsym[1]);
                else if (l == length / 2 && w == width + 1)
                {
                    printnumber(selectednum[1]);
                    printf("|");
                }
                /*print S3*/
                else if (l == 0 && w == (width / 2))
                {
                    printsymbol(selectedsym[2]);
                    printnumber(selectednum[2]);
                }
                /*print s2*/
                else if (l == length / 2 && w == 1)
                    printsymbol(selectedsym[3]);

                else if (l == length / 2 && w == 2)
                    printnumber(selectednum[3]);
            }
            else if (winner == 2)
            {
                /*print s1*/
                if (l == length && w == (width / 2))
                {
                    printsymbol(selectedsym[2]);
                    printnumber(selectednum[2]);
                }
                /*print s4*/
                else if (l == length / 2 && w == width)
                    printsymbol(selectedsym[3]);
                else if (l == length / 2 && w == width + 1)
                {
                    printnumber(selectednum[3]);
                    printf("|");
                }
                /*print S3*/
                else if (l == 0 && w == (width / 2))
                {
                    printsymbol(selectedsym[0]);
                    printnumber(selectednum[0]);
                }
                /*print s2*/
                else if (l == length / 2 && w == 1)
                    printsymbol(selectedsym[1]);

                else if (l == length / 2 && w == 2)
                    printnumber(selectednum[1]);
            }
            else if (winner == 3)
            {
                /*print s1*/
                if (l == length && w == (width / 2))
                {
                    printsymbol(selectedsym[3]);
                    printnumber(selectednum[3]);
                }
                /*print s4*/
                else if (l == length / 2 && w == width)
                    printsymbol(selectedsym[0]);
                else if (l == length / 2 && w == width + 1)
                {
                    printnumber(selectednum[0]);
                    printf("|");
                }
                /*print S3*/
                else if (l == 0 && w == (width / 2))
                {
                    printsymbol(selectedsym[1]);
                    printnumber(selectednum[1]);
                }
                /*print s2*/
                else if (l == length / 2 && w == 1)
                    printsymbol(selectedsym[2]);

                else if (l == length / 2 && w == 2)
                    printnumber(selectednum[2]);
            }
            else if (winner == 1)
            {
                /*print s1*/
                if (l == length && w == (width / 2))
                {
                    printsymbol(selectedsym[1]);
                    printnumber(selectednum[1]);
                }
                /*print s4*/
                else if (l == length / 2 && w == width)
                    printsymbol(selectedsym[2]);
                else if (l == length / 2 && w == width + 1)
                {
                    printnumber(selectednum[2]);
                    printf("|");
                }
                /*print S3*/
                else if (l == 0 && w == (width / 2))
                {
                    printsymbol(selectedsym[3]);
                    printnumber(selectednum[3]);
                }
                /*print s2*/
                else if (l == length / 2 && w == 1)
                    printsymbol(selectedsym[0]);

                else if (l == length / 2 && w == 2)
                    printnumber(selectednum[0]);
            }

            /*print \n*/
            if (w == width + 3)
                printf("\n");
        }
    }
    if (hokm == 0)
        printf("hokm A hast", hokm);
    else if (hokm == 1)
        printf("hokm B hast", hokm);
    else if (hokm == 2)
        printf("hokm C hast", hokm);
    else if (hokm == 3)
        printf("hokm D hast", hokm);
    printf("\n");
    printf("\n");
}

void sort(int symbol[], int number[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (number[j] > number[k])
                {
                    int nptn = number[j];
                    int npts = symbol[j];
                    number[j] = number[k];
                    symbol[j] = symbol[k];
                    number[k] = nptn;
                    symbol[k] = npts;
                    break;
                }
            }
        }
    }
}

void winnerbot(int number[], int symbol[], int selectednum[], int selectedsym[], int hokm, int counter, int *selsymbol, int *selnumber)
{
    sort(symbol, number, 11);

    for (int i = 10; i >= 0; i--)
    {
        if (number[i] != -1)
        {
            if ((symbol[i] != hokm))
            {
                selectednum[0] = number[i];
                selectedsym[0] = symbol[i];
                *selsymbol = symbol[i];
                *selnumber = number[i];
                number[i] = -1;
                symbol[i] = -1;
                return;
            }

            else if (symbol[i] == hokm && i == 0)
            {
                selectednum[0] = number[11];
                selectedsym[0] = symbol[11];
                *selsymbol = symbol[i];
                *selnumber = number[i];
                number[i] = -1;
                symbol[i] = -1;
                return;
            }
        }
    }
}

void bot(int number[], int symbol[], int selectednum[], int selectedsym[], int counter, int winner, int hokm, int *selsymbol, int *selnumber)
{
    int bool = 0;
    sort(symbol, number, 11);

    for (int i = 10; i >= 0; i--)
    {
        if (symbol[i] == selectedsym[0] && number[i] != -1)
        {
            selectedsym[counter] = symbol[i];
            selectednum[counter] = number[i];
            *selsymbol = symbol[i];
            *selnumber = number[i];
            symbol[i] = -1;
            number[i] = -1;
            return;
        }
    }
    for (int i = 10; i >= 0; i--)
    {
        if (symbol[i] == hokm && number[i] != -1)
        {
            selectedsym[counter] = symbol[i];
            selectednum[counter] = number[i];
            *selsymbol = symbol[i];
            *selnumber = number[i];
            symbol[i] = -1;
            number[i] = -1;
            return;
        }
    }

    for (int i = 10; i >= 0; i--)
    {
        selectedsym[counter] = symbol[i];
        selectednum[counter] = number[i];
        *selsymbol = symbol[i];
        *selnumber = number[i];
        symbol[i] = -1;
        number[i] = -1;
        return;
    }
}

int iswinner(int selectedsym[4], int selectednum[4], int hokm, int selsymbol1, int selnumber1, int selsymbol2, int selnumber2, int selsymbol3, int selnumber3, int selsymbol4, int selnumber4)
{
    int nptsym[4];
    for (int i = 0; i < 4; i++)
    {
        nptsym[i] = selectedsym[i];
    }
    sort(selectedsym, selectednum, 4);
    int winnersym;
    int winnernum;
    int winner = 0;

    for (int i = 3; i >= 0; i--)
    {
        if (selsymbol1 == hokm && (selnumber1 == selectednum[i]))
            return 0;
        if (selsymbol2 == hokm && (selnumber2 == selectednum[i]))
            return 1;
        if (selsymbol3 == hokm && (selnumber3 == selectednum[i]))
            return 2;
        if (selsymbol4 == hokm && (selnumber4 == selectednum[i]))
            return 3;
    }
    for (int i = 3; i >= 0; i--)
    {
        if (selsymbol1 == nptsym[0] && (selnumber1 == selectednum[i]))
            return 0;
        if (selsymbol2 == nptsym[0] && (selnumber2 == selectednum[i]))
            return 1;
        if (selsymbol3 == nptsym[0] && (selnumber3 == selectednum[i]))
            return 2;
        if (selsymbol4 == nptsym[0] && (selnumber4 == selectednum[i]))
            return 3;
    }

    if (selnumber1 == selectednum[3])
        return 0;
    if (selnumber2 == selectednum[3])
        return 1;
    if (selnumber3 == selectednum[3])
        return 2;
    if (selnumber4 == selectednum[3])
        return 3;
}