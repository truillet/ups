package l3difs.client;

import java.rmi.RemoteException;
import org.apache.axis2.AxisFault;
import l3difs.HelloStub; // We will use Message and MessageResponse inner classes

public class helloClient{
	public static void main(String[] args){
        try {
			// Create the Stub object
            HelloStub serviceStub = new HelloStub();

            // Create the Request object. The request class is autogenerated
            // as an inner class of the Stub class.
            HelloStub.Message messageReq = new HelloStub.Message();

            // Invoke method and get response as a response object
            HelloStub.MessageResponse response = serviceStub.message(messageReq);

            // Response object's get_return() returns the return of the remote 
            // method
            String message = response.get_return();
            System.out.println("Message from the remote service: " + message);
        }
        catch (AxisFault e) {
			e.printStackTrace();
        }
        catch (RemoteException e) {
            e.printStackTrace();
        }
    }	
	
}