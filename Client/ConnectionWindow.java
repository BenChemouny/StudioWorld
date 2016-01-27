package sample;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.stage.Modality;
import javafx.stage.Stage;

import java.io.IOException;

public class ConnectionWindow {
    public void show() {
        Stage stage = new Stage();
        Parent root = null;
        try
        {
            root = FXMLLoader.load(getClass().getResource("SetConnection.fxml"));
        }
        catch (IOException e)
        {

        }
        stage.setTitle("Connect");
        Scene scene = new Scene(root,300,300);
        stage.setScene(scene);
        stage.initModality(Modality.APPLICATION_MODAL);
        stage.showAndWait();
        //return new TCPCon(txtIp,Integer.parseInt(txtPort));
        //return null;
    }
}
