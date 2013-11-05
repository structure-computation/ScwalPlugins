#include <Soca/Com/SodaClient.h>
#include <Soca/Model/TypedArray.h>
#include <QtCore/QFile>
#include <QtCore/QTemporaryFile>
#include <QtCore/QDataStream>
#include <containers/vec.h>
#include "StepReaderUpdater.h"





//******************************************************************************
// Copyright (c) 1999-2013 - OPEN CASCADE SAS
//******************************************************************************

#include <Interface_Static.hxx>
#include <Standard_Failure.hxx>
#include <Standard_ErrorHandler.hxx>
#include <BRep_Builder.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <Poly.hxx>
#include <Poly_Triangulation.hxx>
#include <Poly_ListOfTriangulation.hxx>
#include <STEPControl_Reader.hxx>
#include <IGESControl_Reader.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Compound.hxx>

#include <iostream>

//******************************************************************************
//******************************************************************************
Handle(Poly_Triangulation) ShapeToTriangles(const TopoDS_Shape& shape)
{
  try
  {
    OCC_CATCH_SIGNALS;

    // generate triangulation
    const Standard_Real    deflection = 0.01;
    const Standard_Boolean deflectionIsRelative = true;
    BRepMesh_IncrementalMesh e(shape, deflection, deflectionIsRelative);

    // concatenate triangulation of all faces
    Poly_ListOfTriangulation triaOfFaces;
    TopLoc_Location loc;
    for ( TopExp_Explorer faceIt( shape, TopAbs_FACE ); faceIt.More(); faceIt.Next() )
    {
      const TopoDS_Face&      face = TopoDS::Face( faceIt.Current() );
      Handle(Poly_Triangulation) t = BRep_Tool::Triangulation( face, loc );
      if ( !t.IsNull() )
      {
        if ( face.Orientation() == TopAbs_REVERSED )
        {
          // inverse triangles
          Poly_Array1OfTriangle& trias = t->ChangeTriangles();
          Standard_Integer n1,n2,n3;
          for ( int i = 1; i <= trias.Upper(); ++i )
          {
            Poly_Triangle& t = trias.ChangeValue( i );
            t.Get( n1,n2,n3 );
            t.Set( n1,n3,n2 );
          }
        }
        triaOfFaces.Append( t );
      }
    }
    Handle(Poly_Triangulation) t = Poly::Catenate( triaOfFaces );
    return t;
  }
  catch (Standard_Failure)
  {
  }
  return NULL;
}

//******************************************************************************
//******************************************************************************
TopoDS_Shape ImportSTEP(const char* stepFile)
{
  STEPControl_Reader aReader;

  // Convert to METERS
  Interface_Static::SetCVal("xstep.cascade.unit","M");
  Interface_Static::SetIVal("read.step.ideas", 1);
  Interface_Static::SetIVal("read.step.nonmanifold", 1);

  BRep_Builder B;
  TopoDS_Compound compound;
  B.MakeCompound(compound);
  int nbInCompound = 0;

  TopoDS_Shape resultShape;

  std::ostringstream readerOutput;
  std::streambuf* coutBuffer = std::cout.rdbuf();
  std::cout.rdbuf( readerOutput.rdbuf() );

  try
  {
    OCC_CATCH_SIGNALS;

    IFSelect_ReturnStatus status = aReader.ReadFile( stepFile );

    if (status == IFSelect_RetDone)
    {
      Standard_Integer nbRoots = aReader.NbRootsForTransfer();
      for (Standard_Integer n = 1; n <= nbRoots; n++)
      {
        Standard_Boolean ok = aReader.TransferRoot(n);
        Standard_Integer nbShapesInRoot = aReader.NbShapes();
        if (!ok || nbShapesInRoot == 0)
        {
          continue; // skip an empty root
        }
        for (Standard_Integer i = 1; i <= nbShapesInRoot; i++)
        {
          TopoDS_Shape aShape = aReader.Shape(i);
          if ( !aShape.IsNull())
          {
            B.Add(compound, aShape);
            ++nbInCompound;
            resultShape = aShape;
          }
        }
      }
    }
  }
  catch ( Standard_Failure )
  {
    std::cout.rdbuf( coutBuffer );
    std::cout << "Exception while reading " << stepFile << std::endl;
    nbInCompound = 0;
    resultShape = TopoDS_Shape();
  }
  std::cout.rdbuf( coutBuffer );

  if ( nbInCompound > 1 )
    resultShape = compound;

  return resultShape;
}


