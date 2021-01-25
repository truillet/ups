# installer Apache Tomcat & le framework AXIS 
## A télécharger
* Apache [XAMPP](https://www.apachefriends.org/fr/index.html) : téléchargez votre distribution et installez-là sur votre système (par exemple dans "C:/xampp").
* Apache [AXIS2](https://axis.apache.org) : téléchargez la distribtion [axis 1.7.9](http://www.apache.org/dyn/closer.lua/axis/axis2/java/core/1.7.9/axis2-1.7.9-bin.zip) et désippez le fichier.

## A configurer
* Si ce n'est pas déjà fait, configurer la variable d'environnement JAVA_HOME afin de pointer sur un JRE ou JDK valide
* sur Xampp, lancez le serveur Tomcat. Vérifiez que tout fonctionne en ouvrant une page du navigateur avec l'URL http://locahost:8080, allez dans 
* modifiez maintenant le fichier tomcat_users.xml (qui se situe sur "C:/xampp/tomcat/conf"
Ajoutez les lignes suivantes :
```<tomcat-users ...>
  <role rolename="admin-gui"/>
  <role rolename="manager-gui"/>
  <user username="tomcat" password="<votre_mot_de_passe>" roles="admin-gui, manager-gui"/>
</tomcat-users>
```
* Stoppez/relancez le service tomcat
* Il faut maintenant déployer Axis2. Su la page http://locahost:8080, appuyez sur le bouton __Manager App__, renseignez le login/password défini plus haut et déployez le ficher _axis2.war_. 

## A vérifier
Une fois ces opérations effectuées, allez à la page http://localhost:8080/axis2/. Suivez le lien _Validate_ afin de vérifier que votre installation s'est bien déroulée.

Suivez maintenant le lien _Services_ pour lister les [services installés](http://localhost:8080/axis2/services/listServices). Normalement, le service __Version__ est installé.
Vérifier la définition [WSDL](http://localhost:8080/axis2/Version?wsdl) puis appelez la méthode [getVersion](http://localhost:8080/axis2/Version?method=getVersion)

# IntellijIDEA et le plugin Axis
__Nota__ : Pour les étudiants, un certain nombre d'outils sont accesibles gratuitement avec le pack [Github for Education](https://education.github.com/pack#offers)

## A télécharger
* _(Téléchargez [IntellijIDEA](https://www.jetbrains.com/idea/download) si nécessaire)_ (la version Ultimate est nécessaire)
* Téléchargez le plugin [Axis2 pour IntellijIDEA](https://axis.apache.org/axis2/java/core/download.html). Désippez le fichier et placez le dans le dossier _<dossier_IntellijIDEA>/plugins_
