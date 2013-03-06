#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <vector>


/** classe CsvReader
 * Un simple lecteur de fichier CSV (Comma-Separated Values).
 * Le format CSV assume que les valeurs sont separees par un caractere
 * separateur, typiquement ',' (Matlab, editeurs de tables en locale anglo-saxonne)
 * ou ';' (editeurs de tables en locale francaise).
 * 
 * Le nom du fichier et le separateur (par defaut la virgule) sont a fournir
 * au constructeur, qui l'analysera et stockera les valeurs en memoire sous forme de std::string.
 * 
 * Le constructeur peut lancer les exceptions standard suivantes:
 *  - std::ios_base::failure, si l'ouverture du fichier echoue
 *  - std::runtime_error, si le fichier est vide ou si les lignes n'ont pas le meme nombre de colonnes
 * 
 * IMPORTANT : Ce lecteur n'analyse pas les valeurs!!!
 * Leurs tests ("non-vide", "numerique", etc...) sont a la charge de l'utilisateur de cette classe.
 */

class CsvReader
{
public:
    CsvReader(const std::string& filename, char value_separator = ','); /// 'filename' est le nom du fichier CSV et 'value_separator' le delimiteur entre chaque colonne
    unsigned nbRows() const;                                            /// Retourne le nombre de colonnes recuperees
    unsigned nbCols() const;                                            /// Retourne le nombre de lignes recuperees
    std::string getValue(unsigned row, unsigned col) const;             /// Retourne la valeur a la ligne 'row' et a la colonne 'col'
    std::string getFilename() const;                                    /// Retourne le nom du fichier
    
    void display(std::ostream& out) const;                              /// Affiche le nom et le contenu du fichier dans le flux 'out'
    
protected:
    std::string __filename;                             /// Le nom du fichier
    char __value_separator;                             /// Le caractere separant les valeurs d'une ligne
    std::vector<std::vector<std::string> > __values;    /// Les valeurs recuperees dans le fichier
};

std::ostream& operator<<(std::ostream& out, const CsvReader& csv);      /// Surcharge de l'operateur de flux pour l'affichage

#endif // CSVREADER_H
