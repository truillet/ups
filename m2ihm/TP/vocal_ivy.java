// vocal_ivy.java
// Auteur : Philippe truillet
// Date : 18/01/2021

import fr.dgac.ivy.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class vocal_ivy extends JFrame {
	Ivy bus;
	JLabel target=new JLabel("Passerelle ivy");
		
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
			bus.bindMsg("^sra5 Text=(.*) Confidence=.*", new IvyMessageListener() {// abonnement 
				public void receive(IvyClient client,String[] args) {
					// on renvoie vers la synthese vocale
					try {
						bus.sendMsg("ppilot5 Say=Vous avez dit " + args[0]);
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
		new vocal_ivy(arg[0]); // l'adresse doit etre passee en parametre
	}
}
