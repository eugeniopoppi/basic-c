#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 1000


int main()
    {
     int i;
     double x1,x2,r,y1,y2,y12m,y1m,devy1m;
     //long int min, max;
     FILE *fd;

     fd=fopen("bm_polar_data.txt","w");
     if (fd == NULL) {
       perror("Errore di apertura del file");
       exit(1);
     }
     srand(time(NULL));
     y12m = 0;
     y1m = 0;
       for(i=0;i<N;i++)
          {
          x1 = rand()/(RAND_MAX+1.0);
          x1 = (x1*2)-1;
          x2 = rand()/(RAND_MAX +1.0);
          x2 = (x2*2)-1;
          r = sqrt((x2*x2)+(x1*x1));
          if(r<1)
           {
            y1 = (x2/r)*sqrt(-2*log(r*r));
            y2 = (x1/r)*sqrt(-2*log(r*r));
            fprintf(fd,"%lf  %lf \n",y1,y2);
           }
          y12m += y1*y1;
          y1m += y1;
          }
          y12m = y12m/N;
          y1m = y1m/N;
       fclose(fd);

       //computing of std deviation
       devy1m = sqrt(N*(y12m - (y1m*y1m))/(N-1));
       printf("dev = %lf \n",devy1m);
       printf("mean = %lf \n",y1m);
       return EXIT_SUCCESS;
}
