# installer Apache Tomcat & le framework AXIS 

## A télécharger
* Apache [XAMPP](https://www.apachefriends.org/fr/index.html) : téléchargez votre distribution et installez-là sur votre système (par exemple dans "C:/Xampp").
* Apache [AXIS2](https://axis.apache.org) : téléchargez la distribtion [axis 1.7.9](http://www.apache.org/dyn/closer.lua/axis/axis2/java/core/1.7.9/axis2-1.7.9-bin.zip) et désippez le fichier.

## A faire
* Si ce n'est pas déjà fait, configurer la variable d'environnement JAVA_HOME
* sur Xampp, lancez le serveur Tomcat. Vérifiez que tout fonctionne en ouvrant une page du navigateur avec l'URL http://locahost:8080
* modifiez maintenant le fichier tomcat_users.xml (qui se situe sur "C:/Xampp/tomcat/conf"
Ajoutez les lignes suivantes :

## A vérifier


http://localhost:8080/axis2/
http://localhost:8080/axis2/services/ListServices
http://localhost:8080/axis2/Version?wsdl
http://localhost:8080/axis2/Version?method=getVersion


Validate 
Services
