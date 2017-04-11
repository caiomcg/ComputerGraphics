package view.Login;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.stage.Stage;
import view.AlertDialog;

import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.ResourceBundle;


public class LoginController implements Initializable {
    @FXML
    private TextField username;
    @FXML
    private PasswordField password;

    @Override
    public void initialize(URL location, ResourceBundle resources) {

    }

    @FXML
    private void onLoginClick(ActionEvent event) {
        if (!isUsernameValid(username.getText())) {
            AlertDialog.create(username.getScene().getWindow(), "MPS - ERROR", "Invalid username").show();
            return;
        }
        if (!isPasswordValid(password.getText())) {
            AlertDialog.create(username.getScene().getWindow(), "MPS - ERROR", "Invalid password").show();
            return;
        }
        try {
            Stage main = (Stage) username.getScene().getWindow();

            Parent root = FXMLLoader.load(getClass().getResource("../Menu/Menu.fxml"));
            Stage stage = new Stage();
            stage.setTitle("MPS - UserErrorHandling");
            stage.setScene(new Scene(root, 600, 400));
            stage.getScene().getStylesheets().add("res/layout.css");
            stage.setResizable(false);

            stage.show();
            main.hide();
        } catch (IOException exception) {
            exception.printStackTrace();
            AlertDialog.create(username.getScene().getWindow(), "MPS - ERROR", "Could not change screen").show();
        }
    }

    private boolean isUsernameValid(String username) {
        return username.length() <= 20 && username.matches("[^0-9]+");
    }

    private boolean isPasswordValid(String password) {
        return password.length() >= 8 && password.length() <= 12 && password.matches(".*[0-9].*[0-9].*");
    }
}
