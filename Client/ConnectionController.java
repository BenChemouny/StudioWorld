package sample;

import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

public class ConnectionController {
    @FXML
    Button btnSave;
    @FXML
    TextField txtIp;
    @FXML
    TextField txtPort;

    @FXML
    public void initialize() {
        txtIp.setText(TCPCon.getInstance().getIp());
        txtPort.setText(Integer.toString(TCPCon.getInstance().getPort()));
        btnSave.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                TCPCon.getInstance().setIp(txtIp.getText());
                try {
                    TCPCon.getInstance().setPort(Integer.parseInt(txtPort.getText()));
                }
                catch (Exception e) {

                }
                Stage stage = (Stage)btnSave.getScene().getWindow();
                stage.close();
            }
        });
    }
}
