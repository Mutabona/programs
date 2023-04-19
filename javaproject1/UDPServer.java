import java.net.*;
import java.io.*;
import java.util.Scanner;
public class UDPServer{
    public static void main(String args[]) { 
        Scanner scn = new Scanner(System.in);
        DatagramSocket aSocket = null;
        try{
            aSocket = new DatagramSocket(6789); // create socket at agreed port
            byte[] buffer = new byte[1000];
            while(true){
                 DatagramPacket request = new DatagramPacket(buffer, buffer.length);
                 aSocket.receive(request);
                 System.out.print("Message: " + new String(request.getData()) + '\n');
                 System.out.print("Answer: ");
                 byte[] message = scn.nextLine().getBytes();
                 DatagramPacket reply = new DatagramPacket(message, message.length, request.getAddress(), request.getPort());
                 aSocket.send(reply);
            }
        } catch (SocketException e){System.out.println("Socket: " + e.getMessage()); // socket creation failed
        } catch (IOException e) {System.out.println("IO: " + e.getMessage());
        } finally {if(aSocket != null) aSocket.close();}
    }
}