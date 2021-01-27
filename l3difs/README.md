# [Support de cours](https://github.com/truillet/ups/blob/master/l3difs/Cours/WebServices.pptx)

# Etape 1 : installer Apache Tomcat & le framework AXIS 
## A télécharger
* Apache [XAMPP](https://www.apachefriends.org/fr/index.html) : téléchargez votre distribution et installez-là sur votre système (par exemple dans "_C:/xampp_").
* Apache [AXIS2](https://axis.apache.org) : téléchargez la distribution [axis 1.7.9](http://www.apache.org/dyn/closer.lua/axis/axis2/java/core/1.7.9/axis2-1.7.9-bin.zip) et désippez le fichier (par exemple dans _C:/axis2-1.7.9_)

## A configurer
* Si ce n'est pas déjà fait, configurez la variable d'environnement __JAVA_HOME__ afin de pointer sur un JRE ou JDK valide
* configurez la variable d'environnement __AXIS2_HOME__ afin de pointer vers le chemin d'installation d'Axis
* ajoutez à la variable __PATH__ le chemin _%AXIS2_HOME/bin%_
* sur Xampp, lancez le serveur Tomcat. Vérifiez que tout fonctionne en ouvrant une page du navigateur avec l'URL http://locahost:8080, allez dans 
* modifiez maintenant le fichier _tomcat_users.xml_ (qui se situe sur "_C:/xampp/tomcat/conf_"

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

# (Optionnel : Un IDE : IntellijIDEA)
__Nota__ : Pour les étudiants, un certain nombre d'outils sont accesibles gratuitement avec le pack [Github for Education](https://education.github.com/pack#offers) dont IntellijIDEA dans sa versino __Ultimate__ (qui permet la gestion des web services)

# Etape 2 : Ecrire un service "basique" 
Une archive Axis2 (extension _.aar_) possède une structure particulière. Nous allons créer un premier service nommé __helloService__. 
```.
├── helloService
    ├─── META-INF
    │ └─── services.xml
    └── l3difs
      └─── helloService.java
```
La classe est une classe "classique" en java
```
package l3difs;

public class helloService {
    helloService() {
    }
    public String message() {
        return("Bonjour, à votre service");
    }
}
```
Enfin, le fichier __services.xml__ expose le service
```
<service name="hello">
    <description>
        This service says hello
    </description>
    <parameter name="ServiceClass">l3difs.helloService</parameter>
    <operation name="message">
        <messageReceiver class="org.apache.axis2.rpc.receivers.RPCMessageReceiver" />
    </operation>
</service>
```
Il suffit maintenant de compiler les sources, créer l'archive Axis2 et la déployer sur le serveur Axis

```
javac l3difs/*.java

# créer l'archive aar
jar cvf helloService.aar *
```
Déplacez le fichier __helloService.aar__ ([archive .aar ici](https://github.com/truillet/ups/blob/master/l3difs/code/helloService.aar) et [fichiers sources là](https://github.com/truillet/ups/blob/master/l3difs/code/helloService.zip)) dans le répertoire _C:/xampp/tomcat/webapps/axis2/WEB-INF/services_ 
Arrêtez/relancer le service tomcat.
Vérifier enfin que votre service est disponible à l'adresse http://localhost:8080/axis2/services/listServices et essayez d'utiliser la méthode _message_ en tapant l'url http://localhost:8080/axis2/services/hello?method=message 
Vous devriez voir apparaître un fichier XML de la forme suivante : 
```
<ns:messageResponse xmlns:ns="http://l3difs">
   <ns:return>Bonjour le monde</ns:return>
</ns:messageResponse>
```

# Etape 3 : écrire un client java pour notre service
Notre client va avoir besoin d'un minimum d'informations qui va lui permettre d'appeler le service. Ces informations peuvent être générées directement par le framework Axis2.
Créez un répertoire _client_ et positionnez-vous dedans. Tapez la commande suivante afin de créer les talons ("stubs") nécessaires à la création de votre client du web service. Vous pouvez regarder le code mais en aucun cas le modifier :) ; en effet, les opérations d'encodage et de décodage des données est __caché__ et vous permet une plus grande souplesse dans la gestion de vos web_services.
```
mkdir client
cd client
wsdl2java -uri http://localhost:8080/axis2/services/hello?wsdl -o .
```
L'arborescence suivante devrait être automatiquement générée
```.
├── src
│    ├─── l3difs
│         ├──  HelloCallbackHandler.java   
│         └─── HelloStub.java         
├── build.xml
```
Nous allons créer notre client dans le package _l3difs/client_ : [helloClient.java](https://github.com/truillet/ups/blob/master/l3difs/code/helloClient.java).
Compilons le code et exécutons-le
```
cd src
javac -cp .;%AXIS2_HOME%/lib/* ./l3difs/*.java
javac -cp .;%AXIS2_HOME%/lib/* ./l3difs/client/*.java
# Exécuter le code 
java -cp .;%AXIS2_HOME%/lib/* l3difs.client.helloClient
```
# Etape 4 : "Up to you" - générez et utilisez votre propre service
## Excercice 1
Vous allez maintenant reproduire toutes ces étapes pour écrire et déployer le web service __Compte__ dont voici les méthodes principales :

```
public class Compte {
	private float Solde;

	// Constructeur
	public Compte() {
		Solde = 0.0;
	}

	public void deposer (float montant) {
		…
	}

	public boolean retirer (float montant) {
		// retourne true si le solde reste positif, false sinon
		…
	}

	public float solde() {
		…
	}
```

Créez finalement un client java qui utilise le service __Compte__. On veut pouvoir effectuer des dépôts, effectuer des retraits et visualiser le solde.

## Exercice 2
L'exercice suivant consiste à simuler un serveur de messagerie électronique. Les quatre principales fonctionnalités sont 1/ de recevoir des messages électroniques de la part d'expéditeurs, 2/ les stocker dans une boîte aux lettres, 3/ les transmettre sur demande à des destinataires et 4/ supprimer les messages lus d'un destinataire.

Développez les deux classes _[Message.java](https://github.com/truillet/ups/blob/master/l3difs/code/Message.java)_ et _[MailServer.java](https://github.com/truillet/ups/blob/master/l3difs/code/MailServer.java)_ du package _l3difs.service.Mail_, déployez le serveur et un client java afin de pouvoir envoyer un email, lire et supprimer les emails reçus.
