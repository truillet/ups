package l3difs.service.mail;

import java.util.*;

public class MailServer{
    Vector messages;
	
    public MailServer(){
	//initialisation des variables
    }

   public String sendMessage(String fromp, String top, String messagep){
       // créer un  nouveau message 
       // ajouter LE dans la listes des messages du serveur
       return ("Message sent successfully");
    }

    public Message[] getMessages (String to){
	// recupérer, dans un tableau, les messages dont le destinataire est "to", il faut les marquer comme étant "lu"
	// envoyer le résultat au client
    }

    public String removeMessages (String to){
	int oldMessageNumber=0;
	// supprimer tous les messages marqué comme étant "lu" et dont le destinataire est "to"
	if(oldMessageNumber==0)
	   return ("No old messages");
	else
	   return ("Old messages removed successfully");
    }

}