//******************************************************************************
//******************************************************************************
TopoDS_Shape ImportIGES(const char* igesFile)
{
  IGESControl_Reader aReader;

  // Convert to METERS
  Interface_Static::SetCVal("xiges.cascade.unit","M");
  Interface_Static::SetIVal("read.iges.ideas", 1);
  Interface_Static::SetIVal("read.iges.nonmanifold", 1);

  BRep_Builder B;
  TopoDS_Compound compound;
  B.MakeCompound(compound);
  int nbInCompound = 0;
  
  TopoDS_Shape resultShape;
//   std::ostringstream readerOutput;
//   std::streambuf* coutBuffer = std::cout.rdbuf();
//   std::cout.rdbuf( readerOutput.rdbuf() );

  try
  {
    OCC_CATCH_SIGNALS;
    IFSelect_ReturnStatus status = aReader.ReadFile( igesFile );
    if (status == IFSelect_RetDone)
    {
      Standard_Integer nbRoots = aReader.NbRootsForTransfer();
      for (Standard_Integer n = 1; n <= nbRoots; n++)
      {  
        Standard_Boolean ok = aReader.TransferOneRoot(n);
        Standard_Integer nbShapesInRoot = aReader.NbShapes();
        if (!ok || nbShapesInRoot == 0)
        {
          continue; // skip an empty root
        }
        for (Standard_Integer i = 1; i <= nbShapesInRoot; i++)
        {
          TopoDS_Shape aShape = aReader.Shape(i);
          if ( !aShape.IsNull())
          {
            B.Add(compound, aShape);
            ++nbInCompound;
            resultShape = aShape;
          }
        }
      }
    }
  }
  catch ( Standard_Failure )
  {
//     std::cout.rdbuf( coutBuffer );
    std::cout << "Exception while reading " << igesFile << std::endl;
    nbInCompound = 0;
    resultShape = TopoDS_Shape();
  }
//   std::cout.rdbuf( coutBuffer );

  if ( nbInCompound > 1 )
    resultShape = compound;

  return resultShape;
}

//******************************************************************************
//******************************************************************************
// int main_test (int argc, char ** argv)
// {
//   if ( argc < 2 )
//   {
//     std::cout << "Usage: " << argv[0] << " stepFile" << endl;
//     return 1;
//   }
//   // read the file
//   TopoDS_Shape shape = ImportSTEP( argv[1] );
//   if ( shape.IsNull() )
//   {
//     std::cout << "ImportSTEP() failed" << std::endl;
//     return 1;
//   }
//   // get triangles
//   Handle(Poly_Triangulation) tria = ShapeToTriangles( shape );
//   if ( tria.IsNull() )
//   {
//     std::cout << "ShapeToTriangles() failed" << std::endl;
//     return 1;
//   }
//   // dump nodes
//   const TColgp_Array1OfPnt& nodes = tria->Nodes();
//   std::cout << "# " << nodes.Upper() << " nodes: " << std::endl;
//   for ( int i = 1; i <= nodes.Upper(); ++i )
//   {
//     const gp_Pnt& p = nodes.Value( i );
//     std::cout << i << " \t" << p.X() << " "  << p.Y() << " "  << p.Z() << std::endl;
//   }
//   // dump triangles
//   const Poly_Array1OfTriangle& trias = tria->Triangles();
//   std::cout << "# " << trias.Upper() << " triangles: " << std::endl;
//   Standard_Integer n1,n2,n3;
//   for ( int i = 1; i <= trias.Upper(); ++i )
//   {
//     const Poly_Triangle& t = trias.Value( i );
//     t.Get( n1,n2,n3 );
//     std::cout << i << " \t" << n1 << " "  << n2 << " "  << n3 << std::endl;
//   }
//   return 0;
// }



typedef LMT::Vec<double,3> Pvec;

//******************************************************************************
// run de l'updater
//******************************************************************************


struct AutoRm {
    AutoRm( QString f ) : f( f ) {}
    ~AutoRm() { QFile::remove( f ); }
    QString f;
};

