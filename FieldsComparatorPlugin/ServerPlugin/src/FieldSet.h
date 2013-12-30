#ifndef FIELDSET_H
#define FIELDSET_H

#include "Field.h"
#include "Mesh.h"

struct FieldSet
{
    Mesh mesh;              /// Maillage sur lequel sont definis les champs
    QVector<Field> fields;  /// Liste des champs
    
    FieldSet(){}
    FieldSet(MP fieldsetitem);
    
    void load(MP fieldsetitem);
    void save(MP fieldsetitem) const;
    
    Field& addField(QString name);
    
    FieldSet operator+(const FieldSet& other) const;
    FieldSet operator-(const FieldSet& other) const;
    FieldSet operator*(const FieldSet& other) const;
    FieldSet operator/(const FieldSet& other) const;
    FieldSet operator*(double value) const;
    FieldSet operator/(double value) const;
};

#endif //FIELDSET_H