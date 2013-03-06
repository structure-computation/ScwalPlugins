#ifndef PARAMETERSCSVREADER_H
#define PARAMETERSCSVREADER_H

#include "csvreader.h"


/** classe ParametersCsvReader
 * Un lecteur de fichier CSV plus elabore, pour s'abstraire de l'orientation et gerer les headers
 * 
 * Les valeurs peuvent etre en lignes ou en colonnes
 * Si le fichier contient des headers, ils seront supposes etre les premieres valeurs des parametres
 * Sinon l'accesseur 'getHeader' retournera des strings vides;
 */

class ParametersCsvReader: protected CsvReader {
public:
    enum Orientation {Row = 0, Column = 1};
    /// Constructeur
    ParametersCsvReader(const std::string& filename,                /// Le nom du fichier
                        Orientation parameters_orientation = Row,   /// Indique si les parametres sont ranges par ligne ou par colonne
                        char value_separator = ',',                 /// Le separateur entre les valeurs
                        bool has_headers = false                    /// Indique si les headers sont dans le fichier
                       );
    
    unsigned nbParameters() const;
    unsigned nbValues() const;
    std::string getHeader(unsigned parameter_index) const;                                  /// Retourne le header du parametre d'indice 'parameter_index' (string vide si non-fournis)
    std::string getValue(unsigned parameter_index, unsigned value_index) const;    /// Retourne la valeur d'indice 'value_index' du parametre d'indice 'parameter_index'
    
    void display(std::ostream& out) const;

protected:
    bool __has_headers;                     /// Indique si les headers sont dans le fichier
    Orientation __parameters_orientation;   /// Indique si les parametres sont ranges par ligne ou par colonne 
};

std::ostream& operator<<(std::ostream& out, const ParametersCsvReader& paramcsv);

#endif // PARAMETERSCSVREADER_H
