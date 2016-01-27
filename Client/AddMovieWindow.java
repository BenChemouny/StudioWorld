package sample;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Modality;
import javafx.stage.Stage;

import java.io.IOException;

/**
 * Created by nadav on 1/19/16.
 */
public class AddMovieWindow {
    public void show() {
        Stage stage = new Stage();
        Parent root = null;
        try
        {
            root = FXMLLoader.load(getClass().getResource("AddMovieWindow.fxml"));
        }
        catch (IOException e)
        {

        }
        stage.setTitle("Add Movie");
        Scene scene = new Scene(root,500,500);
        stage.setScene(scene);
        stage.initModality(Modality.APPLICATION_MODAL);
        stage.showAndWait();
        //return new TCPCon(txtIp,Integer.parseInt(txtPort));
        //return null;
    }
}
