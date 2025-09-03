#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRING_LENGTH 50

// Function that produce one step of the linear congruential generator
double lin_cong(double x_0,double a,double c,double m)
    {  double x;

       x += fmod((a*x_0+c),m);
       return x;
    }

// Main function
int main(int argc, char **argv) {
    double  x_0,x,a,c,m;
    int i;
    long int N;
    char datafile[STRING_LENGTH];
    FILE *fp;

    // Check if the correct number of arguments is provided
    if (argc != 7)
    {
        fprintf(stdout, " How to use this program:\n");
        fprintf(stdout, " %s x_0 a c m N filename\n\n", argv[0]);
        //fprintf(stdout, "x_0,a,c and m should be a double.\n");
        fprintf(stdout, "x_0 = double, the random seed, 0=<x_0<m ");
        fprintf(stdout, "a = double, the multiplier, 0<a<m");
        fprintf(stdout, "c = double, the increment, 0<c<m");
        fprintf(stdout, "m = double, the modulus, 0<m");
        fprintf(stdout, "N =integer ,the numbers to be genereted ");
        fprintf(stdout, "filename = name of the file on which the result is written\n");
        fprintf(stdout, "Output: N 'random' number saved in the file\n");

        return EXIT_SUCCESS;
    } else {

        // Read input values
        x_0 = atof(argv[1]);
        a = atof(argv[2]);
        c = atof(argv[3]);
        m = atof(argv[4]);
        N = atof(argv[5]);
        // filename could be too long, we have to check to prevent errors
        if(strlen(argv[6]) >= STRING_LENGTH)
          {
          fprintf(stderr, "File name too long. Increse STRING_LENGTH or shorten the name (%s, %d)\n", __FILE__, __LINE__);
          return EXIT_FAILURE;
          }
        else
          {
          strcpy(datafile, argv[6]);
          }
        }
    // open data file for writing
      fp=fopen(datafile, "w");
      if(fp==NULL)
        {
        fprintf(stderr, "Error in opening the file %s (%s, %d)\n", datafile, __FILE__, __LINE__);
        return EXIT_FAILURE;
        }
    // Generate the N "random" number
    for(i=0;i<N;i++)
       {
       x = lin_cong(x_0,a,c,m);
       // print the result on the file
       fprintf(fp, "%lf\n",x);
       //redefine x_0 for the nex cicle
       x_0 = x;
       }
       // close the file
       fclose(fp);

    return EXIT_SUCCESS;
}
