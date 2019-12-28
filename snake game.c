#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int height=20,width=20;
int x,y,fruitx,fruity,gameover,score,num,countTail=0;
int tailx[100],taily[100];

void position()
{
    x=height/2;
    y=width/2;
    gameover=0;
    score=0;
    label1:
        fruitx=rand()%20;
        if(fruitx==0)
        {
            goto label1;
        }
     label2:
         fruity=rand()%20;
         if(fruity==0)
         {
             goto label2;
         }
}

void box()
{
    int i,j,k;
    system("cls");
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
              if(i==0||i==height-1||j==0||j==width-1)
              {
                  printf("*");
              }
              else
              {
                  if(i==x&&j==y)
                  {
                      printf("0");
                  }
                  else if(i==fruitx&&j==fruity)
                  {
                      printf("@");
                  }
                  else
                  {
                      int ch=0;
                      for(k=0;k<countTail;k++)
                      {
                         if(i==tailx[k]&&j==taily[k])
                         {
                             printf("o");
                             ch=1;
                         }
                      }
                      if(ch==0)
                      printf(" ");
                  }
              }
        }
        printf("\n");
    }
    printf("\n\nSCORE=%d\n",score);

}

void input()
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'a':
            num=1;
            break;
        case 'd':
            num=2;
            break;
        case 'w':
            num=3;
            break;
        case 's':
            num=4;
            break;
        case 'j':
            gameover=1;
            break;
        }
    }
}

void inputlogic()
{
    int i,prevx,prevy,prev2x,prev2y;
    prevx=tailx[0];
    prevy=taily[0];
    tailx[0]=x;
    taily[0]=y;
    for(i=1;i<countTail;i++)
    {
       prev2x=tailx[i];
       prev2y=taily[i];
       tailx[i]=prevx;
       taily[i]=prevy;
       prevx=prev2x;
       prevy=prev2y;
    }

    switch(num)
    {
    case 1:
        y--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x--;
        break;
    case 4:
        x++;
        break;
    }
    if(x<1||x>height-2||y<1||y>width-2)
    {
        gameover=1;
    }
    for(i=0;i<countTail;i++)
    {
        if(x==tailx[i]&&y==taily[i])
            gameover=1;
    }


    if(x==fruitx&&y==fruity)
    {
     label3:
        fruitx=rand()%20;
        if(fruitx==0||fruitx==height-1)
            goto label3;
     label4:
         fruity=rand()%20;
         if(fruity==0||fruity==width-1)
             goto label4;
     score+=10;
     countTail++;
    }
}

int main()
{
	int m,n;
	char c,name[20];
	printf("\n******>>>>>>>Welcome to Snake Game<<<<<<<*******");
	printf("\n\n\tPress any key to continue:");
	getch();

	label5:
    position();
    while(!gameover)
    {
       box();
       input();
       inputlogic();

      for(m=0;m<1000;m++)
       {
       	  for(n=0;n<10000;n++)
       	  {
		  }
	   }
      for(m=0;m<1000;m++)
      {
          for(n=0;n<10000;n++)
          {
          }
      }
            for(m=0;m<1000;m++)
      {
          for(n=0;n<10000;n++)
          {
          }
      }
            for(m=0;m<1000;m++)
      {
          for(n=0;n<10000;n++)
          {
          }
      }
            for(m=0;m<1000;m++)
      {
          for(n=0;n<10000;n++)
          {
          }
      }
    }
    printf("\n\tGame Over !!!!\n");
    printf("\nEnter your name:");
    scanf("%s",&name);
    printf("\n\n%s has scored %d\n\n",name,score);
    return 0;
}
