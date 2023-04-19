import java.net.*;
import java.util.Scanner;
import java.io.*;

public class UDPClient {
	public static void main(String args[]) {
		Scanner scn = new Scanner(System.in);

		System.out.print("Host: ");
		String host = scn.nextLine();

		System.out.print("Message: ");
		byte[] message = scn.nextLine().getBytes();

		// args give message contents and destination hostname
		try {
			DatagramSocket aSocket = new DatagramSocket(); // create socket
			InetAddress aHost = InetAddress.getByName(host); // DNS lookup
			int serverPort = 6789;
			DatagramPacket request = new DatagramPacket(message, message.length, aHost, serverPort);
			aSocket.send(request); // send message
			byte[] buffer = new byte[1000];
			DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
			aSocket.receive(reply); // wait for reply
			System.out.println("Reply: " + new String(reply.getData()));
			aSocket.close();
		} catch (SocketException e) {
			System.out.println("Socket: " + e.getMessage()); // socket creation failed
		} catch (IOException e) {
			System.out.println("IO: " + e.getMessage()); // can be caused by send
		}
		scn.close();
	}
}