#include "csvreader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

CsvReader::CsvReader(const std::string& filename, char value_separator):
    __filename(filename),
    __value_separator(value_separator)
{
    /// Ouvre le fichier
    std::ifstream file_stream;
    file_stream.open(__filename.c_str());
    
    /// Verifie que le fichier est bien ouvert
    if(not file_stream.is_open())
    {
        std::string error("Unable to open ");
        error += __filename;
        std::cerr << error << std::endl;
        throw std::ios_base::failure(error);
    }
    
    /// Parse le fichier
    char line_separator = '\n';
    while(not file_stream.eof())
    {
        std::string line;
        std::getline(file_stream, line, line_separator);
        //std::cout << line;    /// Debug: Affiche la ligne recuperee
        if(not line.empty())    /// Securite si ligne vide a la fin
        {
            /// Parse chaque ligne du fichier
            std::istringstream line_stream(line);
            std::vector<std::string> line_values;
            while(not line_stream.eof())
            {
                std::string value;
                std::getline(line_stream, value, value_separator);
                //std::cout << '\"' << value << '\"' << '\t';   /// Debug: Affiche la valeur recuperee
                line_values.push_back(value);   /// Les valeurs sont stockees dans un vecteur temporaire...
            }
            //std::cout << std::endl;   /// Debug: pour separer les lignes recuperees
            __values.push_back(line_values);    /// ... avant d'etre stockees dans '__values'
        }
    }
    
    /// Ferme le fichier
    file_stream.close();
    
    /// Verifie que le fichier n'est pas vide
    if(__values.size() == 0)
    {
        std::string error(__filename);
        error += " is an empty file!";
        std::cerr << error << std::endl;
        throw std::runtime_error(error);
    }
    /// Verifie que toutes les lignes ont le meme nombre de colonnes
    const unsigned nb_cols = __values[0].size();
    for(unsigned i = 1; i < __values.size(); i++)
    {
        if(__values[i].size() != nb_cols)
        {
            std::string error(__filename);
            error += " is not correctly formated (all rows should have the same number of columns)!";
            std::cerr << error << std::endl;
            throw std::runtime_error(error);
        }
    }
}

unsigned CsvReader::nbRows() const
{
    return __values.size();
}

unsigned CsvReader::nbCols() const
{
    return __values[0].size();
}

std::string CsvReader::getValue(unsigned row, unsigned col) const
{
    return __values[row][col];
}

std::string CsvReader::getFilename() const
{
    return __filename;
}

void CsvReader::display(std::ostream& out) const
{
    unsigned nb_rows = nbRows();
    unsigned nb_cols = nbCols();
    out << getFilename() << " : (" << nb_rows << ',' << nb_cols << ")\n";
    for(unsigned row = 0; row < nb_rows; row++)
    {
        for(unsigned col = 0; col < nb_cols; col++)
        {
            out << getValue(row,col) << '\t';
        }
        out << '\n';
    }
    out.flush();
}

std::ostream& operator<<(std::ostream& out, const CsvReader& csv)
{
    csv.display(out);
    return out;
}
