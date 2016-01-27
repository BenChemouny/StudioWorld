package sample;

import java.io.*;
import java.net.Socket;

/**
 * Created by nadav on 1/19/16.
 */
public class TCPCon {
    private String ip;
    private int port;
    private Socket clientSock;
    private static TCPCon ourInstance = new TCPCon();

    public static TCPCon getInstance() {
        return ourInstance;
    }

    private TCPCon() {
        ip = "127.0.0.1";
        port = 55555;
    }
    public void setIp(String mip) {
        ip = mip;
    }
    public void setPort(int mport) {
        port = mport;
    }
    public String getIp() {
        return ip;
    }
    public int getPort() {
        return port;
    }
    public void Connect() throws IOException {
        clientSock = new Socket(ip,port);
    }
    public String sendAndRecieve(String msg) throws IOException {
        PrintWriter out = new PrintWriter(clientSock.getOutputStream());
        BufferedReader in = new BufferedReader(new InputStreamReader(clientSock.getInputStream()));
        out.print(msg);
        out.flush();
        String s = in.readLine();
        return s;
    }
    public String getRecieve() throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(clientSock.getInputStream()));
        String s = in.readLine();
        return s;
    }
    public void Disconnect() throws IOException {
        clientSock.close();
    }
}
