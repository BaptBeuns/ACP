#include "matrix.h"

using namespace std;

Matrix::Matrix(std::string file_name){
    // On lit m et n dans la première ligne du fichier
    // On lit mat dans les lignes qui suivent
    // Utiliser les fonctions qui sont écrites ci-dessous

    // Attention, quand on veut assigner mat[i][j], on fait ça :
    // mat[i][j]

    // En revanche, quand on veut seulement lire, il faut faire :
    // mat.at(i).at(j)
}




/*
// Read a file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main ()
{
        string STRING;
    ifstream infile;
    infile.open ("names.txt");
        while(!infile.eof) // To get you all the lines.
        {
            getline(infile,STRING); // Saves the line in STRING.
            cout<<STRING; // Prints our STRING.
        }
    infile.close();
    system ("pause");
}



// Split a string
std::string s = "scott>=tiger>=mushroom";
std::string delimiter = ">=";

size_t pos = 0;
std::string token;
while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    std::cout << token << std::endl;
    s.erase(0, pos + delimiter.length());
}
std::cout << s << std::endl;





// Split a string a la cool
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="- This, a sample string.";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }
  return 0;
}
*/
