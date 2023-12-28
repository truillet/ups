# Une application dirigée à la voix
Nous souhaitons concevoir et réaliser une application **non-visuelle** (en *entrée* et en *sortie* incluant *parole* et éventuellement son -musique, messages enregistrés, etc.) permettant à un utilisateur **d’ajouter, retirer, manipuler des aliments affichés sur un écran afin de composer le contenu d’une assiette "gourmande" de dessert(s)**. (ex : café, thé, sucre, crème brûlée, profiteroles, ...)

<img src="https://github.com/truillet/ups/blob/master/m2ihm/TP/ressources/triangle.png" align="center" width=400>

La disposition physique des desserts fait partie du problème !
Vous coderez votre application dans le **langage que <ins>vous désirez</ins>** :blush:.
**Il devra être possible d’effectuer toutes les actions demandées de manière purement vocale en entrée et en sortie**.

Afin de réaliser notre application multimédia, nous nous servirons prioritairement du **middleware (bus logiciel) [ivy](https://github.com/truillet/ivy/blob/master/README.md)**, support au futur Bureau d’Etudes sur la multimodalité.

**Nota** : Si vous êtes sous Linux ou MacOS, il vous faudra trouver des solutions alternatives pour la reconnaissance et la synthèse vocale (par exemple, utiliser **[MaryTTS](https://github.com/marytts/marytts)** pour la synthèse vocale ou **[STT](http://florianschulz.info/stt)** ou encore **[SpeechRecognition](https://pythonprogramminglanguage.com/speech-recognition)**, librairie python pour la reconnaissance vocale.

# Travail attendu de cette séance (2 heures)
Après avoir <ins>pris en main</ins> les [agents de reconnaissance](https://github.com/truillet/ivy/blob/master/agents/doc_sra5.md) et de [synthèse vocale](https://github.com/truillet/ivy/blob/master/agents/doc_ppilot5.md) fonctionnant avec le [bus logiciel ivy](https://github.com/truillet/ivy), l’objet de cette séance est :

1. de **définir la grammaire de reconnaissance** (commandes vocales ou langage *pseudo-naturel*) qui sera utilisée par votre application, gérer les résultats de la sortie sémantique (i.e. les concepts associés aux paroles prononcées) ainsi que le taux de confiance.
2. de **définir les retours (feedbacks) vocaux à synthétiser** et retours sonores utilisés par votre application.
3. de développer une application d’affichage des plats à l’écran (en java, Processing, python … ou un autre langage).
4. et enfin **développer le contrôleur de dialogue** à **l’aide d’une machine à états** (qui peut être soit séparée, soit incluse dans l’application d’affichage de la forme). Le contrôleur s’appuiera sur un échange de messages ivy avec au moins les modules de reconnaissance et de synthèse vocale.

A la fin de la séance, vous aurez produit un **prototype haute-fidélité testable** du système demandé. 


**Nota** : pour ce faire, vous pourrez utiliser quelques agents ivy déjà codés (présentés en annexe)

