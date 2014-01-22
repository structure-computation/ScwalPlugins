#ifndef FIELDSET_H
#define FIELDSET_H

#include "Field.h"
#include "Mesh.h"

struct FieldSet
{
    Mesh mesh;              /// Maillage sur lequel sont definis les champs
    QVector<Field> fields;  /// Liste des champs
    int current_field;      /// numero du champs selectionné dans color_by (champs visualisé dans le navigateur)
    int current_time_step;  /// numero du pas de temps sur lequel la comparaison est effectuée
    LMT::Vec< int > correspondance;     /// correspondance des noeuds entre deux maillages
    bool correspondance_computed;       /// permet de savoir si le calcul de la correspondance à déjà été réalisé
    
    FieldSet(){}
    FieldSet(MP fieldsetitem);
    
    void load(MP fieldsetitem);                                 /// chargement a partir du model Soda
    void load_current_time_step(int time_step);                 /// chargement du pas de temps courant
    void save(MP fieldsetitem) const;                           /// sauvegarde du résultat dans un fieldset soda
    void other_field_mesh_correspondance(const FieldSet& other);   /// génération de la table de correspondance des noeuds entre deux FieldSet.mesh
      
    Field& addField(QString name);
    
    FieldSet operator+(const FieldSet& other) const;
    FieldSet operator-(const FieldSet& other) const;
    FieldSet operator*(const FieldSet& other) const;
    FieldSet operator/(const FieldSet& other) const;
    FieldSet operator*(double value) const;
    FieldSet operator/(double value) const;
};

#endif //FIELDSET_H