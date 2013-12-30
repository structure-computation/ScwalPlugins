#ifndef FIELD_H
#define FIELD_H

#include <QtCore/QString>
#include <QtCore/QVector>
#include "../LMT/include/containers/vec.h"
#include <Soca/MP.h>
class Mesh;


struct Field
{
    enum Type {Nodal, Elemental};
    struct FieldValue
    {
        typedef LMT::Vec<double> Vector;
        double time;            /// Pas de temps correspondant
        Vector data;            /// Valeurs
    };
    
    QString  name;              /// Nom du champs
    Type     type;              /// Type du champs (Nodal ou Elemental)
    unsigned order;             /// Ordre (tensoriel) du champs (0, 1 ou 2)
    Mesh*    mesh;              /// Maillage sur lequel repose le champs
    QVector<FieldValue> values; /// Valeurs du champs a chaque pas de temps
    
    Field(){}
    Field(MP fielditem, Mesh* mesh);
    
    void load(MP fielditem);
    void save(MP fielditem) const;
    
    Field operator+(const Field& other) const;
    Field operator-(const Field& other) const;
    Field operator*(const Field& other) const;
    Field operator/(const Field& other) const;
    Field operator*(double value) const;
    Field operator/(double value) const;
};

#endif  // FIELD_H