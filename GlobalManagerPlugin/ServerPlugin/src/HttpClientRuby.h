#ifndef HTTPCLIENTRUBY_H
#define HTTPCLIENTRUBY_H

#include <Soca/Com/SodaClient.h>
#include <QtNetwork/QHttp>

// class HttpClientRuby: public QObject  
// {
// Q_OBJECT
// public:
//     HttpClientRuby(){
//         http.setHost("localhost:3000"); // à modifier selon l'IP
//         // slot traitant la réponse du serveur
//         QObject::connect(&http,SIGNAL(readyRead( const QhttpResponseHeader&)), this,SLOT(fin( const QHttpResponseHeader &e)));
//     }
// private slots : 
//         void fin(const QHttpResponseHeader &e ){
//             qDebug() << "fin requette-----------" ;
//         }; // pour lire des données du serveur
// public slots : 
//     void log_tool(QString params){ // connecté à un signal de l'IHM après la saisie
//         //params = urllib.urlencode({'sc_model_id': model_id, 'workspace_member_id': workspace_member_id, 'state': status, 'time': calcul_time_s, 'log_id': log_id})       
//         // content
//         QByteArray content("App='TestItem'&typeApp=1&time=10&proc=2&wmid=2&sc_model_id=200");
//         
//         // header
//         QHttpRequestHeader header("POST", "/log_tools/use_scwal_tool");
//         header.setValue("Host", "localhost:3000");
//         header.setContentType("application/x-www-form-urlencoded"); // important
//         header.setContentLength(content.length());
//         
//         // request
//         http.request(header, content);
//     }
// private : 
//         QHttp http;
// };
// 
// // HttpClientRuby::HttpClientRuby()
// // {
// //         http.setHost("localhost:3000"); // à modifier selon l'IP
// //         // slot traitant la réponse du serveur
// //         QObject::connect(&http,SIGNAL(readyRead( const QhttpResponseHeader&)),
// //         this,SLOT(fin( const QHttpResponseHeader &)));
// // }
// // void HttpClientRuby::log_tool(QString params)
// // {
// //         //params = urllib.urlencode({'sc_model_id': model_id, 'workspace_member_id': workspace_member_id, 'state': status, 'time': calcul_time_s, 'log_id': log_id})       
// //         // content
// //         QByteArray content("App='TestItem'&typeApp=1&time=10&proc=2&wmid=2&sc_model_id=200");
// //         
// //         // header
// //         QHttpRequestHeader header("POST", "/log_tools/use_scwal_tool");
// //         header.setValue("Host", "localhost:3000");
// //         header.setContentType("application/x-www-form-urlencoded"); // important
// //         header.setContentLength(content.length());
// //         
// //         // request
// //         http.request(header, content);
// // }






//#include <QtNetwork/QHttp>
#include <QtCore/QUrl>
 
class Client : public QHttp
{
Q_OBJECT
 
    
private:
    QEventLoop loop; 
    QUrl url;
    int idRequete;
 
public slots:
 
    void recuperationResultat(int id, bool error)
    {
        qDebug() << "error in request" ;
        if ( error ){
            // Il y a eu une erreur pendant la requête
            qDebug() << "error in request" ;
            return;
        }
 
        // Nous vérifions si la requête est celle que nous voulons (dans le cas où plusieurs requêtes sont en cours)
        if ( id == idRequete ){
            // Ici on peut mettre un code pour récupérer les données renvoyées par le serveur dans un QByteArray
            qDebug() << "request id ok : " << idRequete ;
            this->readAll();
        }
        loop.exit();
    }
 
public:
 
    //Client(const QString& urlSite)
    Client()
    {
        url = QUrl("localhost"); // On enregistre l'url du sire
        idRequete = 0;
 
        // Connexion du signal de fin de requête avec notre analyseur de résultat
        connect(this, SIGNAL(requestFinished(int, bool)), this, SLOT(recuperationResultat(int, bool)));
        qDebug() << "finish log_tool-----------" ;
    }
 
    void connexion( )
    {
        this->setHost  ( url.host(), 3000);
            // on détermine si c'est une connexion sécurisée
//                        ( url.scheme().toLower() == "http" ) ? QHttp::ConnectionModeHttps : QHttp::ConnectionModeHttp,
//                          url.port() == -1 ? 0 : url.port() // On détermine le port
//             );
 
        // Prépare une chaîne qui contiendra les éléments pour la connexion
        QString searchString = QString("username=") + QString("toto") + QString("&password=") + QString("tata");
 
        // Ici nous créons l'en-tête pour notre requête
        QHttpRequestHeader postRequest("POST", "/log_tools/use_scwal_tool");
        postRequest.setValue("Host", "localhost:3000");
 
        // Requête avec le passage des identifiants
        
        
        idRequete = this->request(postRequest,searchString.toUtf8());
        qDebug() << "idRequete : " << idRequete;
        loop.exec();
        
        qDebug() << "loop finish log_tool-----------" ;
        
    }
};












#endif // HTTPCLIENTRUBY_H
