#include<stdio.h>

char arr[3][3];
int pos; 
char ch = 'O';// Variable to represent the current player ('O' starts first)
int row, col; 
int f = 0;

void setup()
{
    // Initialize the game board with empty spaces
    for(int i =0; i<3; i++)
    {
        for(int j =0; j<3; j++)
        {
            arr[i][j] = ' ';
        }
    }
}

void setpos()
{
    // Convert the position entered by the player into row and column
    switch (pos)
   {
    case 1: row = 0, col = 0; break;
    case 2: row = 0, col = 1; break;
    case 3: row = 0, col = 2; break;
    case 4: row = 1, col = 0; break;
    case 5: row = 1, col = 1; break;
    case 6: row = 1, col = 2; break;
    case 7: row = 2, col = 0; break;
    case 8: row = 2, col = 1; break;
    case 9: row = 2, col = 2; break;
   }
}

void display()
{
	system("clear");
    // Display the current state of the game board
    printf(" %c | %c | %c \n", arr[0][0], arr[0][1], arr[0][2]);
    printf("------------\n");
    printf(" %c | %c | %c \n", arr[1][0], arr[1][1], arr[1][2]);
    printf("------------\n");
    printf(" %c | %c | %c \n", arr[2][0], arr[2][1], arr[2][2]);
}

int checkwin()
{
    // Check if the current player has won the game
    if (arr[0][0] == ch && arr[0][1] == ch && arr[0][2] == ch)
      return 1;
    if (arr[1][0] == ch && arr[1][1] == ch && arr[1][2] == ch)
      return 1;
    if (arr[2][0] == ch && arr[2][1] == ch && arr[2][2] == ch)
      return 1;
    if (arr[0][0] == ch && arr[1][0] == ch && arr[2][0] == ch)
      return 1;
    if (arr[0][1] == ch && arr[1][1] == ch && arr[2][1] == ch)
      return 1;
    if (arr[0][2] == ch && arr[1][2] == ch && arr[2][2] == ch)
      return 1;
    if (arr[2][0] == ch && arr[1][1] == ch && arr[0][2] == ch)
      return 1;
    if (arr[0][0] == ch && arr[1][1] == ch && arr[2][2] == ch)
      return 1;

    return 0;
}

int main()
{
   setup();
   int i = 0;

   while (i != 9)
   {
   
   checkpos:	   
	   display(); 
           printf("Current player = %c\n", ch); 
           printf("Enter position\n");
           scanf("%d", &pos);

         if (pos < 1 || pos > 9)
        {
              printf("Wrong position \n");
              goto checkpos; // Ask the player to re-enter the position
        }

        setpos();

   if (arr[row][col] == ' ')
     {
       arr[row][col] = ch; // Update the board with the player's move
       i++; // Increment the move counter
       int c;
       c = checkwin(); // Check if the current player has won

       if (c == 1)
       {
          display(); // Display the final state of the board
          printf("Player %c wins the game\n", ch);
          printf("Thanks for playing");
          return 1;
       }

       if (f == 0)
       {
          ch = 'X'; // Switch to the other player
          f = 1; // Toggle the player flag
       }
       else
       {
         ch = 'O'; // Switch to the other player
         f = 0; // Toggle the player flag
       }

   }
   else
   {
       printf("Element already occupied \n");
       goto checkpos; // Ask the player to re-enter the position
   }

   }
   display(); // Display the final state of the board
   printf("Game draw\n");
   printf("Thanks for playing");
   return 0;
}

