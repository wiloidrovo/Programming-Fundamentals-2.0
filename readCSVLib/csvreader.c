#include "csvreader.h"

// --- Manage the Data Frame ---

// Copia titulos del viejo arreglo al arreglo nuevo
void df_copy_titles(char *nuevo, char *viejo, int n_columns){
    int i, j, offset;
    for(i=0; i<n_columns; i++){
        for(j=0; j<MAXCHAR; j++){
            offset = i*MAXCHAR+j;
            nuevo[offset] = viejo[offset];
        }
    }
}

// Free the allocated memory
void df_finalize (DataFrame *df) {
  if (df->titles != NULL)
    free (df->titles);
  if (df->data != NULL)
    free (df->data);
}
// Initialize the dataframe by reserving memory assuming a maximum size.
bool df_initialize (DataFrame *df) {
  // Allocate memory
  df->titles = (char *) malloc(sizeof(char) * MAXCOLUMNS * MAXCHAR);
  df->data = (double *) malloc(sizeof(double) * MAXROWS * MAXCOLUMNS);
  df->columns = 0;
  df->rows = 0;
  // If there was a problem with memory
  if (df->titles == NULL || df->data == NULL) {
    printf ("df_initialize() failed");
    df->n_rows = 0;
    df->n_columns = 0;
    return false;
  }
  // if everything went well
  df->n_rows = MAXROWS;
  df->n_columns = MAXCOLUMNS;
  df->has_titles = false;
  return true;
}

// Get a title
// [[title 0    ][title 1    ] ... [title n-1  ]
char * df_get_title (DataFrame *df, int column) {
  int offset;
  offset = column * MAXCHAR;
  return &(df->titles[offset]);
}

// Get a value
double df_get_value (DataFrame *df, int row, int column) {
  int offset;
  offset = row * df->n_columns + column;
  return df->data[offset];
}

// Print a data frame
void df_print (DataFrame *df) {
  int i, j;
  // Print titles
  if (df->has_titles) {
    for (j=0; j<df->columns; j++)
      printf ("%10.10s", df_get_title(df, j));
    printf ("\n");
  }
  // Print values
  for (i=0; i<df->rows; i++) {
    for (j=0; j<df->columns; j++) {
      printf ("%10.02f", df_get_value(df,i,j));
    }
    printf ("\n");
  }
}

// Set a title
void df_set_title (DataFrame *df, int column, char *n_title) {
  int offset;
  offset = column * MAXCHAR;
  strcpy(&(df->titles)[offset], n_title);
}

// Set a value
void df_set_value (DataFrame *df, int row, int column, double n_value) {
  int offset;
  offset = row * df->n_columns + column;
  df->data[offset] = n_value;
}

// --- Manage CSV ---
// Read a csv file in a dataframe
bool read_csv (char *path, DataFrame *df, bool hasTitles, char separator) {
  // Opening file in reading mode
  FILE *ptr;
  // Open file
  ptr = fopen(path, "r");
  // If existed and error
  if (ptr == NULL) {
    printf("File [%s] can't be opened \n", path);
    return false;
  }
  df->has_titles = hasTitles;
  if (hasTitles)
    read_csv_titles (ptr, df, separator);
  read_csv_values (ptr, df, separator);
  fclose (ptr);
  return true;
}

// Read titles in a DataFrame
void read_csv_titles (FILE *ptr, DataFrame *df, char separator) {
  char c, buffer[MAXCHAR];
  char *nuevo, *temporal;
  int p = 0, j = 0;
  while ((c=fgetc (ptr)) != EOF) {
    if (c==separator || c==NEWLINE) {
      buffer[p] = '\0'; //End of string
      p = 0; // Restart buffer position
      if (j>= df->n_columns){
        //printf("\nnumber of columns exceeded, insufficient memory\n");
        nuevo = (char *) malloc(sizeof(char) * 2 * df->n_columns * MAXCHAR);
        df_copy_titles(nuevo, df->titles, df->n_columns);
        temporal = df->titles;
        df->titles = nuevo;
        free(temporal);
        df->n_columns = 2 * n_columns;
        //exit (1);
      }
      df_set_title (df, j++, buffer);
      if (c==NEWLINE) break;
    }
    else
      buffer[p++]=c; // Is missing to check the MAXCHAR by title
  }
  df->columns = j;
}

// Read values in a DataFrame
void read_csv_values (FILE *ptr, DataFrame *df, char separator) {
  char c, buffer[MAXCHAR];
  int p = 0, i = 0, j = 0, max_column = 0;
  double new_value;
  while ((c=fgetc (ptr)) != EOF) {
    if (c==separator || c==NEWLINE) {
      buffer[p] = '\0'; //End of string
      p = 0; // Restart buffer position
      new_value = atof(buffer);
      df_set_value (df, i, j++, new_value);
      if (c==NEWLINE) {
        if (j > max_column)
          max_column = j;
        j = 0; i++;
      }
    }
    else
      buffer[p++]=c; // Is missing to check the MAXCHAR by title
  }
  df->columns = max_column;
  df->rows = i;
}


