#include "csvreader.h"

//Main function
int main(void) {
  DataFrame df;
  char *path = "D:/6. Sexto Semestre/Fundamentos de Programación 2/New Codes/data.csv";
  if (df_initialize(&df))
    if (read_csv (path, &df, true, ','))
      df_print (&df);
  df_finalize(&df);
  return 0;
}