bool StepReaderUpdater::run( MP mp ) {
    MP ch = mp[ "_children[ 0 ]" ];
    if ( ch.ok() ) {
        // check if a .geo file has been provided
        QString name = ch["_name"];
        bool test_stp = (ch.type() == "FileItem" and (name.endsWith(".stp") or name.endsWith(".step")) );
        bool test_iges = (ch.type() == "FileItem" and (name.endsWith(".iges") or name.endsWith(".igs") or name.endsWith(".IGS") ))  ;
        
        // retrieve or make a .geo file
        QFile* geo = 0;
        if(test_stp or test_iges){
            MP file_geo = mp["_children[0]"];
            quint64 ptr = file_geo[ "_ptr" ];
            PRINT(file_geo.type().toStdString());
            QString name = file_geo[ "_name" ];
            MP data = sc->load_ptr( ptr );
            QString path;
            if( data.ok() and data.type() == "Path") {
                path = (QString) data;
            }
            else {
                add_message( mp, ET_Error, "Unable to find .geo path" );
                return false;
            }
            //qDebug() << "Path : " << path_csv;
            std::string filename(path.toStdString());
            PRINT(filename);
            PRINT(name.toStdString());
            geo = new QFile(filename.c_str());
            
            
            // read the file
            TopoDS_Shape shape;
            
            if(test_stp){
                shape= ImportSTEP( filename.c_str() );
                if ( shape.IsNull() )
                {
                  std::cout << "ImportSTEP() failed" << std::endl;
                  return 1;
                }
            }else{
                shape= ImportIGES( filename.c_str() );
                if ( shape.IsNull() )
                {
                  std::cout << "ImportIGES() failed" << std::endl;
                  return 1;
                }
            }
            
            // get triangles
            Handle(Poly_Triangulation) tria = ShapeToTriangles( shape );
            if ( tria.IsNull() )
            {
              std::cout << "ShapeToTriangles() failed" << std::endl;
              return 1;
            }
            
            // output mesh
            MP output = mp[ "_output[0]" ];
            MP om = output[ "_mesh" ];
            om[ "points" ].clear();
            om[ "_elements" ].clear();
            
            // dump nodes
            const TColgp_Array1OfPnt& nodes = tria->Nodes();
            std::cout << "# " << nodes.Upper() << " nodes: " << std::endl;
            for ( int i = 1; i <= nodes.Upper(); ++i ){
              const gp_Pnt& p = nodes.Value( i );
              //std::cout << i << " \t" << p.X() << " "  << p.Y() << " "  << p.Z() << std::endl;
              
              MP pos = MP::new_lst( "Vec_3" );
              pos << p.X();
              pos << p.Y();
              pos << p.Z();
              
              MP pnt = MP::new_obj( "Point" );
              pnt[ "pos" ] = pos;
              
              om[ "points" ] << pnt;
            }
            //qDebug() << om[ "points" ];
            
            // dump triangles  
            const Poly_Array1OfTriangle& trias = tria->Triangles();
            std::cout << "# " << trias.Upper() << " triangles: " << std::endl;
            Standard_Integer n1,n2,n3;
            TypedArray<int> *tr_con = new TypedArray<int>;
            for ( int i = 1; i <= trias.Upper(); ++i )
            {
              const Poly_Triangle& t = trias.Value( i );
              t.Get( n1,n2,n3 );
              //std::cout << i << " \t" << n1 << " "  << n2 << " "  << n3 << std::endl;
              
              tr_con->_data << (n1-1);
              tr_con->_data << (n2-1);
              tr_con->_data << (n3-1);
              
            }
           
            // triangle
            tr_con->_size.resize( 2 );
            tr_con->_size[ 0 ] = 3;
            tr_con->_size[ 1 ] = tr_con->_data.size() / 3;

            MP triangles = MP::new_obj( "Element_TriangleList" );
            triangles[ "indices" ] = tr_con;
            om[ "_elements" ] << triangles;
            
        }          
    }
    //qDebug() << "GmshItem : ";
    //qDebug() << mp;
    add_message( mp, ET_Info, "Mesher -> OK" );
    qDebug() << "Mesher just finish";
}



