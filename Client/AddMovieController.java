package sample;

import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

import java.util.stream.Stream;

/**
 * Created by nadav on 1/19/16.
 */
public class AddMovieController {
    @FXML
    Button btn_AddMovie;
    @FXML
    TextField txt_mid;
    @FXML
    TextField txt_mname;
    @FXML
    TextField txt_mlength;
    @FXML
    TextArea txt_minfo;
    @FXML
    TextArea txt_mgenres;
    @FXML
    TextField txt_myear;
    @FXML
    Slider sld_mrating;
    String result;
    public void initialize()
    {
        btn_AddMovie.setOnMouseClicked(new EventHandler<MouseEvent>()
        {
            @Override
            public void handle(MouseEvent event) {
                try {
                    result = TCPCon.getInstance().sendAndRecieve("1 "+txt_mid.getText()+" "+txt_mname.getText()+" "+txt_mlength.getText()+" "+txt_myear.getText()+" "+ String.valueOf(sld_mrating.getValue()).substring(0,1)+" "+txt_minfo.getText());
                }
                catch (Exception e) {

                }
                Alert alert = new Alert(Alert.AlertType.INFORMATION);
                alert.setTitle("Result");
                alert.setHeaderText(result);
                alert.showAndWait();
                Stage stage = (Stage)txt_minfo.getScene().getWindow();
                stage.close();
            }
        });
    }
}
