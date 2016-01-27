package sample;

import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.MenuItem;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class MainController {
    @FXML
    ImageView imgLogo;
    @FXML
    MenuItem btnAddMovie;
    @FXML
    MenuItem btnAllMovies;
    @FXML
    ListView lstShow;

    @FXML
    void initialize() {
        imgLogo.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                ConnectionWindow window = new ConnectionWindow();
                window.show();

                try {
                    TCPCon.getInstance().Connect();
                    Alert alert = new Alert(Alert.AlertType.INFORMATION);
                    alert.setTitle("Information");
                    alert.setHeaderText("Connection Succeed");
                    alert.showAndWait();

                    Stage stage = (Stage)imgLogo.getScene().getWindow();
                    stage.setTitle("Cinema - Connected");
                }
                catch (IOException e) {
                    Alert alert = new Alert(Alert.AlertType.INFORMATION);
                    alert.setTitle("Information");
                    alert.setHeaderText("Connection Failed");
                    alert.showAndWait();

                    Stage stage = (Stage)imgLogo.getScene().getWindow();
                    stage.setTitle("Cinema - Disconnected");
                }

            }
        });
        btnAddMovie.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                AddMovieWindow window = new AddMovieWindow();
                window.show();
            }
        });
        btnAllMovies.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                String ret;
                List<String> lst = new ArrayList<String>();
                try {
                    ret = TCPCon.getInstance().sendAndRecieve("13");
                    lst.add(ret);
                }
                catch (Exception e)
                {

                }
                lstShow.setItems(FXCollections.observableList(lst));
            }
        });
    }
}