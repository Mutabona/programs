import java.net.*;
import java.io.*;
import java.util.Scanner;

public class Receiver{
    public static void main(String args[]) { 
        Scanner scn = new Scanner(System.in);
        DatagramSocket aSocket = null;
        try{
            aSocket = new DatagramSocket(6780); // create socket at agreed port
            
            while(true){
                 byte[] buffer = new byte[1000];
                 DatagramPacket request = new DatagramPacket(buffer, buffer.length);
                 aSocket.receive(request);
                 System.out.print("Message: " + new String(request.getData()) + '\n');
                 buffer = null;
            }
        } catch (SocketException e){System.out.println("Socket: " + e.getMessage()); // socket creation failed
        } catch (IOException e) {System.out.println("IO: " + e.getMessage());
        } finally {if(aSocket != null) aSocket.close();}
    }
}