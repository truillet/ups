package l3difs.service.mail;

public class Message implements java.io.Serializable {
    private String message="";
    private String from;
    private String to;
    private boolean isNew;
    
    public Message(String fromp, String top, String messagep){
	// initialisation des variables	
    }
    
    public String getTo(){
	return to;
    }
    public String getFrom(){
	return from;
    }
    public String getMessage(){
	return message;
    }
    public void setTo(String top){
	to=top;
    }
    public void setFrom(String fromp){
	from=fromp;
    }
    //ici vous pouvez ajouter les methodes que vous jugez nécessaires
}