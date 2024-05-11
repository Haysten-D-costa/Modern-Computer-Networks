// A Java program for a Client
import java.net.*;
import java.io.*;

public class Client
{
// initialize socket and input output streams
private Socket socket = null;
private DataInputStream input = null;
private DataOutputStream out = null;

// constructor to put ip address and port
public Client(String address, int port)
{
// establish a connection
try
{
socket = new Socket(address, port);
System.out.println(&quot;Connected&quot;);

// takes input from terminal
input = new DataInputStream(System.in);

// sends output to the socket
out = new DataOutputStream(socket.getOutputStream());
}
catch(UnknownHostException u)

AGNEL INSTITUTE OF TECHNOLOGY AND

DESIGN

AGNEL TECHNICAL EDUCATIONAL COMPLEX
ASSAGAO, BARDEZ-GOA. 403 507
DEPARTMENT OF COMPUTER ENGINEERING
{
System.out.println(u);
}
catch(IOException i)
{
System.out.println(i);
}

// string to read message from input
String line = &quot;&quot;;

// keep reading until &quot;Over&quot; is input
while (!line.equals(&quot;Over&quot;))
{
try
{
line = input.readLine();
out.writeUTF(line);
}
catch(IOException i)
{
System.out.println(i);
}
}

// close the connection
try
{
input.close();
out.close();
socket.close();
}
catch(IOException i)
{
System.out.println(i);
}
}

public static void main(String args[])
{
Client client = new Client(&quot;192.168.3.90&quot;, 9999);
}
}