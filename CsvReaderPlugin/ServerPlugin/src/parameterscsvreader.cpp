#include "parameterscsvreader.h"
#include <iostream>

ParametersCsvReader::ParametersCsvReader(const std::string& filename, Orientation parameters_orientation, char value_separator, bool has_headers):
    CsvReader(filename,value_separator),
    __has_headers(has_headers),
    __parameters_orientation(parameters_orientation)
{
}

unsigned int ParametersCsvReader::nbParameters() const
{
    if(__parameters_orientation == Row)
        return CsvReader::nbRows();
    else
        return CsvReader::nbCols();
}

unsigned int ParametersCsvReader::nbValues() const
{
    if(__parameters_orientation == Row)
        return CsvReader::nbCols() - (__has_headers?1:0);
    else
        return CsvReader::nbRows() - (__has_headers?1:0);
}


std::string ParametersCsvReader::getHeader(unsigned parameter_index) const
{
    if(__has_headers)
    {
        if(__parameters_orientation == Row)
            return CsvReader::getValue(parameter_index, 0);
        else
            return CsvReader::getValue(0, parameter_index);
    }
    else
    {
        return "";
    }
}

std::string ParametersCsvReader::getValue(unsigned parameter_index, unsigned value_index) const
{
    if(__parameters_orientation == Row)
        return CsvReader::getValue(parameter_index, value_index + (__has_headers?1:0));
    else
        return CsvReader::getValue(value_index + (__has_headers?1:0), parameter_index);
}

void ParametersCsvReader::display(std::ostream& out) const
{
    unsigned nb_params = nbParameters();
    unsigned nb_values = nbValues();
    out << getFilename() << " : (" << nb_params << " parameters, " << nb_values << " values)\n";
    for(unsigned param = 0; param < nb_params; param++)
    {
        out << getHeader(param) << " : ";
        for(unsigned value = 0; value < nb_values; value++)
        {
            out << getValue(param,value) << '\t';
        }
        out << '\n';
    }
    out.flush();
}

std::ostream& operator<<(std::ostream& out, const ParametersCsvReader& paramcsv)
{
    paramcsv.display(out);
    return out;
}

