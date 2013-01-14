#ifndef MAKE_FIELDS_H
#define MAKE_FIELDS_H

#include <Soca/MP.h>

MP make_field( MP mp, QString name );
QVector<MP> make_field( MP mp, int dim, QString base );
QVector<MP> make_field( MP mp, int dim, QString base, QVector<QString> letters );

void add_field_in_Interpolated( MP interpolated_field, MP mesh, MP data, double time, QString type_field = "NodalField" );

#endif // MAKE_FIELDS_H
