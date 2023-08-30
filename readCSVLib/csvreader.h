#ifndef CSVREADER_H_INCLUDED   //librerias revisar y cargar librerias
#define CSVREADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXCHAR 250
#define MAXCOLUMNS 2
#define MAXROWS 2
#define NEWLINE '\n'

//Struct for managing csv files of double values
typedef struct data_frame {
  char *titles;
  double *data;
  // Size - reserved
  int n_rows;
  int n_columns;
  // Used
  int rows;
  int columns;
  // Flag
  bool has_titles;
 } DataFrame;

// --- Manage the Data Frame ---
// Copia titulos del viejo arreglo al arreglo nuevo
void df_copy_titles(char *nuevo, char *viejo, int n_columns);
// Free the allocated memory
void df_finalize (DataFrame *df);
// Initialize the dataframe by reserving memory assuming a maximum size.
bool df_initialize (DataFrame *df);
// Get a title
// [[title 0    ][title 1    ] ... [title n-1  ]
char * df_get_title (DataFrame *df, int column) ;
// Get a value
double df_get_value (DataFrame *df, int row, int column);
// Print a data frame
void df_print (DataFrame *df);
// Set a title  pone un valor ahí
void df_set_title (DataFrame *df, int column, char *n_title);
// Set a value
void df_set_value (DataFrame *df, int row, int column, double n_value);

// --- Manage CSV ---
// Read a csv file in a dataframe
bool read_csv (char *path, DataFrame *df, bool hasTitles, char separator);
// Read titles in a DataFrame
void read_csv_titles (FILE *ptr, DataFrame *df, char separator);
// Read values in a DataFrame
void read_csv_values (FILE *ptr, DataFrame *df, char separator);

#endif // CSVREADER_H_INCLUDED
