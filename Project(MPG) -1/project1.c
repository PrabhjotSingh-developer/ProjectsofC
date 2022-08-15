/*                       Math puzzle project-        */
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<conio.h>
void srand(unsigned int seed);
void fillMatrice(int [][4],int []);
void random_arr(int game[][4])
{
    int a[15];
     int min,max,i,j,temp,x;
    min=1;
    max=min+14;
    srand(time(NULL));
    for(i=0;i<15;i++)
    {
        temp=rand()%15+min;
        for(j=0;j<i;j++)
        {
            if(temp==a[j])
            {
                break;
            }
        }
        if(i==j)
        {
            a[i]=temp;
        }
        else 
           i--;
   }
   fillMatrice(game,a);
}
void fillMatrice(int game[][4],int a[])
{
   int count=0;
   int i,j;
   for(i=0;i<4;i++)
   {
      for(j=0;j<4;j++)
      {
            game[i][j]=a[count];
            count++;
            if(count==15)
               break;
      }
   }
   game[3][3]=32;
    for(i=0;i<4;i++)
   {
      for(j=0;j<4;j++)
      {
             if (game[i][j] == 32)
            {
                printf("| %c\t", game[i][j]);
            }
            else
                printf("| %d\t", game[i][j]);

      }
      printf("|\n");
   }
}
int compare(int[][4], int[][4]);
int main()
{
   int x=1;
   while(x>0)
   {
    int i, j, move = 10, chances = 1, winner;
    char c;
    
    char name[50];
    int arr[4][4];
    int marr[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 32};

    printf("Player Name : - ");
    fgets(name, 20, stdin);
    system("cls");
    printf("                    MATRIX PUZZLE\n");
    printf("                    RULES OF THIS GAME\n");
    printf("      1.You can move only one step by arrow key\n");
    printf("             Move Up : by Press key w or W \n");
    printf("             Move Down : by press key s or S \n");
    printf("             Move Left : by Left press key l or L \n");
    printf("             Move Right : by Right press key d or D \n\n");
    printf("      2.You can move number at empty position only\n");
    printf("  3.for each valid move : your total number of move will decreased by 1\n");
    printf("4.Wining situation : Number in a 4*4 matrix should be in order from 1 to 15\n");
    printf("\n\n              Winning situation:\n");
    printf("---------------------------------\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (marr[i][j] == 32)
            {
                printf("| %c\t", marr[i][j]);
            }
            else
                printf("| %d\t", marr[i][j]);
        }
        printf("|\n");
    }
    printf("---------------------------------\n");
    printf("5.You can exit the game at any time by pressing 'E' or 'e'\n so try to win in minimum no of move\n");
    printf("enter the key\n");
    getch();
    system("cls");
    printf("Player name : - %s\t\t\t\t\t  Move remaining : %d\n", name, move);
    random_arr(arr);
   

    while (chances < 11)
    {
        scanf("%c", &c);
        fflush(stdin);
        //    move up key
        if (c == 'w' || c=='W' )
        {

            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {

                    if (arr[i][j] == 32 && i > 0)
                    {
                        arr[i - 1][j] += arr[i][j];
                        arr[i][j] = arr[i - 1][j] - arr[i][j];
                        arr[i - 1][j] = arr[i - 1][j] - arr[i][j];
                    }
                }
                printf("\n");
            }
        }
        // move down key
        else if (c == 's' || c == 'S')
        {
            int temp = 0;
            int r, c;
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    if (arr[i][j] == 32 && i < 3)
                    {
                        temp = arr[i][j];
                        arr[i][j] = arr[i + 1][j];
                        r = i;
                        c = j;
                        printf("%d", temp);
                    }
                    if (temp == 32 && i < 3)
                    {
                        arr[r + 1][c] = temp;
                        break;
                    }
                }
                printf("\n");
                if (temp == 32)
                    break;
            }
        }

        // move right key
        else if (c == 'D' || c == 'd')
        {
            int temp = 0;
            int r, c;
            for (i = 0; i < 4; i++)
            {

                for (j = 0; j < 4; j++)
                {
                    if (arr[i][j] == 32 && j < 3)
                    {

                        temp = arr[i][j];
                        arr[i][j] = arr[i][j + 1];
                        r = i;
                        c = j;
                        printf("%d", temp);
                    }
                    if (temp == 32 && j < 3)
                    {
                        arr[r][c + 1] = temp;
                        break;
                    }
                }

                printf("\n");
            }
        }
        //   move left key
        else if (c == 'a' || c == 'A')
        {
            int temp;
            for (i = 0; i < 4; i++)
            {

                for (j = 0; j < 4; j++)
                {
                    if (arr[i][j] == 32 && j > 0)
                    {
                        temp = arr[i][j];
                        arr[i][j] = arr[i][j - 1];
                        arr[i][j - 1] = temp;
                    }
                }
                printf("\n");
            }
        }
        // move e key
        else if(c=='e'||c=='E')
        {
             move=0;
             break;
        }

        if (c == 'w' || c == 'W' || c == 'a' || c == 'A' || c == 'S' || c == 's' || c == 'd' || c == 'D')
        {
            move--;
            chances++;
        }
        system("cls");
      printf("Player name : - %s\t\t\t\t\t  Move remaining : %d\n", name, move);

        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (arr[i][j] == 32)
                {
                    printf("| %c\t", arr[i][j]);
                }
                else
                    printf("| %d\t", arr[i][j]);
            }
            printf("|\n");
        }
        winner=compare(arr,marr);
        if(winner==0)
        {
             printf("you are winner\n");
             break;
        }    
    }
    if(move==0)
    {
       char pg;
      printf("lose the game\n");
      printf("You want to play again? y or n \n");
      scanf("%c",&pg);
     if(pg=='y')
     {
        x++;
     }else
     {
        printf("Thanks\n");
        break;
     }
     
    }
   }
}

int compare(int user[][4], int sort[][4])
{
    int i, j, flag = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (user[i][j] == sort[i][j])
            {
                flag++;
            }
            else
            {
                
                return 9;
            }
        }
    }
    if (flag == 16)
        return 0;
}
