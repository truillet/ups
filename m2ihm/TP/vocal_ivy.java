// vocal_ivy.java
// Auteur : Philippe truillet
// Date : 14/01/2025

import fr.dgac.ivy.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class vocal_ivy extends JFrame {
	Ivy bus;
	JLabel target=new JLabel("Passerelle ivy/dessert vocal");
		
	vocal_ivy(String adresse) { // Constructeur
		super("Passerelle ivy ");
		getContentPane().add(target);
		bus=new Ivy("vocal_ivy","",null);
		try
		{
			bus.start(adresse); // lancement du bus
		}
		catch(IvyException ie){
			System.out.println("Erreur "+ ie);
		}

		try {
			// On va récupérer le résultat de la reconaissance vocale en mode "CONCEPTS" (et non TEXTE) --> sra5 -p on
			bus.bindMsg("^sra5 Parsed=(.*)=(.*) Confidence=(.*) NP=.*", new IvyMessageListener(){
				// dans args[0] --> boisson ou solide
				// dans args[1] --> la boisson (THE, CAFE, ...) ou le solide considéré (TARTE, CUPCAKE, GLACE, ...)
				// dans args[2] --> le taux de confiance entre 0.0 et 1.0
				
				public void receive(IvyClient client,String[] args){
				// A faire : traiter suivant le taux de confiance ;) 
				// attention : on reçoit des 0,xx et on ne peut traiter que des 0.xx
				if (Float.parseFloat(args[2].replace(",",".")) > 0.75) { // Taux de reco à 75%
				  System.out.println("Ajout de " + args[2] + " dans la liste");
				}        
				else { // reco trop faible
				  // feedback vocal
				  try  {
					bus.sendMsg("ppilot5 Say=Je n'ai pas bien compris, veuillez répéter 'il vou plaît");
				  }
				  catch (IvyException ie) {}       
				}
			   }
			  });

			// Si la parole n'est pas reconnue, on a reconnu qu'on n'a rien reconnu d'où un feedback 
			bus.bindMsg("^sra5 Event=SpeechRejected", new IvyMessageListener() {// abonnement 
				public void receive(IvyClient client,String[] args) {
					// on renvoie vers la synthese vocale
					try {
						bus.sendMsg("ppilot5 Say=J'ai été distrait, je ne vous ai pas compris");
					}
					catch (IvyException ie) {// Exception levee
						System.out.println("can't send my message !");
					}	
				}
			});
		}
		catch (IvyException ie) {// Exception levee
			System.out.println("can't bind my message !");
		}
		pack();
		setVisible(true);
	}



	public static void main(String[] arg) {
		//new vocal_ivy(arg[0]); // l'adresse doit etre passee en parametre
		new vocal_ivy("127.255.255.255:2010");
	}
}
